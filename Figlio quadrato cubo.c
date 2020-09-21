/*
Scrivere un programma che calcoli il quadrato o il cubo di un intero chiesto da input.
Il figlio richiede due numeri da input, ne fa la somma
Il padre riceve il valore e se dispari ne esegue e mostra il cubo, se pari ne esegue e mostra il quadrato
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
	//int k=1;
	int numProcessi;
	int retv;
	int a,b,c,d;
	int flag;
	
	
	pid=fork();
	if(pid==0) 
				{
					printf("Inserire primo valore: ");
					scanf("%d",&a);
					printf("Inserire secondo valore: ");
					scanf( "%d",&b);
					c=a+b;
					printf("Ecco la somma: %d\n",c);
					
					if(c%2==0)
					{
						printf("La somma e' pari \n");
						flag=0; //se il flag è a 1 la somma è dispari, se a 0 la somma è pari
							
					}
					else
					{
						printf("La somma e' dispari \n");
						flag=1;
					}
					exit(c); //e se voglio mettere il flag in uscita come faccio??
					//set di istruzioni del figlio
				}
	else
	{
		printf("Attendo l'elaborazione di mio figlio \n");
		wait(&retv);
		c=WEXITSTATUS(retv);
		//flag=WEXITSTATUS(retv);
	//	if(flag==1) printf("Il flag e' settato a 1 \n");
		printf("Adesso parto con la mia elaborazione \n");
		printf("Ecco la somma: %d\n",c);

			if(c%2!=0)
		{
			d=(c*c*c);
			printf("Il cubo e': %d\n",d);
		}
		else
		{
			d=(c*c);
			printf("Il quadrato e': %d\n",d);
		}
		
		
		
		
		/*
		
		
		//set di istruzioni del padre
		if(flag==1)
		{
			d=(c*c*c);
			printf("Il cubo e': %d",d);
		}
		else
		{
			d=(c*c);
			printf("Il quadrato e': %d",d);
		}
		*/
	}
}
