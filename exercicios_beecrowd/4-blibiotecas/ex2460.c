#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int conteudo;
    struct celula *seg;
} celula;


void append(celula *lista, celula **ultimo, int conteudo) {
    celula *nova = (celula*)malloc(sizeof(celula));
    
    nova->conteudo = conteudo;
    nova->seg = NULL;

    (*ultimo)->seg = nova;
    *ultimo = nova;
}


void buscaRemocao(celula *lista, int conteudo) {
    celula *atual, *proxima;

    atual = lista;
    proxima = lista->seg;

    while (atual->seg != NULL && proxima->conteudo != conteudo) {
        atual = proxima;
        proxima = proxima->seg;
    }

    if (atual->seg != NULL && proxima->conteudo == conteudo) {
        atual->seg = proxima ->seg;
        free(proxima);
    }
}


void printLista(celula *lista) {
    celula *aux;
    for (aux = lista->seg; aux != NULL; aux = aux->seg)
        printf("%d ", aux->conteudo); 
}


int main() {
    celula *lista, *ultimo;
    int num, ciclos;

    lista = (celula*)malloc(sizeof(celula));
    lista->seg = NULL;

    ultimo = lista;

    scanf("%d", &ciclos);
    
    for (int i=0; i<ciclos; i++) {
        scanf("%d", &num);
        append(lista, &ultimo,num);
    }

    scanf("%d", &ciclos);

    for (int i=0; i<ciclos; i++) {
        scanf("%d", &num);
        buscaRemocao(lista, num);
    }

    printLista(lista);

    return 0;
}