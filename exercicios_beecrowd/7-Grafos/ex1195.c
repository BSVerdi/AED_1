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


void preOrder(No *raiz) {
    if (raiz != NULL) {
        printf(" %d", raiz->data);
        preOrder(raiz->esquerda);
        preOrder(raiz->direita);
    }
}


void inOrder(No *raiz) {
    if (raiz != NULL) {
        inOrder(raiz->esquerda);
        
        printf(" %d", raiz->data);

        inOrder(raiz->direita);
    }
}


void postOrder(No *raiz) {
    if (raiz != NULL) {
        postOrder(raiz->esquerda);
        postOrder(raiz->direita);

        printf(" %d", raiz->data);
    }
}


int main() {
    int cases;

    scanf("%d", &cases);

    for (int i = 1; i <= cases; i++) {
        int size, num;
        No *raiz = NULL;

        scanf("%d", &size);

        for (int j = 0; j < size; j++) {
            scanf("%d", &num);
            raiz = inserir(raiz, num);
        }

        printf("Case %d:\n", i);

        printf("Pre.:");
        preOrder(raiz);
        printf("\n");

        printf("In..:");
        inOrder(raiz);
        printf("\n");

        printf("Post:");
        postOrder(raiz);
        printf("\n");

        printf("\n");
    }

    return 0;
}