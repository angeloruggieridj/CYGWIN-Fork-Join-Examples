#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main( )
{ 
  /**
  Scrivi un programma che produca un risultato simile a quello riportato dove un processo padre genera quattro figli che vivono due secondi e poi terminano la loro esecuzione.


cout figlio1 con pid, mio padre ha pid (pidpadre) (x4) - - - SLEEP 2 secondi
cout figlio2 con pid, mio padre ha pid (pidpadre) (x4) - - - SLEEP 2 secondi
cout figlio3 con pid, mio padre ha pid (pidpadre) (x4) - - - SLEEP 2 secondi
cout figlio4 con pid, mio padre ha pid (pidpadre) (x4) - - - SLEEP 2 secondi
padre: (PID5740) e con ppid (del gruppo) riceve dal figlio (pid) exit status 1 (riceve informazioni sui figli che stanno morendo)

*/

pid_t id1,id2,id3,id4;
id1=fork(); //il padre crea il figlio 1
if (id==0)
			{
					printf("Sono il figlio 1\n");
			}
else {
		id2=fork();
		if (id2==0)
		{
				printf("Sono il figlio 2\n");
		}
		else
		{
			id3=fork();
			if(id3==0)
			{
					printf("Sono il figlio 3\n");
			}
			else 
			{
				id4=fork();
				if(id4==0)
				{
						printf("Sono il figlio 4\n");
				}
				else
				{
						printf("Sono il processo padre\n");
				}
			}
		}
	 }
} 
    
