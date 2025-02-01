#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data[1000];
    int size;
} array;


void push(array *pilha, int data) {
    pilha->data[pilha->size++] = data;
}


void enQueue(array *fila, int data) {
    fila->data[fila->size++] = data;
}


void enPriorityQueue(array *pFila, int data) {
    pFila->data[pFila->size++] = data;

    for (int i = pFila->size -1 ; i > 0 && pFila->data[i] > pFila->data[i - 1]; i--) {
        int temp = pFila->data[i];
        
        pFila->data[i] = pFila->data[i - 1];
        pFila->data[i - 1] = temp;
    }
}


int popStack(array *pilha) {
    return pilha->data[--pilha->size];
}


int popQueue(array *fila) {
    int i, temp = fila->data[0];

    for (i = 1; i < fila->size; i++)
        fila->data[i - 1] = fila->data[i];
    fila->size--;

    return temp;
} 


int main() {
    int data, steps, choice;

    while (scanf("%d", &steps) != EOF) {
        array pilha, fila, p_fila;
        int valido[3] = {1, 1, 1};

        pilha.size = fila.size = p_fila.size = 0;
        
        for (int i = 0; i < steps; i++) {
            scanf("%d %d", &choice, &data);

            if (choice == 1) {
                push(&pilha, data);
                enQueue(&fila, data);
                enPriorityQueue(&p_fila, data);
            } else if (choice == 2) {
                if (pilha.size == 0 || popStack(&pilha) != data)
                    valido[0] = 0;
                if (fila.size == 0 || popQueue(&fila) != data)
                    valido[1] = 0;
                if (p_fila.size == 0 || popQueue(&p_fila) != data)
                    valido[2] = 0;
            }
        } 

        if (valido[0] + valido[1] + valido[2] > 1)
            printf("not sure\n");
        else if (valido[0])
            printf("stack\n");
        else if (valido[1])
            printf("queue\n");
        else if (valido[2])
            printf("priority queue\n");
        else
            printf("impossible\n");
    }

    return 0;
}