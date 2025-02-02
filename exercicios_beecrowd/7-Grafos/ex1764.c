#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int menorDistancia(int dist[], int processado[], int cidades) {
    int min = INT_MAX, minIndex;

    for (int v=0; v< cidades; v++) {
        if (!processado[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}


int dijkstra(int **grafo, int origem, int cidades) {
    int dist[cidades];
    int processado[cidades];
    int soma = 0;

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
            if (!processado[v] && grafo[u][v] && dist[u] != INT_MAX && dist[u] + grafo[u][v] < dist[v])
                dist[v] = dist[u] + grafo[u][v];
        }
    } 

    // exibe as distancias
    for (int i = 0; i < cidades; i++)
        soma += dist[i];

    return soma;
}


int main() {
    int **grafo, cidades = 1, estradas = 1, i, j;
    int soma = INT_MAX;


    while (1) {
        // quantidade de cidades e estradas
        scanf("%d %d", &cidades, &estradas);

        if (!(cidades || estradas)) break;    

        grafo = (int**)malloc(sizeof(int*) * cidades);
        for (i=0; i<cidades; i++)
            grafo[i] = (int*)malloc(sizeof(int) * cidades);

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

        for (int i=0; i<cidades; i++) {
            int temp = dijkstra(grafo, i, cidades);

            if (temp < soma)
                soma = temp;
        }
        
        printf("soma = %d", soma);

        for (i = 0; i < cidades; i++)
            free(grafo[i]);
        free(grafo);
    }

    return 0;
}