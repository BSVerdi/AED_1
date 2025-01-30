#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


int menorDistancia(int dist[], int visitado[], int cidades) {
    int minIndex = -1;

    for (int v = 0; v < cidades; v++) {
        if (!visitado[v] && (minIndex == -1 || dist[v] < dist[minIndex])) {
            minIndex = v;
        }
    }

    return minIndex;
}


void dijkstra(int **grafo, int origem, int cidades, int cidades_na_rota) {
    int distancia[cidades];
    int visitado[cidades];

    // inicializa 
    for (int i = 0; i < cidades; i++) {
        distancia[i] = INT_MAX;
        visitado[i] = 0;
    }

    distancia[origem] = 0;

    // processa todos os vertices
    for (int c = 0; c < (cidades - 1); c++) {
        // escolhe o no com a menor distancia
        int u = menorDistancia(distancia, visitado, cidades);

        if (distancia[u] == INT_MAX) break;
        visitado[u] = 1; //marca o no como visitado;

        // atualiza a distancia dos nos adjacentes
        for (int v = 0; v < cidades; v++) {
            if (u >= cidades_na_rota || (v >= cidades_na_rota && grafo[u][v]) || v == u + 1) {
                if (!visitado[v] && distancia[u] + grafo[u][v] < distancia[v]) {
                    distancia[v] = distancia[u] + grafo[u][v];
                }
            }
        }
    } 

    // exibe as distancias
    printf("Vertices \t Distancia da origem\n");
    for (int i = 0; i < cidades; i++)
        printf("%d \t\t %d \n", i, distancia[i]);
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