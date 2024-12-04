#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int passo = 20000;

void insertionSort(int array[], int size) {
    int aux, j, i;

    for (i = 1; i < size; i++) {
        aux = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > aux) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = aux;
    }
}


int main() {
    int *array, size = passo;
    clock_t tempo;

    
    while (size <= 400000) {
        array = (int *)malloc(sizeof(int) * size);
        
        srand((unsigned)time(NULL));

        for (int j = 0; j < size; j++)
            array[j] = rand() % size;

        tempo = clock();
        insertionSort(array, size);
        tempo = clock() - tempo;

        printf("size = %d, tempo = %.6lf ms\n", size, ((double)tempo)/((CLOCKS_PER_SEC/1000)));

        free(array);

        size += passo;
    }

    return 0;
}