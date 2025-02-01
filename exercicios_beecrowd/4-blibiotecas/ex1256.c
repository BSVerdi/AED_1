#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data;
    struct celula *seg;
} celula;


void append(celula **array, int index, int data) {
    celula *nova = (celula*)malloc(sizeof(celula));
    
    nova->data = data;
    nova->seg = NULL;
    
    if (array[index] == NULL)
        array[index] = nova;
    else {
        celula *aux;
        for (aux = array[index]; aux->seg != NULL ;aux = aux->seg);
        aux->seg = nova;
    }
}


void printHash(celula **array, int index) {
    int i;
    celula *aux;

    for (i = 0; i < index; i++) {
        printf("%d -> ", i);
        for (aux = array[i]; aux != NULL; aux = aux->seg)
            printf("%d -> ", aux->data);
        printf("\\\n");
    } 
}


int hash(int x, int index) {
    return x % index;
}


int main() {
    int cases, index, num, keys;
    celula **array;

    scanf("%d", &cases);

    for (int i = 0; i < cases; i++) {
        scanf("%d %d", &index, &keys);

        array = (celula**)malloc(sizeof(celula*) * index);

        // inicializando o array hash
        for (int j = 0; j < index; j++) 
            array[j] = NULL;

        for (int j = 0; j < keys; j++) {
            scanf("%d", &num);

            append(array, hash(num, index), num);
        }

        printHash(array, index);
        if (i < cases - 1) printf("\n");

        for (int j = 0; j < index; j++)
            free(array[j]);
        free(array);
    }

    return 0;
}