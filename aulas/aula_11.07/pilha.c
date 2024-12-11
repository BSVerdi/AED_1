#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data;
    struct celula *seg;
} celula;


int isEmpty(celula *topo) {
    return topo == NULL;
}


void push(celula **topo, int conteudo) {
    celula *nova = (celula*)malloc(sizeof(celula));
    nova->data = conteudo;
    nova->seg = *topo;
    *topo = nova;
}


int pop(celula **topo) {
    if (isEmpty(*topo)) {
        printf("Pilha vazia");
        return -1;
    }
    celula *lixo = *topo;
    int conteudo = lixo->data;

    *topo = lixo->seg;
    free(topo);

    return conteudo;
}


int top(celula *topo) {
    if (isEmpty(topo)) {
        printf("Pilha vazia");
        return -1;
    }
    return topo->data;
}
 

void printPilha(celula *topo) {
    if (isEmpty(topo)) {
        printf("Pilha Vazia");
        return;
    }

    celula *aux = topo;
    while (aux) {
        printf("%d -> ", aux->data);
        aux = aux->seg;
    }
}


int main() {
    celula *topo = NULL;
    int ciclos = 10, choice, num;

    while (ciclos > 0) {
        printf("\n(0) POP ou (1 PUSH)\n");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Valor retirado: %d\n", pop(&topo));
        } else if (choice == 1) {
            printf("PUSH: ");
            scanf("%d", &num);
            push(&topo, num);
        }

        printPilha(topo);
        ciclos--;
    }

    return 0;
}