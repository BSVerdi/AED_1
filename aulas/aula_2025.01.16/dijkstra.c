#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

const int INF = INT_MAX;

// aresta do grafo
typedef struct {
    int destino, peso;
} Aresta;

// grafo
typedef struct {
    Aresta **lista;
    int *size;
    int vertices;
} Grafo;


typedef struct {
    int *vertice;
    int *distancia;
    int *posicao;
    int size;
} HeapMin;


Grafo *criarGrafo(int vertices) {
    Grafo *grafo = (Grafo*)malloc(sizeof(Grafo));

    grafo->vertices = vertices;
    grafo->lista = (Aresta**)malloc(vertices * sizeof(Aresta*));
    grafo->size = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        grafo->lista[i] = NULL;
        grafo->size[i] = 0;
    }

    return grafo;
}


void adicionarAresta(Grafo *grafo, int origem, int destino, int peso) {
    grafo->lista[origem] = (Aresta*)realloc(grafo->lista[origem], (grafo->size[origem] + 1) * sizeof(Aresta));
    
    grafo->lista[origem][grafo->size[origem]] = (Aresta){destino, peso};
    grafo->size[origem]++;

    grafo->lista[destino] = (Aresta*)realloc(grafo->lista[destino], (grafo->size[destino] + 1) * sizeof(Aresta));
    
    grafo->lista[destino][grafo->size[destino]] = (Aresta){origem, peso};
    grafo->size[destino]++;
}


HeapMin *criarHeapMin(int vertices) {
    HeapMin *heapmin = (HeapMin*)malloc(sizeof(HeapMin));

    heapmin->vertice = (int*)malloc(vertices * sizeof(int));
    heapmin->distancia = (int*)malloc(vertices * sizeof(int));
    heapmin->posicao = (int*)malloc(vertices * sizeof(int));
    heapmin->size = vertices;

    for (int i = 0; i < vertices; i++) {
        heapmin->vertice[i] = i;
        heapmin->distancia[i] = INF;
        heapmin->posicao[i] = i;
    }

    return heapmin;
}


void swapHeapNode(HeapMin *heapmin, int i, int j) {
    int temp_vertice = heapmin->vertice[i];
    int temp_dist = heapmin->distancia[i];

    heapmin->vertice[i] = heapmin->vertice[j];
    heapmin->distancia[i] = heapmin->distancia[j];

    heapmin->vertice[j] = temp_vertice;
    heapmin->distancia[j] = temp_dist;

    heapmin->posicao[heapmin->vertice[i]] = i;
    heapmin->posicao[heapmin->vertice[j]] = j;
}


void heapMinfy(HeapMin* heapmin, int index) {
    int min = index, esq = 2 * index + 1, dir = 2 * index + 2;

    if (esq < heapmin->size && heapmin->distancia[esq] < heapmin->distancia[min])
        min = esq;

    if (dir < heapmin->size && heapmin->distancia[dir] < heapmin->distancia[min])
        min = dir;

    if (min != index) {
        swapHeapNode(heapmin, index, min);
        heapMinfy(heapmin, min);
    }
}


int popHeap(HeapMin *heapmin) {
    if (heapmin->size == 0)
        return -1;

    int root = heapmin->vertice[0];
    heapmin->vertice[0] = heapmin->vertice[heapmin->size - 1];
    heapmin->distancia[0] = heapmin->distancia[heapmin->size - 1];

    heapmin->posicao[heapmin->vertice[0]] = 0;
    heapmin->size--;

    heapMinfy(heapmin, 0);

    return root;
}


void changeDistance(HeapMin *heapmin, int vertice, int distancia) {
    int i = heapmin->posicao[vertice];
    heapmin->distancia[i] = distancia;

    while (i > 0 && heapmin->distancia[i] < heapmin->distancia[(i - 1) / 2]) {
        swapHeapNode(heapmin, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}


int findHeap(HeapMin *heapmin, int vertice) {
    return heapmin->posicao[vertice] < heapmin->size;
}


void dijkstra(Grafo *grafo, int origem) {
    int vertices = grafo->vertices;
    int dist[vertices];

    HeapMin *heapmin = criarHeapMin(vertices);
    dist[origem] = 0;
    changeDistance(heapmin, origem, 0);

    while (heapmin->size > 0) {
        int u = popHeap(heapmin);

        for (int i = 0; i < grafo->size[u]; i++) {
            int destino = grafo->lista[u][i].destino;
            int peso = grafo->lista[u][i].peso;

            if (findHeap(heapmin, destino) && dist[u] != INF && dist[u] + peso < dist[destino]) {
                dist[destino] = dist[u] + peso;
                changeDistance(heapmin, destino, dist[destino]);
            }
        }
    }

    printf("Vertice\tDistancia da origem\n");
    for (int i = 0; i < vertices; i++)
        printf("%d\t%d\n", i, dist[i]);

    free(heapmin->vertice);
    free(heapmin->distancia);
    free(heapmin->posicao);
    free(heapmin);
}


int main() {
    int vertices = 6;
    Grafo *grafo = criarGrafo(vertices);

    adicionarAresta(grafo, 0, 1, 350);
    adicionarAresta(grafo, 1, 2, 180);
    adicionarAresta(grafo, 0, 3, 270);
    adicionarAresta(grafo, 3, 4, 200);
    adicionarAresta(grafo, 4, 5, 300);
    adicionarAresta(grafo, 1, 4, 190);
    adicionarAresta(grafo, 3, 5, 500);
    adicionarAresta(grafo, 2, 5, 400);

    dijkstra(grafo, 0);

    return 0;
}
