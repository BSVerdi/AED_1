#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int origem, destino, peso;
} Aresta;

int parent[40000], rank[40000];


int comparar(const void *a, const void *b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}


int encontrar(int vertice) {
    if (parent[vertice] != vertice)
        parent[vertice] = encontrar(parent[vertice]);
    return parent[vertice];
}


void unir(int a, int b) {
    int raiz_A = encontrar(a);
    int raiz_B = encontrar(b);

    if (raiz_A != raiz_B) {
        if (rank[raiz_A] < rank[raiz_B])
            parent[raiz_A] = raiz_B;
        else if (rank[raiz_A] > rank[raiz_B])
            parent[raiz_B] = raiz_A;
        else {
            parent[raiz_B] = raiz_A;
            rank[raiz_A]++;
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


int kruskal(int cidades, int estradas, Aresta *arestas) {
    int i, total = 0, num_aresta = 0;

    for (int i = 0; i < cidades; i ++) {
        parent[i] = i;
        rank[i] = 0;
    }

    quickSort(arestas, 0, estradas - 1);

    for (i = 0; (i < estradas && num_aresta < cidades); i++) {
        int u = arestas[i].origem;
        int v = arestas[i].destino;

        if (encontrar(u) != encontrar(v)) {
            unir(u, v);
            total += arestas[i].peso;
            num_aresta++;
        }
    }

    return total;
}


int main() {
    int cidades, estradas, i;
    Aresta *arestas;

    while(1) {
        scanf("%d %d", &cidades, &estradas);

        if (!(cidades || estradas)) break;

        arestas = (Aresta*)malloc(estradas * sizeof(Aresta));

        for (i = 0; i < estradas; i++)
            scanf("%d %d %d", &arestas[i].origem, &arestas[i].destino, &arestas[i].peso);

        printf("%d\n", kruskal(cidades, estradas, arestas));

        free(arestas);
    }

    return 0;
}