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
        raiz->esquerda = inserir(raiz->esquerda,data);
    else
        raiz->direita = inserir(raiz->direita, data);

    return raiz;
}


No *buscar(No *raiz, int data) {
    if (raiz != NULL) {
        if (data == raiz->data)
            return raiz;

        if (data < raiz->data)
            return buscar(raiz->esquerda, data);
        else
            return buscar(raiz->direita, data);
    }

    return NULL;
}


void printArvore(No *raiz) {
    if (raiz != NULL) {
        printArvore(raiz->esquerda);

        printf(" -> %d", raiz->data);

        printArvore(raiz->direita);
    }
}


int main() {
    No *raiz = NULL;

    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 3);

    printArvore(raiz);

    No *temp = buscar(raiz, 3);
    
    if (temp != NULL) {
        printf("\n%d Encontrado\n", temp->data);
        
        No *aux = temp->esquerda;
        printf("Filho esquerdo: %d\n", aux->data);

        aux = temp->direita;
        printf("Filho Direito: %d\n", aux->data);
    } else {
        printf("Valor nao foi encontrado!");
    }

    return 0;
}