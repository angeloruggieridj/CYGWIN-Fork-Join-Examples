#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void main( ){ 
 pid_t pid;
 pid=fork(); //nasce il figlio
 if (pid==0)
   {
   printf("sono il processo figlio 1\n");
   exit(1) ;     /* termina processo figlio */
 	}
pid=fork(); //genera il secondo figlio
if (pid==0)
{
   printf("sono il processo figlio 2\n");
   exit(1) ;     /* termina processo figlio */
 	}
else{
   printf("sono il processo padre\n");
   exit(0) ;     /* non necessaria */
       }
    }




/*
fork() nasce il processo figlio identico al processo figlio, il return è un intero
       al padre restituisce il  PID Del figlio, se ce errore il return è -1;
       fa uso della libreria #include <stdlib.h>
       che si chiude con l'istruzione Join

join() termina l'esecuzione parallelo*/
