/**
Scrivere un programma che calcoli la seguente espressione c=a+b, dove a è il prodotto tra due valori interi richiesti da input dal processo figlio
mentre b, calcolato dal processo padre è (10-3)
Il programma deve visualizzare quando l'esecuzione è ad opera del padre e quando è ad opera del figlio.
*/

//ALUNNO: Ruggieri Angelo
//CLASSE: 4°Bi
//DATA: 06/02/2015

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
	//zona dichiarativa
	pid_t pid;
	int primo=0,secondo=0,a=0,b,c=0,app=0,retval;
	//termine zona dichiarativa
	
	pid=fork(); // eseguo il comando FORK per la creazione del figlio
	if (pid==0) // verifica presenza del figlio
   		   		   {
   		   		   	 //set di istruzioni del figlio
   		   		   	 printf("FIGLIO: Sono il figlio, ho pid %d e mio padre ha pid %d\n",getpid(),getppid()); //presento il figlio con pid e ppid
   		   		   	 printf("FIGLIO: Inserire primo valore: "); //chiedo il primo valore in input
   		   		   	 scanf("%d",&primo); //ricezione del primo valore
   		   		   	 printf("FIGLIO:Inserire secondo valore: "); //chiedo il secondo valore in input
   		   		   	 scanf("%d",&secondo); //ricezione del secondo valore
   		   		   	 a=primo*secondo; //eseguo il prodotto
   		   		   	 printf("FIGLIO: Termino la mia esecuzione e passo a mio padre il valore: %d\n",a); // stampo il prodotto
   		   		   	 exit(a); //restituisco al padre il prodotto
   		   		   	 
   		   		   }
   		   		   else 
   		   		   {
   		   		   	   if(pid==-1) //test
   		   		   	   {
   		   		   	   	printf("Errore nella creazione della FORK\n"); //stampa a video l'errore generato dalla FORK()
   		   		   	   }
   		   		   	   else
   		   		   	   {
   		   		   	   	// set di istruzioni del padre
   		   		   	   	printf("PADRE: Sono il processo padre ho pid %d\n",getpid()); //verifico che sia realmente il processo padre mostrando il suo pid
   		   		   	   	waitpid(pid,&retval,0); //attendo il processo figlio1
   		   		   	   	app=WEXITSTATUS(retval); //ricevo il valore nella variabile app
   		   		   	   	printf("PADRE: Ricevo da mio figlio il valore: %d\n",app); //stampo il valore ricevuto
   		   		   	   	b=(10-3); //inizializzo il valore di b
   		   		   	   	printf("PADRE: Il valore da me generato e' %d\n",b); //stampo il valore di b
   		   		   	   	c=app+b; //inserisco la somma in c
   		   		   	   	printf("PADRE: Il valore della espressione e': %d\n",c); //stampo a video il valore di c
   		   		   	   	printf("Creato da Angelo Ruggieri, 4Bi 06/02/2015");
   		   		   	   	exit(0); //non richiesto
   		   		   	   }
   		   		   }
return 0;
}
