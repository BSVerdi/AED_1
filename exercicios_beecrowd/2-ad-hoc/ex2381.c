#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *nome;
    struct celula *seg;
} celula;


void append(celula *lista, char *conteudo) {
    celula *atual, *proxima, *nova;
    nova = (celula*)malloc(sizeof(celula));

    nova->nome = (char*)malloc((strlen(conteudo) + 1) * sizeof(char));
    strcpy(nova->nome, conteudo);

    atual = lista;
    proxima = lista->seg;

    while (atual->seg != NULL && strcmp(proxima->nome, conteudo) < 0) {
        atual = proxima;
        proxima = proxima->seg;
    }

    nova->seg = atual->seg;
    atual->seg = nova;
}


void search(celula *lista, int posicao) {
    celula *atual = lista;
    for (int i=0; i<posicao; i++)
        atual = atual->seg;

    printf("%s\n", atual->nome);
}


int main() {
    int alunos, sorteado;
    char nome_aluno[21];
    celula *lista;

    lista = (celula *)malloc(sizeof(celula));
    lista->seg = NULL;

    scanf("%d", &alunos);
    scanf("%d", &sorteado);
    getchar();
    
    while (alunos > 0) {
        gets(nome_aluno);
        nome_aluno[strlen(nome_aluno) + 1] = '\0';
        append(lista, nome_aluno);
        alunos--;
    }

    search(lista, sorteado);

    return 0;
}