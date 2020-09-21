#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* codice_thread(void*arg)
{
	printf("Il pid del figlio e' %d\n",(int)getpid());
	return NULL;
}

int main()
{
	pthread_t miothread;
	printf("Il pid del main is %d\n",(int)getpid());
	pthread_create(&miothread,NULL,&codice_thread,NULL);
	sleep(2);
	return 0;
}
