#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data;
    struct No *esquerda;
    struct No *direita;
} No;


No *novoNo(int data) {
    No *novo = (No*)malloc(sizeof(No));

    novo->data = data;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}


No *inserir(No *raiz, int data) {
    if (raiz == NULL)
        return novoNo(data);
    
    if (data < raiz->data)
        raiz->esquerda = inserir(raiz->esquerda, data);
    else
        raiz->direita = inserir(raiz->direita, data);

    return raiz;
}


void bfs(No *raiz) {
    if (raiz == NULL)
        return;

    int start = 0, end = 0, first = 1;
    No *fila[500];

    fila[end++] = raiz;

    while (start < end) {
        No *atual = fila[start++];

        if (!first)
            printf(" ");
        printf("%d", atual->data);
        first = 0;

        if (atual->esquerda != NULL)
            fila[end++] = atual->esquerda;

        if (atual->direita != NULL)
            fila[end++] = atual->direita;

    }
}


int main() {
    int cases;

    scanf("%d", &cases);

    for (int i = 1; i <= cases; i++) {
        int numbers;

        scanf("%d", &numbers);

        No *raiz = NULL;

        for (int i = 0; i < numbers; i++) {
            int data;

            scanf("%d", &data);

            raiz = inserir(raiz, data);
        }

        printf("Case %d:\n", i);
        bfs(raiz);
        printf("\n\n");
    }

    return 0;
}