#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>




double funcao(double x){
	double f = sin(x);
        if(f < 0){
	   return f * -1;
	}else{
  	   return sin(x);
	}
}


void area_trapezio(float a,float b,int n,double *soma_global){
	int numero_thread = omp_get_thread_num();
	int qtd_thread = omp_get_num_threads();

	int tarefas_por_thread = n/qtd_thread; //5
	//printf("\nhello from thread [%d] Vou executar %d retangulos",numero_thread,tarefas_por_thread);

	float divisoes = (b-a)/n; //0.5

	float inicio = numero_thread * tarefas_por_thread * divisoes;


	int i = 0;
	a = inicio;
	b = a;
	float soma_local = 0;
	for(i;i < tarefas_por_thread;i++){
		b += divisoes;
		soma_local += (funcao(a) + funcao(b))*(b-a)/2;
		a = b;	
	}

	//Caso eu chegue na ultima thread e não tenha sobrado tarefas pra serem executadas
	if(numero_thread == qtd_thread-1){
	    if(n%(numero_thread+1) != 0){
	      a = b;
              b = a;
	      int i = 0;
	      for(i;i < n%(numero_thread+1);i++){
		b += divisoes;
		soma_local += (funcao(a) + funcao(b))*(b-a)/2;
		a = b;	
	      }	      
	    }
	}
	//printf("sai de %lf",inicio);
	//printf("cheguei no %f",b);
	//printf("minha soma deu {%lf}",soma_local);

	#pragma omp critical
	*soma_global += soma_local;
}


int main(){
	double soma_global = 0.0;
	double a = 0;
	double b = 10000000;
	int n = 1000;
	int qtd_threads;
	
	qtd_threads = 1;
	printf("Iremos calcular A = %.2lf e B = %.2lf dividido em %d trapezios\nThreads = [%d]\n",a,b,n,qtd_threads);

	#pragma omp parallel num_threads(qtd_threads)
	area_trapezio(a,b,n,&soma_global);

	printf("\nA area da funcao sin(x) = %lf \n",soma_global);
	return 0;
	
}
