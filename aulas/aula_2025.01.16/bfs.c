#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct {
    int *data;
    int size;
} Queue;

const int INF = INT_MAX;

void push(Queue *fila, int data) {
    fila->data[fila->size++] = data;
}


int pop(Queue *fila) {
    int temp = fila->data[0];

    for (int i = 0; i < fila->size - 1; i++)
        fila->data[i] = fila->data[i + 1];

    fila->size--;

    return temp;
}


void bfs(int **grafo, int vertices, int origem) {
    int visitado[vertices];
    Queue fila;
    
    fila.size = 0;
    fila.data = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++)
        visitado[i] = 0;
    visitado[origem] = 1;

    push(&fila, origem);
    
    printf("Ordem da busca em largura:");

    while (fila.size > 0) {
        int i = pop(&fila);
        printf(" %d", i);

        for (int j = 0; j < vertices; j++) {
            if (grafo[i][j] == 1 && !visitado[j]) {
                visitado[j] = 1;
                push(&fila, j);
            }
        }
    }

    printf("\n");
}


int main() {
    int vertices, arestas, **grafo;

    scanf("%d %d", &vertices, &arestas);

    grafo = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++)
        grafo[i] = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < arestas; i++) {
        int origem, destino;

        scanf("%d %d", &origem, &destino);

        grafo[origem][destino] = 1;
    }

    bfs(grafo, vertices, 0);

    return 0;
}