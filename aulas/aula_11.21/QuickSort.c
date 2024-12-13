#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int const SIZE = 10;

int particionar(int *array, int start, int end) {
    int pivo = array[end];
    int i = (start - 1);
    int aux, j;

    for (j = start; j < end; j++) {
        if (array[j] <= pivo) {
            i++;
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
        }
    }

    aux = array[i + 1];
    array[i + 1] = array[end];
    array[end] = aux;

    return(i + 1);
}


void quickSort(int *array, int start, int end) {
    if (start < end) {
        int pivo = particionar(array, start, end);

        quickSort(array, start, pivo - 1);
        quickSort(array, pivo + 1, end);
    }
}


void printArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d -> ", array[i]);
    printf("\n");
}


int main() {
    int array[SIZE];

    srand(time(0));

    for (int i = 0; i < SIZE; i++)
        array[i] = rand() % SIZE;

    printf("Lista antes de ordenar: \n");
    printArray(array, SIZE);

    quickSort(array, 0, SIZE - 1);

    printf("Lista depois de ordenar: \n");
    printArray(array, SIZE);

    return 0;
}