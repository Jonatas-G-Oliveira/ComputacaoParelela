#include<stdio.h>

//www.quora.com/How-do-I-divide-two-very-large-numbers-that-are-more-than-1000-minimum-characters-in-length
//Funciona para numero inteiros onde o divisor é maior que o dividendo


void divisao_vetor(int *vetor,int tamanho){
    int indice = tamanho-1;
    int divisor = 5;
    int carry = 0;
    for(indice;indice >= 0;indice--){
        int quociente = (carry + vetor[indice]) / divisor ;
        printf("\n->%d",quociente);
        int m = quociente * divisor;
        printf("\n->%d",m);
        carry = ((carry + vetor[indice]) - m)*10;
        vetor[indice] = quociente;
        printf("\n->%d",carry + vetor[indice-1]);
	printf("\n\n");
    }
}


void print_vetor(int *vetor,int tamanho){
	int elemento;
	for(elemento = tamanho-1;elemento >= 0;elemento--){
		printf("%d",vetor[elemento]);
	}
}


int main(){
    int n[4] = {5,4,2,3};
    print_vetor(n,4);
    divisao_vetor(n,4);
    print_vetor(n,4);
    return 0 ;
}
