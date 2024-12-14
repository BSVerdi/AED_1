#include<stdio.h>
#include<stdlib.h>

int const MAX = 20;


void push(int *heap, int *size ,int data) {
    int aux = *size;
    int pai;

    heap[*size] = data;
    (*size)++;

    while (aux > 0) {
        pai = (aux - 1) / 2;

        if (heap[aux] > heap[pai]) {
            int temp = heap[pai];
            heap[pai] = heap[aux];
            heap[aux] = temp;
            aux = pai;
        } else return;
    }
}


int pop(int *heap, int *size) {
    int raiz = heap[0];
    int aux = 0;


    heap[0] = heap[*size - 1];
    (*size)--;

    while (aux < *size) {
        int max = aux;
        int left = 2 * aux + 1;
        int right = 2 * aux + 2;

        if (left < *size && heap[left] > heap[max])
            max = left;

        if (right < *size && heap[right] > heap[max])
            max = right;

        if (max != aux) {
            int temp = heap[aux];
            heap[aux] = heap[max];
            heap[max] = temp;
            aux = max;
        } else return raiz;
    }

    return raiz;
}


void heapSort(int *heap, int size) {
    int aux, tam = size;

    while (tam > 0) {
        aux = heap[0];
        heap[0] = heap[tam - 1];
        heap[tam - 1] = aux;
        
        aux = 0;
        tam--;

        while (aux < tam) {
            int max = aux;
            int left = 2 * aux + 1;
            int right = 2 * aux + 2;

            if (left < tam && heap[left] > heap[max])
                max = left;
        
            if (right < tam && heap[right] > heap[max])
                max = right;

            if (max != aux) {
                int temp = heap[aux];
                heap[aux] = heap[max];
                heap[max] = temp;
                aux = max;
            } else break;
        }
    }
}


void printArray(int *array, int size) {
    for (int i=0; i < size; i++)
        printf("%d -> ", array[i]);
    printf("\n");
}


int main() {
    int array[MAX], size = 0, num;

    for (int i = 0; i < 9; i++) {
        scanf("%d", &num);
        push(array, &size, num);
        printArray(array, size);
    }
    
    printf("Popped: %d\n", pop(array, &size));
    printArray(array, size);

    heapSort(array, size);
    printf("Array apos ordenacao: \n");
    printArray(array, size);

    return 0;
}