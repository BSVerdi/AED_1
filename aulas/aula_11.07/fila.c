/*
    Filas(FiFo)
        FiFo = First in First out
        Ou seja o primeiro elemento que entrou na fila é o primeiro a sair.
    inserir = PUSH
    tirar = POP
    Aqui irei implementar as filas em uma lista encadeada
*/
#include<stdio.h>
#include<stdlib.h>


typedef struct {
    int conteudo;
    struct celula *seg;
} celula;

// função para remover elemento
int pop(celula **primeiro, celula **ultimo) {
    celula *aux;
    int valor;

    aux = *primeiro;
    valor = aux->conteudo;
    *primeiro = aux->seg;

    free(aux);

    if (*primeiro == NULL)
        *ultimo = NULL;

    return valor;
}

// função para adicionar elementos
void push(celula **ultimo, celula **primeiro, int conteudo) {
    celula *nova = (celula*)malloc(sizeof(celula));
    nova->conteudo = conteudo;
    nova->seg = NULL;

    if (*ultimo == NULL) 
        *ultimo = *primeiro = nova;
    else {
        (*ultimo)->seg = nova;
        *ultimo = nova;
    }  
}

//função para imprimir a fila
void printFila(celula **primeiro) {
    celula *aux;
    for (aux = *primeiro; aux != NULL; aux = aux->seg)
        printf("%d -> ", aux->conteudo);
}


int main() {
    celula *ultimo = NULL, *primeiro;
    int ciclos = 10, choice, num;

    while (ciclos > 0) {
        printf("\n(0) POP ou (1 PUSH)\n");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Valor retirado: %d\n", pop(&primeiro, &ultimo));
        } else if (choice == 1) {
            printf("PUSH: ");
            scanf("%d", &num);
            push(&ultimo, &primeiro, num);
        }

        printFila(&primeiro);
        ciclos--;
    }

    return 0;
}