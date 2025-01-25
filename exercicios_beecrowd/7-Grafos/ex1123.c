#include<stdio.h>
#include<stdlib.h>

void printMatriz(int **matriz, int size) {
    int i, j;

    for (i=0; i<size; i++) {
        for (j=0; j<size; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

int main() {
    int **matriz_adj, cidades, estradas, i, j;
    
    // quantidade de cidades e estradas
    scanf("%d %d", &cidades, &estradas);

    matriz_adj = (char**)malloc(sizeof(char*) * cidades);
    for (i=0; i<cidades; i++)
        matriz_adj[i] = (char*)malloc(sizeof(char) * cidades);

    for (i=0; i<cidades; i++) {
        for(j=0; j<cidades; j++)
            matriz_adj[i][j] = 0;
    }

    for (int k=0; k<estradas; k++) {
        int temp;

        scanf("%d %d",&i, &j);
        scanf("%d", &temp);

        matriz_adj[i][j] = temp;
        matriz_adj[j][i] = temp;
    }
    
    printMatriz(matriz_adj, cidades);

    return 0;
}