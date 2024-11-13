#include<stdio.h>
#include<stdlib.h>

void ordenar(int *lista, int size) {
    int i, j, aux;
    for (i=0; i<(size-1); i++) {
        for (j = 0; j < (size-1); j++) {
            if (lista[j] < lista[j + 1]) {
                aux = lista[j + 1];
                lista[j + 1] = lista[j];
                lista[j] = aux;
            }
        }
    }
}


int comparar(int *lista, int *lista_2, int size) {
    int i, contagem = 0;
    for (i = 0; i < size; i++) {
        if (lista[i] == lista_2[i])
            contagem++;
    }

    return contagem;
}


int main() {
    int *lista, *lista_ordenada, ciclos, alunos;

    scanf("%d", &ciclos);

    while (ciclos > 0) {
        scanf("%d", &alunos);

        lista = (int*)malloc(alunos * sizeof(int));
        lista_ordenada = (int*)malloc(alunos * sizeof(int));

        for (int i=0; i<alunos; i++) {
            scanf("%d", &lista[i]);
            lista_ordenada[i] = lista[i];
        }

        ordenar(lista_ordenada, alunos);

        printf("%d\n", comparar(lista, lista_ordenada, alunos));

        free(lista);
        free(lista_ordenada);
        
        ciclos--;
    }

    return 0;
}