#include<stdio.h>
#include<limits.h>

#define VERTICES 5

int menorDistancia(int dist[], int processado[]) {
    int min = INT_MAX, minIndex;

    for (int v=0; v< VERTICES; v++) {
        if (!processado[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}


void dijkstra(int grafo[VERTICES][VERTICES], int origem) {
    int dist[VERTICES];
    int processado[VERTICES];

    // inicializa 
    for (int i = 0; i < VERTICES; i++) {
        dist[i] = INT_MAX;
        processado[i] = 0;
    }

    dist[origem] = 0;

    // processa todos os vertices
    for (int c = 0; c < (VERTICES - 1); c++) {
        // escolhe o no com a menor distancia
        int u = menorDistancia(dist, processado);

        processado[u] = 1; //marca o no como processado;

        // atualiza a distancia dos nos adjacentes
        for (int v = 0; v < VERTICES; v++) {
            if (!processado[v] && grafo[u][v] && dist[u] != INT_MAX && dist[u] + grafo[u][v] < dist[v])
                dist[v] = dist[u] + grafo[u][v];
        }
    } 

    // exibe as distancias
    printf("Vertices \t Distancia da origem\n");
    for (int i = 0; i < VERTICES; i++)
        printf("%d \t\t %d \n", i, dist[i]);
}


int main() {
    // representçao do grafo como matriz de adjacencia
    int grafo[5][5] = {
        {0, 10, 5, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 3, 0, 9, 2},
        {0, 0, 0, 0, 4},
        {7, 0, 0, 6, 0},
    };

    dijkstra(grafo, 0);

    return 0;
}