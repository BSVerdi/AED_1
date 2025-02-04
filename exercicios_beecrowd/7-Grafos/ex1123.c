#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

const int INF = INT_MAX;

typedef struct {
    int data[1010];
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


int dijkstra(int **grafo, int *custo, int cidades, int origem, int destino) {
    Queue fila;
    fila.size = 0;
    
    push(&fila ,origem);

    custo[origem] = 0;

    while (fila.size > 0) {
        int i = pop(&fila);

        for (int j = 0; j < cidades; j++) {
            if (grafo[i][j] != INF && custo[j] > custo[i] + grafo[i][j]) {
                custo[j] = custo[i] + grafo[i][j];
                push(&fila, j);
            }
        }
    }
    
    return custo[destino];
}


int main() {
    int cidades, estradas, cidades_rota, conserto;

    while (1) {
        scanf("%d %d %d %d", &cidades, &estradas, &cidades_rota, &conserto);

        if (!(cidades || estradas || cidades_rota || conserto)) break;

        int **grafo;
        int *custo;

        grafo = (int**)malloc(cidades * sizeof(int*));
        for (int i = 0; i < cidades; i++)
            grafo[i] = (int*)malloc(cidades * sizeof(int));

        custo = (int*)malloc(cidades * sizeof(int));

        infinito(grafo, custo, cidades);

        for (int i = 1; i <= estradas; i++) {
            int u, v, p;

            scanf("%d %d %d", &u, &v, &p);

            if (u >= cidades_rota && v >= cidades_rota) {
                grafo[u][v] = p;
                grafo[v][u] = p;
            }

            if (u >= cidades_rota && v < cidades_rota)
                grafo[u][v] = p;

            if (u < cidades_rota && v >= cidades_rota)
                grafo[v][u] = p;

            if (u < cidades_rota && v < cidades_rota && abs(u - v) == 1) {
                grafo[u][v] = p;
                grafo[v][u] = p;
            }
        }

        printf("%d\n", dijkstra(grafo, custo, cidades, conserto, cidades_rota -1));

        for (int i = 0; i < cidades; i++)
            free(grafo[i]);
        free(grafo);
        free(custo);
    }

    return 0;
}