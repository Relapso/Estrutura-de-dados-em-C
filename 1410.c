#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

//usando TAD 

typedef struct {
    int distancia;
    int is_atacante;
} jogador;

int main() {
    int a, d, i, j;
    jogador *atacantes, *defensores;


    while (TRUE) {
        scanf("%d %d", &a, &d);

        if (a == 0 && d == 0) {
            break;
        }


        atacantes = (jogador *) malloc(a * sizeof(jogador));
        defensores = (jogador *) malloc(d * sizeof(jogador));


        for (i = 0; i < a; i++) {
            scanf("%d", &atacantes[i].distancia);
            atacantes[i].is_atacante = 1;
        }
      for (i = 0; i < d; i++) {
            scanf("%d", &defensores[i].distancia);
            defensores[i].is_atacante = 0;
        }

 
        for (i = 0; i < d - 1; i++) {
            for (j = i + 1; j < d; j++) {
                if (defensores[i].distancia > defensores[j].distancia) {
                    jogador temp = defensores[i];
                    defensores[i] = defensores[j];
                    defensores[j] = temp;
                }
            }
        }


        int impedido = 0;
        for (i = 0; i < a; i++) {
            if (atacantes[i].distancia < defensores[1].distancia) {
                impedido = 1;
                break;
            }
        }


        if (impedido) {
            printf("Y\n");
        } else {
            printf("N\n");
        }

        free(atacantes);
        free(defensores);
    }

    return 0;
}
