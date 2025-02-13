#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

const int INF = INT_MAX;

int menorPeso(int *peso, int *visitado, int vertices) {
    int min = INF, min_index;

    for (int i = 0; i < vertices; i++) {
        if (!visitado[i] && peso[i] < min) {
            min = peso[i];
            min_index = i;
        }
    }

    return min_index;
}


void printMST(int *parent, int **grafo, int vertices) {
    printf("Aresta \t peso\n");
    for (int i = 1; i < vertices; i++)
        printf("%d - %d \t %d\n", parent[i], i, grafo[i][parent[i]]);
}


void prim(int **grafo, int vertices) {
    int parent[vertices];
    int peso[vertices];
    int visitado[vertices];

    for (int i = 0; i < vertices; i++) {
        peso[i] = INF;
        visitado[i] = 0;
    }

    peso[0] = 0;
    parent[0] = -1;
    
    for (int i = 0; i < vertices - 1; i++) {
        int u = menorPeso(peso, visitado, vertices);
        visitado[u] = 1;

        for (int j = 0; j < vertices; j++) {
            if (grafo[u][j] != INF && !visitado[j] && grafo[u][j] < peso[j]) {
                parent[j] = u;
                peso[j] = grafo[u][j];
            }
        }
    }

    printMST(parent, grafo, vertices);
}


int main() {
    int vertices, arestas;
    int **grafo;
    
    scanf("%d %d", &vertices, &arestas);

    grafo = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        grafo[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++)
            grafo[i][j] = INF;
    }

    for (int i = 0; i < arestas; i++) {
        int origem, destino, peso;

        scanf("%d %d %d", &origem, &destino, &peso);

        grafo[origem][destino] = peso;
        grafo[destino][origem] = peso;
    }

    prim(grafo, vertices);

    return 0;
}
