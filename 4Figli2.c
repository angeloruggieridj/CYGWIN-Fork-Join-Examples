/*
Gestire la creazione di un certo numero di processi. Gestire il valore della wexitstatus. 
I figli vanno in sleep
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
	int k=1;
	int numProcessi;
	int ex[10],retv, time,i;
	
	printf("Quanti processi vuoi far nascere? max 10 ");
	scanf("%d",&numProcessi);
	
	printf("Quanto tempo deve attendere ogni processo prima di morire? ");
	scanf( "%d",&time);
	
	for(i=0; i<numProcessi; i++){
									  pid = fork();
									  if(pid==0){
									  				k=k+i;
													  									  
									  				printf("Sono il %d processo figlio e ho pid: %d \n", i+1, getpid());
									  				sleep(time);
									  				exit(k);
									  			}
									  	else{
									  			wait(&retv);
									  			ex[i] = WEXITSTATUS(retv);
									  			
									  	    }
	                            }
	for(i=0; i<numProcessi; i++){
									  
									  printf("Sono il processo %d e sto per morire. Valore di exitstatus: %d \n", i+1, ex[i]);
									  //exit(i);
								}
}
