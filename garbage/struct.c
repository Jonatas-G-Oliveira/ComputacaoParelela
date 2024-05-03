#include <stdio.h>
#include<string.h>


//Struct são estruturas de ados com tipos compostos
//Ao inves de varíaveis usamos uma struct
typedef struct {
	int dia,mes,ano;
}CALENDARIO;

typedef struct { 
    CALENDARIO dataNascimento;
	char nome[10];
	char sexo;
	int idade;
	
}ALUNO;


struct ALUNO2{
	int cpf;
};

//Criar uma variavel
//Com o typedef -> ALUNO aluno
//Sem o typedef -> struct ALUNO aluno

void print_aluno(ALUNO aluno){
	printf("Nome: %s\n",aluno.nome);
	printf("Idade: %d\n",aluno.idade);
	printf("Sexo: %c\n",aluno.sexo);
}

//Quando eu vou acessar endereços de memória usa a seta
void modifica_struct(ALUNO *aluno){
    strcpy(aluno->nome,"Marcos");
}


int main(){
	ALUNO aluno[10];
	
	aluno[0].idade = 10;
	aluno[0].sexo = 'M';
	strcpy(aluno[0].nome,"Joao");
	
	//Podemos ter  Structs dentro de outras
	aluno[0].dataNascimento.ano = 2022;
	aluno[0].dataNascimento.mes = 2;
	aluno[0].dataNascimento.dia = 3;
	print_aluno(aluno[0]);
	printf("O tamanho da struct em bytes e %d\n",sizeof(aluno[0]));
	
	modifica_struct(&aluno[0]);
	print_aluno(aluno[0]);

	return 0;
}
