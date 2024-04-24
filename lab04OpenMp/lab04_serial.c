#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double funcao(double x){
	double f = sin(x);
	if (f < 0){
		return f * -1;
	}else{
	    f;
	}
}


float area_trapezio(float a,float b,float n){
	
	//Calcula o número de divisões
	float altura  = b-a;
	float distancia_retangulos = altura/n;
	double aproximacao = 0;

	int i = 0;
	b = a;
	for(i; i < n;i++){
		b += distancia_retangulos;
		aproximacao += ((funcao(a) + funcao(b)) * (b-a))/2;
		a = b;
	}
	return aproximacao;
}


int main(){
	printf("\nA area da funcao sen(x) = com %lf \n",area_trapezio(0,1000000,1000));
	printf("A = [0], B = [10000000], Trapezios = [1000]"); 
	return 0;
	
}
