#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int main () 
{
	pid_t id,id2;
	id=fork();
	int pippo=0;
	if (id==0)
				{
					printf("FIGLIO1: Sono il processo figlio\n");
					//sleep(6);
					while (pippo==1)
					{
					}
					printf("FIGLIO1: Ora muoio\n");
					exit(1); //uccide il figlio1
				}
	else {
			printf("PADRE: Sono il processo padre\n");
			sleep(5);
			id2=fork();
			pippo=1;
				if(id2==0)
				{
					printf("FIGLIO2: Sono il processo figlio\n");
				}
				else
				{
					printf("PADRE: Sono rimasto io e mio figlio2\n");
				}
		 }
		
}
  
