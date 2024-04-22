#include <stdio.h>
#include <stdlib.h>
#include <omp.h>



void Hello(void);

int main(int argc,char **argv){
    //argc -> Número de parametros passado na linha de comando
    //argv -> Os parametros em si,entendidos com string,pos[0] guarda o nome do programa
    
    int quantidade_threads = atoi(argv[1]);
    
    //Pragama -> Instruções pro compilador
    //omp parallel -> Vai carregar a biblioteca
    
    #pragma omp parallel num_threads(quantidade_threads)
    Hello();

    return 0;
}

void Hello(void){
    int numero_thread = omp_get_thread_num(); //Id das threads
    int total_threads = omp_get_num_threads();

    printf("Hello from thread %d of %d\n",numero_thread,total_threads);
}
