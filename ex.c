#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int main () {
  pid_t child_pid;
  /*   */
  child_pid = fork (); //creo il processo figlio
  
  if (child_pid > 0) // quindi se è il padre
  						{
							printf("Padre: Sono il processo padre e vado in attesa per 60 secondi\n");
    						sleep(5); //  attende 60 secondi
    						exit(1);
    						printf("Padre: Mio figlio e' morto'\n");
    						
  						}
  else 
  	{ 	 // se è il figlio
  		printf("FIGLIO: Il mio PID fittizio e' %d\n",child_pid);
  		printf("Figlio: sono il figlio.\n");
  		printf("Il PID di mio padre e' %d\n",getppid());
    	exit(1); // termina il processo figlio
    	
  	}
  return 0;
}
