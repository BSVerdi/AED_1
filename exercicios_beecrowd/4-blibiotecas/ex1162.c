#include<stdio.h>

typedef struct {
    int vagoes[51];
    int size;
} array;


int insertionSort(array *trem) {
    int aux, i, j, swaps = 0;

    for (i = 1; i < trem->size; i++) {
        aux = trem->vagoes[i];

        for (j = i - 1; (j >= 0 && aux < trem->vagoes[j]); j--) {
            trem->vagoes[j + 1] = trem->vagoes[j];
            swaps++;
        }
        trem->vagoes[j + 1] = aux;
    }

    return swaps;
}


int main() {
    int cases, wagons, swaps; 
    array trem;

    scanf("%d", &cases);

    for (int i = 0; i <cases; i++){
        scanf("%d", &wagons);
        trem.size = wagons;

        for (int j = 0; j < wagons; j++) 
            scanf("%d", &trem.vagoes[j]);

        swaps = insertionSort(&trem);

        printf("Optimal train swapping takes %d swaps.\n", swaps);
    }
    
    return 0;
}