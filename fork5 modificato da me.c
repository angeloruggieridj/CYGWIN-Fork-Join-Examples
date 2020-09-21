#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(){ 
  pid_t pid,figlio1pid,padrepid,figlio2pid;
  pid=fork(); //restituisce 0 se è il figlio, -1 se si verifica un errore
  if(pid==0) //sfrutto per capire se in quel momento cosa è in esecuzione: il padre o il figlio?
  {
    figlio1pid=getpid();
    printf("1)sono il primo processo figlio con pid: %i\n",figlio1pid);
    exit(1);        /* termina primo processo figlio */
  }else{
    printf("2)sono il processo padre\n");
    printf("3)sono ancora il processo padre e ho creato un processo con pid: %i\n", pid); //il pid è quello del figlio
    padrepid=getpid();
    printf("4)sono sempre il cacacazzo del padre e il mio pid e' invece: %i\n", padrepid); //qui stampa il suo pid padre
    pid=fork();
    if (pid==0){
      figlio2pid=getpid();
      printf("5)sono il secondo processo figlio con pid: %i\n",figlio2pid);
      exit(2);      /* termina secondo processo figlio */
    }else {
      printf("6)sono il processo padre\n");
      printf("7)sono ancora il processo padre e ho creato un secondo processo con pid: %i\n", pid);
      exit(0);      /* non necessario */
    }
  }
}





