#include<stdio.h>
#include<stdlib.h>

const int MAX = 300;

typedef struct {
    char data[300];
    int topo;
} pilha;


int isEmpty(pilha *pilha) {
    return pilha->topo == -1;
}


void push(pilha *pilha, char caracter) {
    pilha->data[++(pilha->topo)] = caracter;
}


char pop(pilha *pilha) {
    if (!isEmpty(pilha)) {
        return pilha->data[(pilha->topo)--];
    }
    return '\0';
}


char top(pilha *pilha) {
    if (!isEmpty(pilha)) {
        return pilha->data[pilha->topo];
    }
    return '\0';
}


int operador(char caracter) {
    char operadores[7] = "+-*/^()";

    for (int i=0; operadores[i] != '\0'; i++) {
        if (caracter == operadores[i])
            return 1;
    }

    return 0;
}


int precedencia(char caracter) {
    if (caracter == '^')
        return 3;
    if (caracter == '*' || caracter == '/')
        return 2;
    if (caracter == '+' || caracter == '-')
        return 1;
    
    return 0;
}


void posfixar(char *expressao, char *posfixa) {
    pilha *p = malloc(sizeof(pilha));
    int i=0, j=0;
    char aux;
    
    p->topo = -1;
    
    while (expressao[i] != '\0') {
        aux = expressao[i];

        if (!operador(aux))
            posfixa[j++] = aux;
        else if (aux == '(')
            push(p, aux);
        else if (aux == ')') {
            while (!isEmpty(p) && top(p) != '(')
                posfixa[j++] = pop(p);
            pop(p);
        } else {
            while (!isEmpty(p) && precedencia(top(p)) >= precedencia(aux))
                posfixa[j++] = pop(p);

            push(p, aux);
        }
        i++;
    }

    while (!isEmpty(p))
        posfixa[j++] = pop(p);

    posfixa[j] = '\0';

    free(p);
}


int main() {
    char expressao[MAX], expressao_posfixa[MAX];
    int ciclos;

    scanf("%d", &ciclos);
    getchar();

    while (ciclos--) {
        gets(expressao);

        posfixar(expressao, expressao_posfixa);

        puts(expressao_posfixa);
    }

    return 0;
}