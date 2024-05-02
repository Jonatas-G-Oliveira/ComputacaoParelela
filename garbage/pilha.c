#include<stdio.h>
#include<stdlib.h>


//Todos os nós são alocados dinamicamente
//Insere um elemento,o ponteiro vai apontar pro topo


typedef struct NO{
    int dado;
    struct NO *prox;
}NO;

typedef struct PILHA{
   NO* topo;
}PILHA;	


void inicializarPilha(PILHA *p){
   P->topo = NULL;
}




void empilhar(PILHA *p,int dado){
    NO *novo_no = (NO*) malloc(sizeof(NO));
    if(novo_no == NULL){
	printf("Erro de alocação de de memória");
    }else{
	novo_no->dado = dado;
	novo_no->prox = p->topo;
	p->topo = prox;
    }
}

int desimpilhar(PILHA p*){
    NO* ptr_aux = p->topo;
    int dado;
    if(ptr_aux == NULL){
	printf("Pilha Vazia.\n");
	return;
     }else{
        p->topo = ptr_aux->prox;
        ptr->prox = NULL;
	dado = ptr->dado;
        free(ptr);
	return dado;
     }
}
int main(){

    return 0;
}
