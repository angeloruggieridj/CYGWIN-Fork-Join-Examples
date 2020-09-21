#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>


int main()
{
	//zona dichiarativa
	pid_t pid;
	int a=0,b,c=0,retval;
	int i=0;
	char v[5];
	char ap;
	char primo,app;
	//termine zona dichiarativa
	
	pid=fork(); // eseguo il comando FORK per la creazione del figlio
	if (pid==0) // verifica presenza del figlio
   		   		   {
   		   		   	 //set di istruzioni del figlio PRODUTTORE

   		   		   	 printf("FIGLIO: Sono il figlio PRODUTTORE, ho pid %d e mio padre ha pid %d\n",getpid(),getppid()); //presento il figlio con pid e ppid
   		   		   	 	
								  
								  printf("FIGLIO: Inserire vocale: "); //chiedo il primo valore in input
   		   		   	 	scanf("%c",&primo); //ricezione del primo valore   		   		   	 	
   		   		   	 exit(primo); //restituisco al padre il prodotto
   		   	
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
									printf("PADRE: Ricevo da mio figlio il valore: %c\n",app); //stampo il valore ricevuto
									v[0]=app;
									pid=fork();
									if(pid==0)
									{
										printf("FIGLIO: Sono il figlio PRODUTTORE, ho pid %d e mio padre ha pid %d\n",getpid(),getppid()); //presento il figlio con pid e ppid
								  		printf("FIGLIO: Inserire vocale: "); //chiedo il primo valore in input
   		   		   	 					scanf("%c",&primo); //ricezione del primo valore   		   		   	 	
   		   		   	 					exit(primo); //restituisco al padre il prodotto	
									}
									else
									{
										printf("PADRE: Sono il processo padre ho pid %d\n",getpid()); //verifico che sia realmente il processo padre mostrando il suo pid
										waitpid(pid,&retval,0); //attendo il processo figlio1
   		   		   	   					app=WEXITSTATUS(retval); //ricevo il valore nella variabile app
										printf("PADRE: Ricevo da mio figlio il valore: %c\n",app); //stampo il valore ricevuto
										v[1]=app;
									}
									pid=fork();
									if(pid==0)
									{
										printf("FIGLIO: Sono il figlio PRODUTTORE, ho pid %d e mio padre ha pid %d\n",getpid(),getppid()); //presento il figlio con pid e ppid
								  		printf("FIGLIO: Inserire vocale: "); //chiedo il primo valore in input
   		   		   	 					scanf("%c",&primo); //ricezione del primo valore   		   		   	 	
   		   		   	 					exit(primo); //restituisco al padre il prodotto	
									}
									else
									{
										printf("PADRE: Sono il processo padre ho pid %d\n",getpid()); //verifico che sia realmente il processo padre mostrando il suo pid
										waitpid(pid,&retval,0); //attendo il processo figlio1
   		   		   	   					app=WEXITSTATUS(retval); //ricevo il valore nella variabile app
										printf("PADRE: Ricevo da mio figlio il valore: %c\n",app); //stampo il valore ricevuto
										v[2]=app;
									}
									pid=fork();
									if(pid==0)
									{
										printf("FIGLIO: Sono il figlio PRODUTTORE, ho pid %d e mio padre ha pid %d\n",getpid(),getppid()); //presento il figlio con pid e ppid
								  		printf("FIGLIO: Inserire vocale: "); //chiedo il primo valore in input
   		   		   	 					scanf("%c",&primo); //ricezione del primo valore   		   		   	 	
   		   		   	 					exit(primo); //restituisco al padre il prodotto	
									}
									else
									{
										printf("PADRE: Sono il processo padre ho pid %d\n",getpid()); //verifico che sia realmente il processo padre mostrando il suo pid
										waitpid(pid,&retval,0); //attendo il processo figlio1
   		   		   	   					app=WEXITSTATUS(retval); //ricevo il valore nella variabile app
										printf("PADRE: Ricevo da mio figlio il valore: %c\n",app); //stampo il valore ricevuto
										v[3]=app;
									}
									pid=fork();
									if(pid==0)
									{
										printf("FIGLIO: Sono il figlio PRODUTTORE, ho pid %d e mio padre ha pid %d\n",getpid(),getppid()); //presento il figlio con pid e ppid
								  		printf("FIGLIO: Inserire vocale: "); //chiedo il primo valore in input
   		   		   	 					scanf("%c",&primo); //ricezione del primo valore   		   		   	 	
   		   		   	 					exit(primo); //restituisco al padre il prodotto	
									}
									else
									{
										printf("PADRE: Sono il processo padre ho pid %d\n",getpid()); //verifico che sia realmente il processo padre mostrando il suo pid
										waitpid(pid,&retval,0); //attendo il processo figlio1
   		   		   	   					app=WEXITSTATUS(retval); //ricevo il valore nella variabile app
										printf("PADRE: Ricevo da mio figlio il valore: %c\n",app); //stampo il valore ricevuto
										v[4]=app;
									}
									for(i=0;i<5;i++)
									{
										printf("VALORE SALVATO: %c\n",v[i]);
									}
   		   		   	   	printf("Creato da Angelo Ruggieri, 4Bi 06/02/2015");
   		   		   	   	exit(0); //non richiesto
   		   		   	   }
   		   		   }
return 0;
}
