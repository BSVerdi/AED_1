#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *conteudo;
    struct celula *seg;
} celula;


void append(char *palavra, celula *lista) {
    celula *nova, *aux_1, *aux_2;
    aux_1 = lista;
    aux_2 = lista->seg;

    nova = malloc(sizeof(celula));
    nova->conteudo = (char *)malloc((strlen(palavra) + 1) * sizeof(char));
    strcpy(nova->conteudo, palavra);

    while ((aux_1->seg != NULL) && (aux_1 != NULL) && (strcmp(aux_2->conteudo, palavra) < 0)) {
        aux_1 = aux_2;
        aux_2 = aux_2->seg;
    }
    if ((aux_1 != NULL) && (aux_1->seg != NULL) && (strcmp(aux_2->conteudo, palavra) == 0)) {
        free(nova->conteudo);
        free(nova);
        return;
    }

    nova->seg = aux_1->seg;
    aux_1->seg = nova;
}


void clear(celula *lista) {
    celula *aux, *aux_2;
    aux = lista->seg;

    while (aux != NULL) {
        aux_2 = aux;
        aux = aux->seg;
        free(aux_2->conteudo);
        free(aux_2);
    }
    lista->seg = NULL;
}


void separarPalavras(char *string, celula *lista) {
    int i=0, j=0, size;
    char *palavra;

    while (string[i] != '\0') {
        size = 0;

        if (string[i] != ' ') {
            while (string[i + size] != ' ' && string[i + size] != '\0') size++;
            
            palavra = (char *)malloc((size + 1) * sizeof(char));
            
            for (j=0; j<size; j++) 
                palavra[j] = string[i + j];
            palavra[j] = '\0';

            append(palavra, lista);

            free(palavra);
        }
        i += (size+1);
    }
}


void imprimir(celula *lista) {
    celula *aux;
    for (aux = lista->seg; aux->seg != NULL; aux = aux->seg)
        printf("%s ", aux->conteudo);
    printf("%s\n", aux->conteudo);
}


int main() {
    celula *lista;
    char string[200000];
    int entradas;

    lista = malloc(sizeof(celula));
    lista->seg = NULL;

    scanf("%d", &entradas);
    getchar();

    while (entradas > 0) {
        gets(string);
        string[strlen(string) + 1] = '\0';
        separarPalavras(string, lista);
        
        imprimir(lista);
        
        clear(lista);
        
        entradas--;
    }

    return 0;
}