#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int conteudo;
    struct celula *seg;
} celula;


void imprima(celula *lista) {
    celula *p;
    for (p = lista->seg; p != NULL; p = p->seg)
        printf("%d\n", p->conteudo);
}


void inserir(int num, celula *p) {
    celula *aux;
    
    for (aux = p; aux->seg != NULL; aux = aux->seg);

    celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = num;
    nova->seg = aux->seg;
    aux->seg = nova;
}


int main() {
    int num;
    celula *lista;

    lista = malloc(sizeof(celula));
    lista->seg = NULL;

    for (int i=0; i<5; i++) {
        scanf("%d", &num);
        inserir(num, lista);
    }

    imprima(lista);

    return 0;
}