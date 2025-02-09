#include<stdio.h>
#include<stdlib.h>

void dfs(int **grafo, int vertices, int origem, int *visitado) {
    printf(" %d", origem);

    visitado[origem] = 1;

    for (int i = 0; i < vertices; i++) {
        if (grafo[origem][i] == 1 && !visitado[i])
            dfs(grafo, vertices, i, visitado);
    }
}


int main() {
    int vertices, arestas, **grafo, *visitado;
    
    scanf("%d %d", &vertices, &arestas);

    // inicializando
    visitado = (int*)malloc(vertices * sizeof(int));

    grafo = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        grafo[i] = (int*)malloc(vertices * sizeof(int));
        visitado[i] = 0;
    }

    for (int i = 0; i < arestas; i++) {
        int origem, destino;

        scanf("%d %d", &origem, &destino);

        grafo[origem][destino] = 1;
        grafo[destino][origem] = 1;
    }

    printf("Ordem da busca em profundidade:");
    dfs(grafo, vertices, 0, visitado);
    printf("\n");

    return 0;
}