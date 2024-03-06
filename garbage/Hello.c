#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int thread_count;

void *Hello(void *rank){
	long ran =(long)rank;
	printf("%ld",ran);
}

int main(int argc, char * argv[]){
	long thread; 
	pthread_t* thread_handles;

	thread_count = strtol(argv[1],NULL, 10);

	thread_handles = malloc(thread_count  * sizeof(pthread_t)); 
	
	long  numeros;
	for(numeros = 0; numeros < thread_count; numeros++){
		pthread_create(&thread_handles[numeros],NULL,Hello,(void*) numeros);
	}
	printf("Sou a Thread  pai");


	for(numeros = 0; numeros < thread_count; numeros++){
		pthread_join(thread_handles[numeros],NULL);
	}
	free(thread_handles);
	return 0;
}
