#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


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
    for (int i = 0; i < cidades; i++) {
        // escolhe o no com a menor distancia
        int u = -1;
        for (int j = 0; j < cidades; j++) {
            if (!visitado[j] && (u == -1 || distancia[j] < distancia[u]))
                u = j;
        }

        if (u == -1 || distancia[u] == INT_MAX) break;
        visitado[u] = 1; //marca o no como visitado;

        // atualiza a distancia dos nos adjacentes
        for (int v = 0; v < cidades; v++) {
            if (grafo[u][v] > 0) {
                if (u >= cidades_na_rota || v >= cidades_na_rota || v == u + 1) {
                    if (distancia[u] + grafo[u][v] < distancia[v]) {
                        distancia[v] = distancia[u] + grafo[u][v];
                    }
                }
            }
        }
    } 

    // exibe as distancia
    if (cidades_na_rota == 0)
        printf("%d\n", distancia[cidades_na_rota]);
    else
        printf("%d\n", distancia[cidades_na_rota - 1]);
}


int main() {
    int **grafo, cidades = 1, estradas = 1, cidades_na_rota = 1, conserto = 1, i, j;
    

    while (1) {
        // quantidade de cidades e estradas
        scanf("%d %d %d %d", &cidades, &estradas, &cidades_na_rota, &conserto);

        if (!(cidades || estradas || cidades_na_rota || conserto)) break;    

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

        dijkstra(grafo, conserto, cidades, cidades_na_rota);
        
        for (i = 0; i < cidades; i++)
            free(grafo[i]);
        free(grafo);
    }

    return 0;
}