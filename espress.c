#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main( )
{ 
  int x,y,z, retv;
  pid_t pid;
  pid=fork();     // inizio elaborazione parallela 
  if (pid==0)	//controlla se è in esecuzione il figlio (pid=0) o il padre (pid >0)
  				{    
    				x=figlio1();  // esecuzione codice della funzione del processo figlio
    				exit(x) ;     // termina processo figlio (exit(5))
   				}
  else							//inizia elaborazione del codice del padre
      			{
      				printf("elab. parallela processo padre\n");
      				y = 6-2;				//y=4
      			}
  printf("join: padre aspetta \n"); 
  wait(&retv);           // join : il padre aspetta il figlio 
  x =WEXITSTATUS(retv);  // prende il risultato del figlio
  printf("elab. finale padre\n");
  z=(x+y);							//collega i due risultati insieme
  printf("risultato finale z= %d", z );
 }

int figlio1()
{
 int k;
 printf("elab. parallela processo figlio \n");
 k = 3+2;
 return k; 
} 
    
