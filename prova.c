#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void main( ){ 
 pid_t pid;
 pid=fork();
 if (pid==0)
   {
   printf("sono il processo figlio\n");
   exit(1) ;     /* termina processo figlio */
 	}
else{
   printf("sono il processo padre\n");
   exit(0) ;     /* non necessaria */
       }
    }
