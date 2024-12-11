#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int const SIZE = 10000;

int buscaSequencial(int *array, int num, int size) {
    int j = 0;

    while (j < size && array[j] < num) ++j;

    return j; // retorna a posiçao onde esta ou deveria estar o valor procurado.
}


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
    int array[SIZE], pos, num;

    srand(time(0));

    for (int i = 0; i < SIZE; i++)
        array[SIZE] = rand() % SIZE;

    quicksort(array, 0, SIZE-1);

    printf("Insira o valor que deseja encontrar: ");
    scanf("%d", &num);
    
    pos = buscaSequencial(array, num, SIZE);

    printf("O valor %d esta na posicao %d", num, pos);

    return 0;
}