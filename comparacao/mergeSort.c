#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int passo = 20000;

void intercala(int array[], int left, int mid, int right) {
    int i, j, k, *subarray;

    subarray = (int *)malloc(sizeof(int) * right - left);

    i = left;
    j = mid;
    k = 0;

    while (i < mid && j < right) {
        if (array[i] <= array[j])
            subarray[k++] = array[i++];
        else
            subarray[k++] = array[j++];
    }

    while (i < mid)
        subarray[k++] = array[i++];
    while (j < right)
        subarray[k++] = array[j++];

    for (i = left; i < right; i++)
        array[i] = subarray[i - left];
    
    free(subarray);
}


void mergeSort(int array[], int left, int right) {
    if (left < right - 1) {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid, right);
        intercala(array, left, mid, right);
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
        mergeSort(array, 0, size);
        tempo = clock() - tempo;

        printf("%.0lf\n", ((double)tempo)/((CLOCKS_PER_SEC/1000)));

        free(array);

        size += passo;
    }

    return 0;
}