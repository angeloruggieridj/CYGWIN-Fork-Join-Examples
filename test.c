#include<stdlib.h>
#include <stdio.h>
#include<pthread.h>

int variabile=100;

pthread_mutex_t scrivi;
pthread_mutex_t leggi = PTHREAD_MUTEX_INITIALIZER;

void *produttore (void *arg)
{
	pthread_mutex_lock(&scrivi);
	printf("PRODUTTORE: Il valore e': %d\n",variabile);
	int n;
	printf("Inserire valore da sommare: ");
	scanf("%d",&n);
	printf("Il valore di n e: %d",n);
	variabile=variabile+n;
	printf("Variabile condivisa vale: %d",variabile);
	pthread_mutex_unlock(&leggi);
	pthread_exit(0);
}

void *consumatore (void *arg)
{
	pthread_mutex_lock(&leggi);
	printf("CONSUMATORE: Il valore e': %d",variabile);
	pthread_mutex_unlock(&scrivi);
	pthread_exit(0);
}


int main()
{
	pthread_t produci;
	pthread_t consuma;
	
	pthread_mutex_init(&scrivi,NULL);
	
	pthread_create(&produci,NULL,produttore,NULL);
	//printf("Ora passo al consumatore\n");
	pthread_create(&consuma,NULL,consumatore,NULL);
	
	pthread_join(produci,NULL);
	pthread_join(consuma,NULL);
	
	pthread_mutex_destroy(&scrivi);
	pthread_mutex_destroy(&leggi);
	return 0;
}
