#include<stdio.h>

void listaADJ(int **grafo, int vertices) {
    for (int i = 0; i < vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < vertices; j++) {
            if (grafo[i][j] != 0) {
                printf("%d -> ", j);
            }
        }
        printf("\\\n");
    }
}


int main() {
    int grafo[6][6];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++)
            grafo[i][j] = 0;
    }

    for (int i = 0; i < 10; i++) {
        int origem, destino;

        scanf("%d %d", &origem, &destino);

        grafo[origem][destino] = 1;
    }

    listaADJ(grafo, 6);
    
    return 0;
}