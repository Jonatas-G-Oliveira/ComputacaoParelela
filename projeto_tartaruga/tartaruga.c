#include<stdio.h>
#include<stdlib.h>


//Maior quantidade de casas decimais
//Menor tempo

//Tudo que é conta da pra otimizar
//--> Otimizar o fatorial
//--> Otimizar a série de taylor

//Se eu otimizar as contas em serial eu penso no paralelo
//Se eu chegar no máximo do paralelo eu troco a linguagem
//--> Fim

float fatorial(int n){
    if(n == 0){
       return 1;
    }
    float fat = n;
    int i = n-1;
    for(i; i > 0;i--){
		fat *= i;
    }
    return fat;
}

float serie_taylor(int n){
   float e = 0;
   float f = 0;
   int i = 0;
   for(i;i <= n;i++){
   	f = 1/(float)fatorial(i);
	e += f;
	printf("1 / %d! = 1/%f == %f \n",i,fatorial(i),f);
   }
   return e;
}

int main(){
    printf("Projeto Turtle\n");
    printf("\nSerie de taylor para n = 9 %.20f",serie_taylor(9));
    return 0;
}
