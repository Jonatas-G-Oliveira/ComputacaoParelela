#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void  *hello(void *args){
	long numero = (long)  args;
	printf("Hello from thread %ld",args);
	return NULL;
}


//Os parametros da main são 
//argv -> Vetor de strings
//argc -> Número de parametros passados

int main(int argc, char **argv){
	int numero_threads = atoi(argv[1]);
	
	//Criar espaços de alocação de threads
	//Finalizar as thrd
	
	pthread_t *vetor_thread = malloc(numero_threads * sizeof(pthread_t));
	
	printf("Hello from main\n");
	for(long thread = 0;thread < numero_threads;thread++){
		printf("%ld", thread);
		pthread_create(&vetor_thread[thread],NULL,hello,(void *)thread);
	}

	for(long thread = 0;thread < numero_threads;thread++){
		pthread_join(vetor_thread[thread],NULL);
	}
	printf("%d",numero_threads);

	free(vetor_thread);
	return 0;
}
