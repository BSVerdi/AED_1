#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char string[51];
    double preco;
} array;


void printArray(array *lista, int size) {
    for (int i = 0; i < size; i++)
        printf("%s: %.2f\n", lista[i].string, lista[i].preco);
}


double checkPrice(array *lista, int size, char *string) {
    for (int i = 0; i < size; i++) {
        if (!strcmp(string, lista[i].string))
            return lista[i].preco;
    }

    return 0;
}


int main() {
    int size, cases, compras;
    array *lista;

    scanf("%d", &cases);

    for (int i = 0; i < cases; i++) {
        double total = 0;
        
        scanf("%d", &size);

        lista = (array*)malloc(size * sizeof(array));

        for (int j = 0; j < size; j++) {
            scanf("%s", lista[j].string);
            scanf("%lf", &lista[j].preco); 
        }

        scanf("%d", &compras);

        for (int j = 0; j < compras; j++) {
            char string[51];
            int qtd;

            scanf("%s", string);
            scanf("%d", &qtd);

            total += qtd * checkPrice(lista, size, string);
        }

        printf("R$ %.2f\n", total);
    }
    
    return 0;
} 