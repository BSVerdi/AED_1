#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int const SIZE = 10;

void merge(int *array, int start, int mid, int end) {
    int *subarray = (int *)malloc(sizeof(int) * (end - start));

    int i = start;
    int j = mid;
    int k = 0;

    while (i < mid && j < end) {
        if (array[i] <= array[j])
            subarray[k++] = array[i++];
        else
            subarray[k++] = array[j++];
    }

    while (i < mid)
        subarray[k++] = array[i++];
    
    while (j < end)
        subarray[k++] = array[j++];

    for (i = start; i < end; i++)
        array[i] = subarray[i - start];

    free(subarray);
}


void mergeSort(int *array, int start, int end) {
    if (start < end - 1) {
        int mid = (start + end) / 2;
        mergeSort(array, start, mid);
        mergeSort(array, mid, end);
        merge(array, start, mid, end);
    }
}


void printArray(int *array) {
    for (int i = 0; i < SIZE; i++)
        printf("%d -> ", array[i]);
    printf("\n");
}


int main() {
    int array[SIZE];

    srand(time(0));

    for (int i = 0; i < SIZE; i++)
        array[i] = rand() % SIZE;

    printf("Array antes de ordenar: \n");
    printArray(array);

    mergeSort(array, 0, SIZE);

    printf("Array depois de ordenar: \n");
    printArray(array);

    return 0;
}