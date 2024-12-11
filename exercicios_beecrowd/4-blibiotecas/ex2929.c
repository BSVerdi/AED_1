#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int conteudo;
    int minimo;
    struct celula *seg;
    struct celula *ant;
} celula;


void push(celula **topo, int conteudo) {
    celula *nova = (celula*)malloc(sizeof(celula));
    nova->conteudo = conteudo;
    nova->seg = NULL;
    nova->ant = *topo;

    if (*topo == NULL)
        nova->minimo = conteudo;
    else if (conteudo < (*topo)->minimo)
        nova->minimo = conteudo;
    else
        nova->minimo = (*topo)->minimo;

    if (*topo != NULL)
        (*topo)->seg = nova;   
    *topo = nova;
}


void pop(celula **topo) {
    if (*topo == NULL) {
        printf("EMPTY\n");
    } else {
        celula *lixo;

        lixo = *topo;
        *topo = (*topo)->ant;
        (*topo)->seg == NULL;

        free(lixo);
    }
}


void min(celula *topo) {
    if (topo == NULL)
        printf("EMPTY\n");
    else {
        printf("%d\n", topo->minimo);
    }
}


int main() {
    celula *topo = NULL;
    char string[5];
    int ciclos, num;

    scanf("%d", &ciclos);

    for (int i=0; i<ciclos; i++) {
        scanf("%s", string);

        if (strcmp(string, "PUSH") == 0) {
            scanf("%d", &num);
            push(&topo, num);
        } else if (strcmp(string, "POP") == 0)
            pop(&topo);
        else if (strcmp(string, "MIN") == 0)
            min(topo);
    }

    return 0;
}