/*
Scrivere un programma che genera 3 figli ed esegua le seguenti richieste:
1. Uno dei tre figli calcola la differenza di due numeri dati da input.
2. Il padre stampi a video la differenza ricevuta dal figlio
3. Il padre stampi a video il valore di uscita (exit()) del figlio 2 e 3
*/
  
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int retv;
	int differenza,figlio2,figlio3,a,b,c;
	
	pid=fork();
	if(pid==0)
				{
					//set di istruzioni del figlio 1
					printf("Inserire primo valore: ");
					scanf("%d",&a);
					printf("Inserire secondo valore(necessariamente minore di %d): ",a);
					scanf("%d",&b);
					c=a-b; //calcolo la differenza
					printf("FIGLIO: Ecco la differenza %d\n",c);
					exit(c);
				}
				
				else
				{
					//set di istruzioni del padre
					wait(&retv);
					differenza=WEXITSTATUS(retv);
					printf("PADRE: Ricevo da FIGLIO 1 la differenza: %d\n",differenza);
					//creo il figlio 2
					pid=fork();
					if(pid==0)
								{
									//set di istruzioni figlio 2
									printf("FIGLIO 2:Sono in esecuzione. Adesso muoio e restituisco 1 a mio padre\n");
									exit(1);
								}
								else
								{
									//set di istruzioni del padre
									wait(&retv);
									figlio2=WEXITSTATUS(retv);
									printf("PADRE: Ricevo da FIGLIO 2 il valore %d\n",figlio2);
									
									//creo il figlio 3
									pid=fork();
									if(pid==0)
									{
										//set di istruzioni figlio 3
										printf("FIGLIO 3:Sono in esecuzione. Adesso muoio e restituisco 10 a mio padre\n");
										exit(10);
									}
									else
									{
										//set di istruzioni del padre
										wait(&retv);
										figlio3=WEXITSTATUS(retv);
										printf("PADRE: Ricevo da FIGLIO 3 il valore %d\n",figlio3);
									}
										
								}
				}
}
