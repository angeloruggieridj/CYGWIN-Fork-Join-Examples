#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main( )
{ 
 pid_t pid1,pid2,pid4,pid3,pid;
 pid1=fork();
 int retval;
 
 if(pid1==0) {
 				printf("Sono il processo figlio 1. Ho PID= %d",getpid());
 				printf("Mio padre ha PID= %d\n",getppid());
 				retval=0;
 				sleep(2); //pausa di 10 secondi
 				exit(1);
 			}
 else 
 {
 	pid2=fork();
 	if (pid2==0) {
 					printf("Sono il processo figlio 2. Ho PID= %d",getpid());
 					printf("Mio padre ha PID= %d\n",getppid());
 					retval=0;
 					sleep(2);
 					exit(2);
 					}
 	
	 else
	 {
	 	pid3=fork();
	 	if (pid3==0)
	 				{
	 				printf("Sono il processo figlio 3. Ho PID= %d",getpid());
	 				printf("Mio padre ha PID= %d\n",getppid());
 					retval=0;
 					sleep(2);
 					exit(3);
	 				}
	 	else
	 		pid4=fork();
	 		if(pid4==0)
	 					{
	 						printf("Sono il processo figlio 4. Ho PID= %d",getpid());
	 						printf("Mio padre ha PID= %d\n",getppid());
 						retval=0;
 						sleep(2);
 						exit(4);
	 					}
	 }
	 
	 
	//codice per quanto riguarda la fine del processo 1 
	printf("Sono il processo padre con PID= %d",getpid());
	printf(" Il mio PPID e' %d\n",getppid());
 	pid=wait(&retval); // il padre rimane in attesa del figlio
 	printf("Il valore ritornato da %d",pid);
 	printf(" E' %d\n",WEXITSTATUS(retval));
 	if(WEXITSTATUS(retval)==1)
 	{
 		printf("Il processo figlio1 e' morto\n\n");
 	}
 	
 		//codice per quanto riguarda la fine del processo 2 
	printf("Sono il processo padre con PID= %d\n",getpid());
	printf(" Il mio PPID e' %d\n",getppid());
 	pid=wait(&retval); // il padre rimane in attesa del figlio
 	printf("Il valore ritornato da %d",pid);
 	printf(" E' %d\n",WEXITSTATUS(retval));
 	if(WEXITSTATUS(retval)==2)
 	{
 		printf("Il processo figlio2 e' morto\n\n");
 	}
 	
 		//codice per quanto riguarda la fine del processo 3 
	printf("Sono il processo padre con PID= %d\n",getpid());
	printf(" Il mio PPID e' %d\n",getppid());
 	pid=wait(&retval); // il padre rimane in attesa del figlio
 	printf("Il valore ritornato da %d",pid);
 	printf(" E' %d\n",WEXITSTATUS(retval));
 	if(WEXITSTATUS(retval)==3)
 	{
 		printf("Il processo figlio3 e' morto\n\n");
 	}
 	
 		//codice per quanto riguarda la fine del processo 4 
	printf("Sono il processo padre con PID= %d\n",getpid());
	printf(" Il mio PPID e' %d\n",getppid());
 	pid=wait(&retval); // il padre rimane in attesa del figlio
 	printf("Il valore ritornato da %d",pid);
 	printf(" E' %d\n",WEXITSTATUS(retval));
 	if(WEXITSTATUS(retval)==4)
 	{
 		printf("Il processo figlio4 e' morto\n\n");
 	}
 	
 	
 	
 	exit(0);
 }

}

    
