#include <stdio.h>



void fatorial(int *resposta,int n){
	//Fatorial de 1 e 0;
	resposta[0] = 1;
	int tamanho = 1;
	int carry = 0;
	int i,multiplicador;
	
	int aux;
	
	for(multiplicador = 1; multiplicador <= n; multiplicador++){
		carry = 0;
		i = 0;
		while(i < tamanho){
			resposta[i] = (resposta[i] * multiplicador) + carry;
			carry       = resposta[i] / 10;
			resposta[i] = resposta[i] % 10; //Pega o digito unico
			i++;
		}
		while(carry != 0){
			resposta[tamanho] = carry % 10;
			carry = carry/  10;
			tamanho++;
		}
	}	
}


void print_vetor(int *vetor,int tamanho){
	int elemento;
	for(elemento = tamanho-1;elemento >= 0;elemento--){
		printf("%d",vetor[elemento]);
	}
}


int main(){
	int N = 100;
	int numero_digitos[1000] = {0};

	fatorial(numero_digitos,N);
	printf("\n\n\n ");
	print_vetor(numero_digitos,158);
	return 0;
}
