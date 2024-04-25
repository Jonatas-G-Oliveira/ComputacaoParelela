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

double fatorial(int n){
    if(n == 0){
       return 1;
    }
    double fat = n;
    for(int i =n-1; i > 0;i--){
	//printf("%d ->",i);
	fat = fat * i;
	//printf("%d\n",fat);
    }
    return fat;
}

double serie_taylor(int n){
   double e = 0;
   for(int i = 0;i < n;i++){
	e += 1/fatorial(i);
	//printf("%f ->",1/fatorial(i));
   }
   return e;
}

int main(int argc, char **argv){
    printf("Projeto Turtle\n");
    //printf("Fatorial de 5 %d \n",fatorial(5));
    printf("\nSerie de taylor para n = 5000 %lf",serie_taylor(50000));
}
