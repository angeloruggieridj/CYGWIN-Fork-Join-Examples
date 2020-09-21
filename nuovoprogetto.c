#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t miopid,pid;
	int i;
	int retval;
	
	int numprocessi;
	printf("Inserire numero di processi da creare: ");
	scanf("%d",&numprocessi);
	printf("ECCO IL NUMERO DI PROCESSI DA CREARE: %d",numprocessi);
	
	for(i=0;i<numprocessi;i++)
	{
		pid=fork();
		if(pid==0)
		{
			printf("Sono il processo figlio %d \n",i);
			retval=0;
 			sleep(2); //pausa di 10 secondi
 			exit(1);
		}
	}
	
	for(i=0;i<numprocessi;i++)
	{
		printf("Sono il processo padre con PID= %d\n",getpid());
		printf(" Il mio PPID e' %d\n",getppid());
 		pid=wait(&retval); // il padre rimane in attesa del figlio
 		printf("Il valore ritornato da %d",pid);
 		printf(" E' %d\n",WEXITSTATUS(retval));
 		if(WEXITSTATUS(retval)==i)
 	{
 		printf("Il processo figlio %d e' morto\n\n",i);
 	}
	}
}
