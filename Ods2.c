#include <stdio.h>
#include <stdlib.h>


#define QDEESTADOS 27


typedef struct _mort{
    char  estado[3];
    float mortes09;
    float mortes15;
    float indice;
} mortMaterna;


void shellSort(mortMaterna *vet, int n){
    int i, j, k;
    mortMaterna temp;


    for (k = n/2; k > 0; k /= 2){
        for (i = k; i < n; i++){
            temp = vet[i];
            for (j = i; j >= k && vet[j-k].indice > temp.indice; j -= k)
                vet[j] = vet[j-k];
            vet[j] = temp;
        }
    }
}


int main(){
    mortMaterna estados[QDEESTADOS];
    int i;


    for(i=0; i < QDEESTADOS; i++){
        scanf("%s %f %f", estados[i].estado, &estados[i].mortes09, &estados[i].mortes15);
        estados[i].indice = estados[i].mortes15 - estados[i].mortes09;
    }


    printf("\nDados em ordem de entrada\n");
    printf("Estado\t2009\t2015\tDiferenca\n");    
    for(i=0; i<QDEESTADOS; i++)
        printf("%s\t%.1f\t%.1f\t%.1f\n",estados[i].estado, estados[i].mortes09, estados[i].mortes15, estados[i].indice);


    shellSort(estados, QDEESTADOS);


    printf("\nDados ordenados por mortalidade em 2015\n");
    printf("Estado\t2009\t2015\tDiferenca\n");    
    for(i=0; i<QDEESTADOS; i++)
        printf("%s\t%.1f\t%.1f\t%.1f\n",estados[i].estado, estados[i].mortes09, estados[i].mortes15, estados[i].indice);


    return 0;
}
