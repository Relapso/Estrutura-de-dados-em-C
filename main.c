	#include <stdio.h>
	#include <stdlib.h>
	#define TAM 5
	
	typedef struct {
		int ra_aluno;
		char nome_aluno[20];
		int idade_aluno;
		float nota_media;
		
	}Aluno;
	
	int main(void) {
		Aluno *a;
		a = (Aluno *) malloc (TAM*sizeof(Aluno));
		int i;
		for(i = 0; i<TAM; i++){
			
		printf("Ra do aluno[%d]\n",i+1);
		scanf("%d",&a[i].ra_aluno);   
		while(getchar() != '\n');
		printf("Nome do aluno[%d]\n",i+1);
		fgets(a[i].nome_aluno,20,stdin);
		printf("Idade aluno[%d]\n",i+1);
		scanf("%d", &a[i].idade_aluno);
		
		printf("Media aluno[%d]\n",i+1);
		scanf("%f", &a[i].nota_media);	
		
		printf("=============\n");
		}

		for(i=0; i<TAM;i++){
		printf("Ra aluno:%d Endereco da memoria: %d Tamanho ocupado:%d bytes\n",a[i].ra_aluno, &a[i].ra_aluno, sizeof(a[i].ra_aluno));
		printf("Nome aluno:%s \t Endereço da memoria: %d \t Tamanho ocupado:%d bytes\n",a[i].nome_aluno,&a[i].nome_aluno, sizeof(a[i].nome_aluno));
		printf("Idade aluno:%d Endereço da memoria: %d   Tamanho ocupado:%d bytes\n",a[i].idade_aluno, &a[i].idade_aluno, sizeof(a[i].idade_aluno));
		printf("Nota media:%.2f Endereço da memoria: %d   Tamanho ocupado:%d bytes\n",a[i].nota_media, &a[i].nota_media, sizeof(a[i].nota_media));
		printf("\n");
		}
		free(a);
		return 0;
	}
