#include<stdio.h>
#include<stdlib.h>

void dfs(int estacao, int *visitado, int grafo[100][100], int e) {
    visitado[estacao] = 1;

    for (int i = 0; i < e; i++) {
        if (grafo[estacao][i] && !visitado[i])
            dfs(i, visitado, grafo, e);
    }
}


int main() {
    int estacoes, linhas, caso = 1;

    while (1) {
        scanf("%d %d", &estacoes, &linhas);

        if (!(estacoes || linhas)) break;

        int grafo[100][100] = {0};
        int visitado[100] = {0};
        int normal = 1;

        for (int i = 0; i < linhas; i++) {
            int x, y;
            
            scanf("%d %d", &x, &y);

            grafo[x - 1][y - 1] = 1;
            grafo[y - 1][x - 1] = 1;
        }

        dfs(0, visitado, grafo, estacoes);

        for (int i = 0; i < estacoes; i++) {
            if (!visitado[i]) {
                normal = 0;
                break;
            }
        }

        printf("Teste %d\n", caso++);
        if (normal)
            printf("normal\n");
        else
            printf("falha\n");
        printf("\n");
    }

    return 0;
}