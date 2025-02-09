#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

const int INF = INT_MAX;

typedef struct {
    int *data;
    int size;
} Queue;


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


void infinito(int **grafo, int *custo, int cidades) {
    for (int i = 0; i < cidades; i++) {
        custo[i] = INF;
        for (int j = 0; j < cidades; j++)
            grafo[i][j] = INF;
    }
}


void dijkstra(int **grafo, int *custo, int vertices, int origem) {
    Queue fila;

    fila.data = (int*)malloc(vertices * sizeof(int));
    fila.size = 0;

    push(&fila, origem);

    custo[origem] = 0;

    while (fila.size > 0) {
        int i = pop(&fila);

        for (int j = 0; j < vertices; j++) {
            if (grafo[i][j] != INF && custo[j] > custo[i] + grafo[i][j]) {
                custo[j] = custo[i] + grafo[i][j];
                push(&fila, j);
            }
        }
    }
    printf("Vertice\tDistancia da origem\n");
    for (int i = 0; i < vertices; i++)
        printf("%d\t%d\n", i, custo[i]);
}


int main() {
    int vertices, arestas, **grafo, *custo;

    scanf("%d %d", &vertices, &arestas);

    grafo = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) 
        grafo[i] = (int*)malloc(vertices * sizeof(int));

    custo = (int*)malloc(vertices * sizeof(int));

    infinito(grafo, custo, vertices);

    for (int i = 0; i < arestas; i++) {
        int origem, destino, custo;

        scanf("%d %d %d", &origem, &destino, &custo);

        grafo[origem][destino] = custo;
    }

    dijkstra(grafo, custo, vertices, 0);

    return 0;
}