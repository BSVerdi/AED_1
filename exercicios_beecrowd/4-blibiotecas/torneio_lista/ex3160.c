#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *conteudo;
    struct celula *seg;
} celula;


void append(char *palavra, celula *lista) {
    celula *aux, *nova;

    aux = lista;

    while (aux->seg != NULL)
        aux = aux->seg;
    
    nova = malloc(sizeof(celula));
    nova->conteudo = (char *)malloc(strlen(palavra) + 1);
    strcpy(nova->conteudo, palavra);
    nova->seg = aux->seg;
    aux->seg = nova;
}


void imprimir(celula *lista) {
    celula *aux;

    aux = lista->seg;

    while (aux->seg != NULL) {
        printf("%s ", aux->conteudo);
        aux = aux->seg;
    }
    printf("%s\n", aux->conteudo);
}


void separarPalavra(char *frase, celula *lista) {
    int i=0, j=0, size;
    char *palavra;

    while (frase[i] != '\0') {
        size = 0;

        if (frase[i] != ' ') {
            while (frase[i + size] != ' ' && frase[i + size] != '\0') size++;
            
            palavra = (char *)malloc((size + 1) * sizeof(char));
            
            for (j=0; j<size; j++) 
                palavra[j] = frase[i + j];
            palavra[j] = '\0';

            append(palavra, lista);

            free(palavra);
        }

        i += (size + 1);
    }
}


void buscarJuntar(char *decisao, celula *lista_1, celula *lista_2) {
    celula *aux, *aux_2;
    
    aux = lista_1->seg;
    aux_2 = lista_1;

    while ((strcmp(aux->conteudo, decisao)) && (aux->seg != NULL)) {
        aux_2 = aux_2->seg;
        aux = aux->seg;
    }

    if (aux->seg == NULL && (strcmp(aux->conteudo, decisao)))
        aux->seg = lista_2->seg;
    else {
        aux_2->seg = lista_2->seg;
        while (aux_2->seg != NULL)
            aux_2 = aux_2->seg;
        aux_2->seg = aux;
    }
}


int main() {
    celula *lista_1, *lista_2;
    char string[100000];

    lista_1 = malloc(sizeof(celula));
    lista_1->seg = NULL;

    lista_2 = malloc(sizeof(celula));
    lista_2->seg = NULL;

    gets(string);
    string[strlen(string) + 1] = '\0';
    separarPalavra(string, lista_1);

    gets(string);
    string[strlen(string) + 1] = '\0';
    separarPalavra(string, lista_2);

    gets(string);
    string[strlen(string) + 1] = '\0';

    buscarJuntar(string, lista_1, lista_2);

    imprimir(lista_1);

    return 0;
}