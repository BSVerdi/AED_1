#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


int menorDistancia(int dist[], int processado[], int cidades) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < cidades; v++) {
        if (!processado[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}


void dijkstra(int **grafo, int origem, int cidades, int cidades_na_rota) {
    int dist[cidades];
    int processado[cidades];
    int valido = 1;

    // inicializa 
    for (int i = 0; i < cidades; i++) {
        dist[i] = INT_MAX;
        processado[i] = 0;
    }

    dist[origem] = 0;

    // processa todos os vertices
    for (int c = 0; c < (cidades - 1); c++) {
        // escolhe o no com a menor distancia
        int u = menorDistancia(dist, processado, cidades);

        processado[u] = 1; //marca o no como processado;

        // atualiza a distancia dos nos adjacentes
        for (int v = 0; v < cidades; v++) {
            if (!processado[v] && grafo[u][v] && dist[u] != INT_MAX && dist[u] + grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo[u][v];
            }
        }
    } 

    // exibe as distancias
    printf("Vertices \t Distancia da origem\n");
    for (int i = 0; i < cidades; i++)
        printf("%d \t\t %d \n", i, dist[i]);
}


int main() {
    int **grafo, cidades, estradas, cidades_na_rota, conserto, i, j;
    
    // quantidade de cidades e estradas
    scanf("%d %d %d %d", &cidades, &estradas, &cidades_na_rota, &conserto);

    grafo = (char**)malloc(sizeof(char*) * cidades);
    for (i=0; i<cidades; i++)
        grafo[i] = (char*)malloc(sizeof(char) * cidades);

    for (i=0; i<cidades; i++) {
        for(j=0; j<cidades; j++)
            grafo[i][j] = 0;
    }

    for (int k = 0; k < estradas; k++) {
        int temp;

        scanf("%d %d",&i, &j);
        scanf("%d", &temp);

        grafo[i][j] = temp;
        grafo[j][i] = temp;
    }

    dijkstra(grafo, 0, cidades, cidades_na_rota);

    return 0;
}