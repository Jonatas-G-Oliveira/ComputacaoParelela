#include <stdio.h>
#include <gmp.h>


void fatorial(int n,mpz_t r){
    mpz_t resultado;
    mpz_init(resultado);
    mpz_set_d(resultado,1);//Inicializa com o valor de 1

    for(int i = 1;i <= n;i++){
	mpz_mul_si(resultado,resultado,i);
    }
   //--gmp_printf("fatorial de %d  é = %Zd",n,resultado);
   mpz_set(r,resultado);
}


void euler(int n){
    mpz_t r;
    mpz_init(r);//Variavel que pega o valor inteiro de fatorial
    mpf_t divisor;
    mpf_init2(divisor,1000);//Variavel que converte o valor para usarmos na divisao
    mpf_t e;
    mpf_init2(e,7000);//Variavel que guarda o resultado da operação
    mpf_t dividendo;
    mpf_init(dividendo);
    mpf_set_d(dividendo,1);

    fatorial(n,r);
    mpf_set_z(divisor,r);


    mpf_t soma;
    mpf_init2(soma,7000);

    //Tem que fazer o loop agora
    //gmp_printf("Fatorial de %d é = %Ff\n",n,divisor);
    mpf_div(e,dividendo,divisor);
    mpf_add(soma,soma,e);
    //gmp_printf("Euler de == %.Ff",e);
}

int main(){
    //Pensamentos
    //Sera que fazer o fatorial diretamento com floats da certo:
    //Por eu precisar converter inteiros para floats eu preciso de 1000 bits pelo menos para o 100!
    //A divisão funciona
    //--Falta somar
    printf("--=== Projeto Tartaruga --====\n");
    
    euler(5);
    //--fatorial(100);
    return 0;
    }
