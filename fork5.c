#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(){ 
  pid_t pid,miopid;
  pid=fork(); //restituisce 0 se è il figlio, -1 se si verifica un errore, !=0 se è il padre
  if(pid==0) //sfrutto per capire se in quel momento cosa è in esecuzione: il padre o il figlio?
  {
    miopid=getpid();
    printf("1)sono il primo processo figlio con pid: %i\n",miopid);
    exit(1);        /* termina primo processo figlio */
  }else{
    printf("2)sono il processo padre\n");
    printf("3)ho creato un processo con pid: %i\n", pid); //il pid è quello del figlio
    miopid=getpid();
    printf("4)il mio pid e' invece: %i\n", miopid); //qui stampa il suo pid padre
    pid=fork();
    if (pid==0){
      miopid=getpid();
      printf("5)sono il secondo processo figlio con pid: %i\n",miopid);
      exit(2);      /* termina secondo processo figlio */
    }else {
      printf("6)sono il processo padre\n");
      printf("7)ho creato un secondo processo con pid: %i\n", pid);
      exit(0);      /* non necessario */
    }
  }
}





