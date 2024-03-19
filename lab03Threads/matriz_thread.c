#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int thread_count = 8;
int **matrizA,**matrizB,** matrizR;
int linhaA = 6000;
int colunaA = 40000;
int linhaB = 40000;
int colunaB = 1;


void aloca_matriz(int ***matriz, int linhas, int colunas) {
  int l = 0;
  int **m = (int **)malloc(linhas * sizeof(int *));
  for (l = 0; l < linhas; l++) {
    m[l] = (int *)malloc(colunas * sizeof(int));
  }
  *matriz = m;
}


void preenche_matriz(int **matriz, int linhas, int colunas) {
  int l, c;
  for (l = 0; l < linhas; l++) {
    for (c = 0; c < colunas; c++) {
      matriz[l][c] = rand() % 10;
    }
  }
}


void print_matriz(int **matriz, int linhas, int colunas) {
  int l, c;
  for (l = 0; l < linhas; l++) {
    for (c = 0; c < colunas; c++) {
      printf("\t%4d", matriz[l][c]);
    }
    printf("\n");
  }
}


void *multiplica_matriz_threads(void* n_thread ){
  long numero_thread = (long) n_thread;
  int i,j,k;
  int divisao = linhaA/thread_count;
  int primeira_linha = numero_thread * divisao;
  int ultima_linha = (numero_thread+1) * divisao -1;

  //Essa Operação faz a ultima thread trabalhar mais do que as outras
  int resto = linhaA%thread_count;
  if(numero_thread == thread_count-1){
	int resto = linhaA%thread_count;
	//printf("ultima thread %d ",resto);
	ultima_linha = ultima_linha + resto;	
  }
  for(i = primeira_linha; i <= ultima_linha; i++){
  	for(j = 0; j < colunaB;j++){
	   for(k = 0; k < colunaA;k++){
		matrizR[i][j] += matrizA[i][k] * matrizB[k][j];
	}
     }
  }
  return NULL;
}




void libera_matriz(int **matriz, int linhas) {
  int l;
  for (l = 0; l < linhas; l++) {
    free(matriz[l]);
  }
  free(matriz);
}


int main(int argc, char * argv[]) {
  printf("\n -= Multiplicação de Matrizes -= \n");
  if(colunaA != linhaB){
    printf("Não é possível fazer as operações");
    return 1;
  }
  
  aloca_matriz(&matrizA, linhaA, colunaA);
  aloca_matriz(&matrizB, linhaB, colunaB);
  aloca_matriz(&matrizR, linhaA, colunaB);
  preenche_matriz(matrizA, linhaA, colunaA);
  preenche_matriz(matrizB, linhaB, colunaB);
/*
  printf("Matriz A: \n");
  print_matriz(matrizA, linhaA, colunaA);
  printf("Matriz B: \n");
  print_matriz(matrizB, linhaB, colunaB);

  printf("Matriz Resultante: \n");
*/
  long thread;
  pthread_t *vetor_thread = malloc(thread_count * sizeof(pthread_t));
  for(thread = 0;thread < thread_count;thread++){
  	pthread_create(&vetor_thread[thread],NULL,multiplica_matriz_threads,(void*)thread );
  }

  for(thread = 0;thread < thread_count;thread++){
        pthread_join(vetor_thread[thread],NULL);
  }
 /* 
  print_matriz(matrizR,linhaA,colunaB);
 */ 
  free(vetor_thread);
  libera_matriz(matrizA, linhaA);
  libera_matriz(matrizB, linhaB);
  libera_matriz(matrizR, linhaA);
  return 0;
}
