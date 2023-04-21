#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int ra_aluno;
	char nome_aluno[20];
	int idade_aluno;
	float nota_media;
	
}Aluno;

int main(void) {
	Aluno *a;
	int tamanho;
	a = (Aluno *) malloc(sizeof(Aluno));
	
	printf("Ra do aluno\n");
	scanf("%d",&a->ra_aluno);     
	printf("Nome do aluno\n");
	fflush(stdin);
	fgets(a->nome_aluno,20,stdin);
	strtok(a->nome_aluno, "\n");
	printf("Idade aluno\n");
	scanf("%d", &a->idade_aluno);
	printf("Media aluno\n");
	scanf("%f", &a->nota_media);
	
	printf("=============\n");
	printf("Ra aluno:%d \t Endereco da memoria: %d \t Tamanho ocupado:%d bytes\n",a->ra_aluno, &a->ra_aluno, sizeof(a->ra_aluno));
	printf("Nome aluno:%s \t Endereço da memoria: %d \t Tamanho ocupado:%d bytes\n",a->nome_aluno,&a->nome_aluno, sizeof(a->nome_aluno));
	printf("Idade aluno:%d \t\t Endereço da memoria: %d \t Tamanho ocupado:%d bytes\n",a->idade_aluno, &a->idade_aluno, sizeof(a->idade_aluno));
	printf("Nota media:%.2f \t Endereço da memoria: %d \t Tamanho ocupado:%d bytes\n",a->nota_media, &a->nota_media, sizeof(a->nota_media));
	free(a);
}
