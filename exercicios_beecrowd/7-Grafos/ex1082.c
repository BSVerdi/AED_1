#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int adj[26][26];
    int vertices;
} Grafo;

int visitado[26];

void initGrafo(Grafo *grafo, int vertices) {
    grafo->vertices = vertices;
    memset(grafo->adj, 0, sizeof(grafo->adj));
    memset(visitado, 0, sizeof(visitado));
}


void addAresta(Grafo *grafo, char u, char v) {
    int i = u - 'a';
    int j = v - 'a';

    grafo->adj[i][j] = 1;
    grafo->adj[j][i] = 1;
}


void dfs(Grafo *grafo, int v, char *componente, int *indice) {
    visitado[v] = 1;
    componente[(*indice)++] = v + 'a';

    for (int i = 0; i < grafo->vertices; i++) {
        if (grafo->adj[v][i] && !visitado[i])
            dfs(grafo, i, componente, indice);
    }
}


int particionar(char *componente, int start, int end) {
    char pivo = componente[end];
    int i = (start - 1), j;
    char aux;

    for (j = start; j < end; j++) {
        if (strcmp(&componente[j], &pivo) == -1) {
            i++;
            aux = componente[i];
            componente[i] = componente[j];
            componente[j] = aux;
        }
    }

    aux = componente[i + 1];
    componente[i + 1] = componente[end];
    componente[end] = aux;

    return(i + 1);
}


void quickSort(char *componentes, int start, int end) {
    if (start < end) {
        int pivo = particionar(componentes, start, end);

        quickSort(componentes, start, pivo - 1);
        quickSort(componentes, pivo + 1, end);
    }
}


int main() {
    int cases;

    scanf("%d", &cases);

    for (int i = 1; i <= cases; i++) {
        int vertices, arestas, componentes = 0;
        Grafo grafo;

        scanf("%d %d", &vertices, &arestas);

        initGrafo(&grafo, vertices);

        for (int j = 0; j < arestas; j++) {
            char u, v;
            
            scanf(" %c %c", &u, &v);

            addAresta(&grafo, u, v);
        }

        printf("Case #%d:\n", i);

        for (int j = 0; j < vertices; j++) {
            if (!visitado[j]) {
                char componente[26];
                int indice = 0;

                dfs(&grafo, j, componente, &indice);

                quickSort(componente, 0, indice - 1);

                for (int k = 0; k < indice; k++)
                    printf("%c,", componente[k]);
                printf("\n");

                componentes++;
            }
        }

        printf("%d connected components\n\n", componentes);
    }

    return 0;
}