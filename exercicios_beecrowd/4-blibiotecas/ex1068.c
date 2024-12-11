#include<stdio.h>
#include<string.h>

int verificarExpressao(char *expressao) {
    int i=0, contagem = 0;

    for (i=0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            contagem++;
        } else if (expressao[i] == ')') {
            if (contagem == 0)
                return 0;
            contagem--;
        }
    }
    
    if (contagem)
        return 0;
        
    return 1;
}


int main() {
    char expressao[1001];

    while (fgets(expressao, 1001, stdin) != NULL) {
        expressao[strcspn(expressao, "\n")] = '\0';

        if (verificarExpressao(expressao))
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}