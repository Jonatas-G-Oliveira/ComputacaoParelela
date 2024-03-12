#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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


void multiplica_matriz(int **matrizA, int **matrizB, int **matrizR, int linhasA, int colunasA, int colunasB) {
  int i, j, k;
  for (i = 0; i < linhasA; i++) {
    for (j = 0; j < colunasB; j++) {
      for (k = 0; k < colunasA; k++) {
        matrizR[i][j] += matrizA[i][k] * matrizB[k][j];
      }
    }
  }
}


void libera_matriz(int **matriz, int linhas) {
  int l;
  for (l = 0; l < linhas; l++) {
    free(matriz[l]);
  }
  free(matriz);
}


int main(void) {
  printf("\n -= Multiplicação de Matrizes -= \n");
  int **matrizA, **matrizB, **matrizR;
  int linhaA = 5;
  int colunaA = 4;
  int linhaB = 4;
  int colunaB = 1;
  if(colunaA != linhaB){
    printf("Não é possível fazer as operações");
    return 1;
  }
  
  aloca_matriz(&matrizA, linhaA, colunaA);
  aloca_matriz(&matrizB, linhaB, colunaB);
  aloca_matriz(&matrizR, linhaA, colunaB);
  preenche_matriz(matrizA, linhaA, colunaA);
  preenche_matriz(matrizB, linhaB, colunaB);

  printf("Matriz A: \n");
  print_matriz(matrizA, linhaA, colunaA);
  printf("Matriz B: \n");
  print_matriz(matrizB, linhaB, colunaB);

  printf("Matriz Resultante: \n");
  multiplica_matriz(matrizA, matrizB, matrizR, linhaA, colunaA, colunaB);
  print_matriz(matrizR,linhaA,colunaB);
  
  libera_matriz(matrizA, linhaA);
  libera_matriz(matrizB, linhaB);
  libera_matriz(matrizR, linhaA);
  return 0;
}
