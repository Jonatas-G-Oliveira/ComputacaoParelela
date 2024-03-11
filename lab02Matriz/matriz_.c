#include<stdio.h>
#include<stdlib.h>


void aloca_matriz(int ***matriz,int linhas,int colunas){
	int l;
	int **m = (int**) malloc(linhas  * sizeof(int** ));
	for(l = 0;l < linhas;l++){
		 m[l]  = (int*) malloc(colunas * sizeof(int* ));
	}
	*matriz = m;
}


void mult_matriz(int **matrizA,int **matrizB, int linhasA,int colunasA,int linhasB,int colunasB){
	if(colunasA != linhasB){
		printf("Add erro");
	}
	int l,c;
	int **matrizR = aloca_matriz(&matrizR,linhasA,colunasB);
	
	for(l = 0;l < linhasA;l++){
		for(c = 0;c < colunasB;c++){
			printf("%d,%d",matrizA[l][c],matrizB[l][c]);
		}	
	}	
	
}


void print_matriz(int **matriz,int linhas,int colunas){
	int l,c;
	for(l = 0; l < linhas;l++){
		for(c = 0;c < colunas;c++){
			printf("%d ",matriz[l][c]);
		}
		printf("\n");
	}
}


void libera_matriz(int **matriz,int linha,int linhas){
	int l;
	for (l =0; l < linhas;l++){
		free(matriz[l]);
	}
	free(*matriz);
}


int main(int argc, char *args[] ){
	printf("\nMultiplicação de matrizes\n");
	int ** matrizA;
	int ** matrizB;
	aloca_matriz(&matrizA,2,3);
	aloca_matriz(&matrizB,3,1);
	printf("Matriz A\n");
	print_matriz(matrizA,2,3);
	printf("MAtriz B\n");
	print_matriz(matrizB,3,1);


	return 0;
    }
