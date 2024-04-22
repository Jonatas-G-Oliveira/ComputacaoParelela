#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

float potencia(float base,int expoente){
   float resultado = base;
   int i = 1;
   for(i;i < expoente;i++){
	resultado = resultado * base;
   }
   return resultado;
}

float funcao(float x){
    float f = potencia(2.71828,x);
    return f;
}
 
float regra_trapezio_unico(float a,float b){
   float area  = (funcao(a) + funcao(b)) * (b-a)/2;
   return area;
}	

float regra_trapezio(float a,float b,float n){
   float divisoes = (b-a)/n;
   int i = 0;
   float soma = 0;
   for(i; i < n;i++){
      b = a + divisoes;
      soma +=  ((funcao(a) + funcao(b))*(b-a))/2 ;
      printf("A vale %f B vale %f essa area vale:%f \n",a,b,(funcao(a) + funcao(b))*(b-a)/2);
      a = b;
   }
   return soma;
}

int main(int argc,int **argv){
    float resultado = regra_trapezio_unico(1,2);
    printf("\nA area da curva é %f \n",resultado);

    printf("A area da curva é aproximada é %f",regra_trapezio(1,2,4));
   


    return 0;
}
