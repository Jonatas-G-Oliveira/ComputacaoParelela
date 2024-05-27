#include <stdio.h>
#include <gmp.h>
#include <omp.h>


void fatorial(int n,mpz_t r){
    mpz_t resultado;
    mpz_init(resultado);
    mpz_set_d(resultado,1);

    for(int i = 1;i <= n;i++){
	mpz_mul_si(resultado,resultado,i);
    }
    mpz_set(r,resultado);
}


void euler(int n,mpf_t *soma_global){
    int numero_thread = omp_get_thread_num();
    int qtd_threads = omp_get_num_threads();

    int qtd_tarefas = n/qtd_threads;
    int comeco_local = numero_thread*qtd_tarefas;
    int fim_local = comeco_local + qtd_tarefas;
	
    if(n%qtd_threads > 0 && numero_thread == qtd_threads-1){
    	fim_local = fim_local + n%qtd_threads;
    }
   // printf("Oi eu sou a thread %d,Start[%d]End[%d] <%d>",numero_thread,comeco_local,fim_local,qtd_threads);
    mpz_t r;
    mpz_init(r);//Variavel que pega o valor inteiro de fatorial
    mpf_t divisor;
    mpf_init2(divisor,3000000);//Variavel que converte o valor para usarmos na divisao
    mpf_t aux;
    mpf_init2(aux,80000);//Variavel que guarda o resultado da operação
    mpf_t dividendo;
    mpf_init(dividendo);
    mpf_set_d(dividendo,1);//Inicializando o dividendo com 1

    fatorial(n,r);
    mpf_set_z(divisor,r);


    mpf_t soma;
    mpf_init2(soma,80000);

    //Tem que fazer o loop agora
    for(int i = comeco_local; i < fim_local;i++){
	fatorial(i,r);
	mpf_set_z(divisor,r); //Converte o resultado para float

	mpf_div(aux,dividendo,divisor);
	mpf_add(soma,soma,aux);
    }

    #pragma omp critical
    mpf_add(*soma_global,*soma_global,soma); 

    //p_printf("Euler de == %.Ff",soma);
}

int main(){
    //Pensamentos
    //Sera que fazer o fatorial diretamento com floats da certo:
    //Por eu precisar converter inteiros para floats eu preciso de 1000 bits pelo menos para o 100!
    //fatorial 3000 ->30000 bits de resposta.
    int quantidade_threads = 2;
    
    printf("--=== Projeto Tartaruga --====\n");
    
    mpf_t soma_global;
    mpf_init2(soma_global,80000);

    # pragma omp parallel num_threads(quantidade_threads)
    euler(10000,&soma_global);

    gmp_printf("Euler de == %.Ff",soma_global);
    return 0;
}
