#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data;
    struct celula *seg;
} celula;


void push(celula **base, celula **topo, int conteudo) {
    celula *nova = (celula*)malloc(sizeof(celula));

    nova->data = conteudo;
    nova->seg = *topo;
    *topo = nova;
    
    if (*base == NULL)
        *base = nova;
}


int pop(celula **topo) {
    celula *lixo = *topo;
    int data = (*topo)->data;

    *topo = lixo->seg;

    free(lixo);

    return data;
}


void topoNaBase(celula **topo, celula **base) {
    celula *aux = *topo;
    
    if ((*topo)->seg != NULL)
        *topo = (*topo)->seg;

    aux->seg = (*base)->seg;
    (*base)->seg = aux;
    *base = aux;
}


int main() {
    celula *base, *topo;
    int num = -1;

    base = topo = NULL;
    
    while (1) {
        scanf("%d", &num);
        
        if (num == 0) break;

        for (int i=num; i>=1; i--)
            push(&base, &topo, i);

        printf("Discarded cards: ");

        for (int i=1; i<num; i++) {
            printf("%d", pop(&topo));
            if (i != num - 1)
                printf(", ");
            topoNaBase(&topo, &base);
        }

        printf("\nRemaining card: %d\n", pop(&topo));

        base = topo = NULL;
    }

    return 0;
}