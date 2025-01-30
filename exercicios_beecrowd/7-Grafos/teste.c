#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 250
#define INF INT_MAX

typedef struct {
    int destino, custo;
} Aresta;

typedef struct {
    Aresta arestas[MAX_N];
    int tamanho;
} ListaAdj;

ListaAdj grafo[MAX_N];
int distancia[MAX_N];
int visitado[MAX_N];

void adicionarAresta(int u, int v, int p) {
    grafo[u].arestas[grafo[u].tamanho].destino = v;
    grafo[u].arestas[grafo[u].tamanho].custo = p;
    grafo[u].tamanho++;
    
    grafo[v].arestas[grafo[v].tamanho].destino = u;
    grafo[v].arestas[grafo[v].tamanho].custo = p;
    grafo[v].tamanho++;
}

void dijkstra(int N, int C, int K) {
    for (int i = 0; i < N; i++) {
        distancia[i] = INF;
        visitado[i] = 0;
    }
    distancia[K] = 0;
    
    for (int i = 0; i < N; i++) {
        int u = -1;
        for (int j = 0; j < N; j++) {
            if (!visitado[j] && (u == -1 || distancia[j] < distancia[u])) {
                u = j;
            }
        }
        
        if (distancia[u] == INF) break;
        visitado[u] = 1;
        
        for (int j = 0; j < grafo[u].tamanho; j++) {
            int v = grafo[u].arestas[j].destino;
            int peso = grafo[u].arestas[j].custo;
            
            if (u >= C || v >= C || v == u + 1) {
                if (distancia[u] + peso < distancia[v]) {
                    distancia[v] = distancia[u] + peso;
                }
            }
        }
    }
    printf("%d\n", distancia[C - 1]);
}

int main() {
    int N, M, C, K;
    while (scanf("%d %d %d %d", &N, &M, &C, &K) == 4 && (N || M || C || K)) {
        for (int i = 0; i < N; i++) {
            grafo[i].tamanho = 0;
        }
        
        for (int i = 0; i < M; i++) {
            int U, V, P;
            scanf("%d %d %d", &U, &V, &P);
            adicionarAresta(U, V, P);
        }
        
        dijkstra(N, C, K);
    }
    return 0;
}
