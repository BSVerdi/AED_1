#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char nome[1000];
    char logo[15];
    char tamanho;
} Array;


void printArray(Array *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%s %c %s\n", array[i].logo, array[i].tamanho, array[i].nome);
}


int tamanhoCompare(char tamanho) {
    char sizes[3] = {'P', 'M', 'G'};

    for (int i = 0; i < 3; i++)
        if (sizes[i] == tamanho)
            return i;

    return -1;
}


void ordenar_camisetas(Array camisetas[], int n) {
    Array temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Ordenação por cor (vermelho primeiro, depois branco)
            if (strcmp(camisetas[i].logo, camisetas[j].logo) > 0 ||
                (strcmp(camisetas[i].logo, camisetas[j].logo) == 0 && camisetas[i].tamanho < camisetas[j].tamanho) ||
                (strcmp(camisetas[i].logo, camisetas[j].logo) == 0 && camisetas[i].tamanho == camisetas[j].tamanho && strcmp(camisetas[i].nome, camisetas[j].nome) > 0)) {
                temp = camisetas[i];
                camisetas[i] = camisetas[j];
                camisetas[j] = temp;
            }
        }
    }
}


int main() {
    int alunos, steps = 0;

    while (1) {
        Array *camisas;

        scanf("%d", &alunos);
        getchar();

        if (!alunos) break;

        camisas = (Array*)malloc(alunos * sizeof(Array));

        for (int j = 0; j < alunos; j++) { 
            scanf("%[^\n] %s %c", camisas[j].nome, camisas[j].logo, &camisas[j].tamanho);
            getchar();
        }

        ordenar_camisetas(camisas, alunos);

        if (steps > 0) printf("\n");

        printArray(camisas, alunos);
        steps++;

        free(camisas);
    }

    return 0;
}