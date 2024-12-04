#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int passo = 20000;

int separa(int array[], int left, int right) {
    int pivo = array[right];
    int i = (left - 1);
    int aux;

    for (int j = left; j < right; j++) {
        if (array[j] <= pivo) {
            i++;
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
        }
    }
    aux = array[i + 1];
    array[i + 1] = array[right];
    array[right] = aux;

    return (i + 1);
}


void quicksort(int array[], int left, int right) {
    if (left < right) {
        int indice_pivo = separa(array, left, right);

        quicksort(array, left, indice_pivo - 1);
        quicksort(array, indice_pivo + 1, right);
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
        quicksort(array, 0, size - 1);
        tempo = clock() - tempo;

        printf("size = %d, tempo = %.6lf ms\n", size, ((double)tempo)/((CLOCKS_PER_SEC/1000)));

        free(array);

        size += passo;
    }

    return 0;
}