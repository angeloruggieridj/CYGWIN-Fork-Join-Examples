#include <unistd.h>  
#include <stdio.h>  
#include <sys/wait.h>  
#include <stdlib.h> 
 
#define due 2  
int main() {  
   pid_t pid;  
   int retv;  
   pid = fork(); // creazione di un processo figlio  
  
     if (pid==0)
    {  
       /* utilizzo getpid() e getppid() per avere il valore pid e ppid */ 
       printf("Figlio (pid=%d, ppid=%d) in sleep per %d secondi\n",getpid(),getppid(), due);  
       sleep(2);  
       printf("Figlio (pid=%d, ppid=%d) si risveglia\n", getpid(), getppid());  
       exit(1);  
     }  
   else {  
     // utilizzo getpid() e getppid() per avere il valore pid e ppid  
       printf("Padre (pid=%d) attende il figlio\n", getpid());  
       wait(&retv);  
     // utilizzo oltre alle funzioni citate, la macro WEXITSTATUS(retv) per ottenere il valore di ritorno  
     printf("Padre (pid=%d) riceve da figlio exit status %d\n",getpid(),WEXITSTATUS(retv));  
        }  
      
  return 0;  
 } 
