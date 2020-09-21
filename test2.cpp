#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int variabile;

pthread_mutex_t scrivi;
pthread_mutex_t leggi= PTHREAD_MUTEX_INITIALIZER;

void *produttore (void *arg)
{
	pthread_mutex_lock(&scrivi);
	srand(time(NULL));
	variabile=rand()%100;
	printf("Il valore della variabile e': %d",variabile);
	pthread_mutex_unlock(&leggi);
	pthread_exit(0);	
}

void *consumatore (void *arg)
{
	pthread_mutex_lock(&leggi);
	printf("Trovato %d\n",variabile);
	variabile=variabile*2;
	printf("La variabile ora vale: %d\n",variabile);
	pthread_mutex_unlock(&scrivi);
	pthread_exit(0);
}

int main()
{
	pthread_t produci;
	pthread_t consuma;
	
	pthread_create(&produci,NULL,produttore,NULL);
	pthread_create(&consuma,NULL,consumatore,NULL);
	
	pthread_join(produci,NULL);
	pthread_join(consuma,NULL);
	
	pthread_mutex_destroy(&scrivi);
	pthread_mutex_destroy(&leggi);
	return 0;
}
