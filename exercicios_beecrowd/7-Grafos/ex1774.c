#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int origem, destino, peso;
} Aresta;


int comparar(const void *a, const void *b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}


int encontar(int *parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = encontar(parent, parent[i]);
}


void unir(int *parent, int *rank, int a, int b) {
    int raiz_a = encontar(parent, a);
    int raiz_b = encontar(parent, b);

    if (raiz_a != raiz_b) {
        if (rank[raiz_a] > rank[raiz_b]) {
            parent[raiz_b] = raiz_a;
        } else if (rank[raiz_a] < rank[raiz_b]) {
            parent[raiz_a] = raiz_b;
        } else {
            parent[raiz_b] = raiz_a;
            rank[raiz_a]++;
        }
    }
}


int particionar(Aresta *array, int start, int end) {
    int pivo = array[end].peso;
    int i = (start - 1), j;
    Aresta aux;

    for (j = start; j < end; j++) {
        if (array[j].peso <= pivo) {
            i++;
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
        }
    }

    aux = array[i + 1];
    array[i + 1] = array[end];
    array[end] = aux;

    return(i + 1);
}


void quickSort(Aresta *array, int start, int end) {
    if (start < end) {
        int pivo = particionar(array, start, end);

        quickSort(array, start, pivo - 1);
        quickSort(array, pivo + 1, end);
    }
}


int main() {
    int R, C, arestas_usadas = 0, total = 0;

    scanf("%d %d", &R, &C);

    Aresta arestas[C];
    int parent[R], rank[R];

    for (int i = 0; i < C; i++) {
        int origem, destino, peso;

        scanf("%d %d %d", &origem, &destino, &peso);

        arestas[i].origem = origem - 1; 
        arestas[i].destino = destino - 1; 
        arestas[i].peso = peso; 
    }

    quickSort(arestas, 0, C - 1);

    for (int i = 0; i < R; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    for (int i = 0; i < C && arestas_usadas < R - 1; i++) {
        int origem = arestas[i].origem;
        int destino = arestas[i].destino;
        int peso = arestas[i].peso;
        
        if (encontar(parent, origem) != encontar(parent, destino)) {
            unir(parent, rank, origem, destino);
            total += peso;
            arestas_usadas++;
        }
    }

    printf("%d\n", total);

    return 0;
}