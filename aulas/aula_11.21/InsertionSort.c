#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void insertionSort(int *array, int size) {
    int aux, i, j;

    for (i = 1; i < size; i++) {
        aux = array[i];

        for (j = i - 1; (j >= 0 && aux < array[j]); j--)
            array[j + 1] = array[j];
        array[j + 1] = aux;
    }
}


void printArray(int *array, int size) {
    for (int i=0; i<size; i++)
        printf("%d -> ", array[i]);
    printf("\n");
}


int main() {
    int array[10];

    srand(time(0));

    for (int i = 0; i < 10; i++)
        array[i] = rand() % 10;

    printf("Array antes de ordenar: \n");
    printArray(array, 10);

    insertionSort(array, 10);

    printf("Array depois de ordenar: \n");
    printArray(array, 10);

    return 0;
}