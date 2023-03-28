/*
BEEID: 639677
NOME / RA:	Vinicius Fernandes 113063
//
PROBLEMA: 	1259 - Pares e Ímpares
RESPOSTA:	Accepted
LINGUAGEM: 	C++17 (g++ 7.3.0, -std=c++17 -O2 -lm) [+0s]
TEMPO:	0.244s
TAMANHO:    1,15 KB
MEMÓRIA:	-
SUBMISSÃO:	27/03/2023 14:10:20 
*/

#include <stdio.h>
#include <iostream>
using namespace std;

void quicksort(int *vet, int esq, int dir) {
    int i = esq;
    int j = dir;
    int pivo = vet[(esq + dir) / 2];
    int temp;

    while (i <= j) {
        while (vet[i] < pivo && i < dir) i++;
        while (vet[j] > pivo && j >= esq) j--;
        if (i <= j) {
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
            i++;
            j--;
        }
    }

    if (j >= esq) quicksort(vet, esq, j);
    if (i <= dir) quicksort(vet, i, dir);
}

int main() {
    int qtd, i, num, par = 0, impar = 0;
    scanf("%d", &qtd);

    int nump[qtd];
    int numi[qtd];

    for (i = 0; i < qtd; i++) {
        scanf("%d", &num);
        if (num % 2 == 0) {
            nump[par] = num;
            par++;
        } else {
            numi[impar] = num;
            impar++;
        }
    }

    quicksort(nump, 0, par - 1);
    quicksort(numi, 0, impar - 1);

    for (i = 0; i < par; i++) {
        printf("%d\n", nump[i]);
    }

    for (i = impar - 1; i >= 0; i--) {
        printf("%d\n", numi[i]);
    }

    return 0;
}