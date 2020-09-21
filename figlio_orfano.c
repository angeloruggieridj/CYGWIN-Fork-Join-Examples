#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main( )
{ pid_t pid;
pid=fork(); //creo il processo figlio
if (pid==0) {
				printf("Figlio: Sono il processo figlio\n");
				pid_t pidproprietario= getpid(); //verifico il pid del figlio
				printf("Figlio: Il mio pid e': %d\n", pidproprietario);	 //stampo il pid del figlio
				sleep(5);
				pid_t pidpapa= getppid(); //verifico il pid del padre che lo ha generato
				if (pidpapa==1) printf("Figlio: Sono diventato un processo orfano\n"); //verifico se il pid è =1 il padre è stato ucciso altrimenti
				else {
						
						printf("Figlio: mio padre ha PID: %d\n",pidpapa); //stampo il pid del padre che lo ha generato
						printf("Figlio: Mio padre non e' ancora morto e non sono quindi orfano\n");
					}
					exit(1); //uccisione del figlio
			}
else {
		printf("Padre: Sono il processo padre\n");
		pid_t pidproprietario= getpid(); //verifico il pid del padre
		printf("Padre: Il mio pid e': %d\n", pidproprietario); //stampo il pid del padre che sarà uguale al ppid del figlio
		exit(0); //uccido il padre
		
	 }
  
} 
    
