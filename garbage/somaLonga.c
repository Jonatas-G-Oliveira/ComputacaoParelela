#include<stdio.h>
#include<stdlib.h>//Vamos utilizar vetor para guardar o vetor


//Lidando com números grandes em c
//Soma simples não funciona tão bem
void add(int a,int b){
    printf("Add of %d + %d = %d\n",a,b,a+b);
}


//Vamos fazer 3 pilhas de operadores
//Pilha 1 e 2 vai segurar os operand 
//Pilha 3 vai segurar os resultados

struct pilha_numeros{
    int top;
    unsigned altura_pilha;
    int* array;
};


//Construtor
struct pilha_numeros* criarPilha(unsigned altura_pilha){
    (struct pilha_numeros*) malloc(sizeof(struct pilha_numeros));

}

int main(){
    int a,b;
    a = 2147483647;
    b = 1;
    add(a,b);

    return 0;
}

