#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data;
    struct celula *seg;
} Celula;


void append(Celula **array, int index, int data) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));

    nova->data = data;
    nova->seg = NULL;

    if (array[index] == NULL)
        array[index] = nova;
    else {
        Celula *temp;

        for (temp = array[index]; temp->seg != NULL; temp = temp->seg);
        
        temp->seg = nova;
    }
}


void printHash(Celula **array, int index) {
    int i;
    Celula *temp;

    for (i = 0; i < index; i++) {
        printf("%d ->", i);
        for(temp = array[i]; temp != NULL; temp = temp->seg)
            printf("%d -> ", temp->data);
        printf("\\\n");
    }
}


int hash(int x, int index) {
    return x % index;
}


int main() {
    int index = 13;
    Celula **array = (Celula**)malloc(13 * sizeof(Celula*));

    // inicializando o hash
    for (int i = 0; i < index; i++)
        array[i] = NULL;

    append(array, hash(44, index), 44);
    append(array, hash(45, index), 45);
    append(array, hash(49, index), 49);
    append(array, hash(70, index), 70);
    append(array, hash(27, index), 27);
    append(array, hash(73, index), 73);
    append(array, hash(92, index), 92);
    append(array, hash(97, index), 97);
    append(array, hash(95, index), 95);

    printHash(array, index);

    return 0;
}