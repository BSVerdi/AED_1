#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int code;
    int quantidade;
} celula;


int particionar(celula *array, int start, int end) {
    int pivo = array[end].quantidade;
    int i = (start - 1), j;
    celula aux;

    for (j = start; j < end; j++) {
        if (array[j].quantidade < pivo || (array[j].quantidade == pivo && array[j].code > array[end].code)) {
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


void quickSort(celula *array, int start, int end) {
    if (start < end) {
        int pivo = particionar(array, start, end);

        quickSort(array, start, pivo - 1);
        quickSort(array, pivo + 1, end);
    }
}


void printArray(celula *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d %d\n", array[i].code, array[i].quantidade);
}


int main() {
    char string[1001];
    celula *array;
    int i, j, size, passo = 0;

    while (scanf(" %[^\n]", string) != EOF) {
        array = (celula*)malloc(96 * sizeof(celula));
        // inicializando a lista;
        for (i = 0; i < 96; i++) {
            array[i].code = -1;
            array[i].quantidade = 0; 
        }


        for (i = 0; string[i] != '\0'; i++) {
            if (string[i] >= 32 && string[i] <= 127) {
                if (i == 0) {
                    array[i].code = string[i];
                    array[i].quantidade++;
                } else {
                    int temp = -1;
                    for (j = 0; j < 96; j++) {
                        // salva uma posição vazia
                        if (temp == -1 && array[j].code == -1)
                            temp = j;

                        if (array[j].code == string[i]) {
                            temp = j;
                            break;
                        }
                    }
                    
                    array[temp].code = string[i];
                    array[temp].quantidade++;
                    
                }
            }
        }

        for (size = 0; array[size].code != -1; size++);

        // ordenar em relação a quantidade
        quickSort(array, 0, size - 1);

        if (passo)
            printf("\n");
        else
            passo++;

        printArray(array, size);
        
        free(array);
    }   


    return 0;
}