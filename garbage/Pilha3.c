#include <stdio.h>
#include <stdlib.h>


typedef struct CELULA{
	int dado;
	struct CELULA *proximo;
}CELULA;

typedef struct PILHA{
	struct CELULA *topo;
	int tam;
}PILHA;


void inicializarPilha(PILHA *pilha){
	pilha->topo = NULL;
	pilha->tam = 0;
}


void empilhar(int elemento,PILHA *pilha){
	CELULA *novo = malloc(sizeof(CELULA));
	
	novo->dado = elemento;
	novo->proximo = pilha->topo;
	pilha->topo = novo;
	printf("-- Empilhando Numero -> %d\n",elemento);
}


void desempilhar(PILHA *pilha){
	if(pilha->topo == NULL){
		printf("Pilha Vazia");
	}else{
		//Temos que limpar esse espaço de memoria,eu sei que parece redundante mas é necessári
		CELULA *aux = pilha->topo;
		pilha->topo = aux->proximo;
		printf("x- Eliminando o numero %d -x \n",aux->dado);
		free(aux);  
	}
}


void imprimirPilha(PILHA *pilha){
	if(pilha->topo == NULL){
		printf("Pilha Vazia");
	}else{
		CELULA *aux = pilha->topo;
		while(aux != NULL){
			printf("Numero -> %d \n",aux->dado);
			aux = aux->proximo;
		}
	}
}

int main(){

	return 0;
}
