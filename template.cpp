#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//dichiarazione variabilecondivisa
int variabile;

pthread_mutex_t semaforo; //crea il semaforo non assegnando nessuno stato

pthread_mutex_t semaforo=PTHREAD_MUTEX_INITIALIZER; //inizializza il semaforo ad occupato

void *dichiarato (void *parametro)
{
	pthread_mutex_lock(semaforo); //blocca il semaforo (lo imposta ad occupato)
	pthread_exit(0);
}


int main()
{
	pthread_t dichiarato; //dichiarazione del thread
	
	pthread_mutex_init(&nomedelsemaforo,null);//inizializzo il semafoto a libero
	
	pthread_create(&dichiarato,NULL,partedicodice,NULL); //crea il thread DICHIARATO
	
	pthread_join(dichiarato,NULL); //il main aspetta la terminazione di DICHIARATO
	
	pthread_mutex_destroy(semaforo); //distruzione semaforo creato
	return 0;
}
