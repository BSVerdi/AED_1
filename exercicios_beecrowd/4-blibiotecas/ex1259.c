#include<stdio.h>
#include<stdlib.h>


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
        printf("%d\n", array[i]);
}


int main() {
    int *pares, *impares, *total, entradas, num, i = 0 , j = 0, qtd_pares = 0, qtd_impares = 0;

    scanf("%d", &entradas);

    pares = (int*)malloc(sizeof(int) * entradas);
    impares = (int*)malloc(sizeof(int) * entradas);
    total = (int*)malloc(sizeof(int) * entradas);

    while ((i + j) < (entradas)) {
        scanf("%d", &num);

        if (num % 2 == 0) {
            pares[i++] = num;
            qtd_pares++;
        } else {
            impares[j++] = num;
            qtd_impares++;
        }
    }

    quickSort(pares, 0, qtd_pares - 1);
    quickSort(impares, 0, qtd_impares - 1);

    for (i = 0; i < qtd_pares; i++) total[i] = pares[i];

    for (j = qtd_impares - 1; j >= 0; j--) total[i++] = impares[j];

    printArray(total, entradas);

    return 0;
}
