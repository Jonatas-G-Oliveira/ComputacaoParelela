#include<stdio.h>
#include<gmp.h>


void fatorial(int n,mpz_t *resultado){
	mpz_t f;
	mpz_set_ui(f,n);
	mpz_t proximo;

	for(int i = 1;i < n;i++){
	   mpz_set_ui(proximo,i);
	  // gmp_printf("%Zd -> ",proximo);
           mpz_mul(f,proximo,f);
	  // gmp_printf("%Zd -> ",f);
	}

//	gmp_printf("\n-> %Zd",f);
	mpz_set(*resultado,f);	
    }


void euler(mpz_t *numero){
	//Inicializando Euler
 	mpf_t e;
	mpz_t dividendo;
	mpz_set_ui(dividendo,1);
	//mpf_init(e,256) Vai ter pelo  pelo menos 256 bits de precisao
	
	//mpz_fdiv_q(e,dividendo,resultado);
	gmp_printf("\n -> %Zf",e);
}


int main(){
   mpz_t numero;
   mpz_init(numero);
   //Usar pra resetar um numero;
   //mpz_init(numero);//A variavel pode ser usada
		    
   //A atribuiução funciona dessa maneira
   //mpz_set_ui(numero,"12222222222222222222222255555555555555555555547777");
   //O print funciona dessa maneira
   //gmp_printf("%Zd\n",numero);


   printf("GMP -> %d\n\n",__GNU_MP_RELEASE);
   fatorial(10,&numero);
   gmp_printf("\n-> %Zd",numero);
   euler(&numero);
   return 0;
}
