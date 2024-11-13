#include<stdio.h>

void acharDiamantes(char *string) {
    int contagem = 0, diamantes = 0, i, j;

    for (i=0; string[i] != '\0'; i++) {
        if ((string[i] == '<') && (contagem == 0)) {
            for (j=i; string[j] != '\0'; j++) {
                if (string[j] == '>') {
                    string[i] = ' ';
                    string[j] = ' ';
                    diamantes++;
                    break;
                }
            }   
        }
    }

    printf("%d\n", diamantes);    
}


int main() {
    char string[1000];
    int ciclos;

    scanf("%d", &ciclos);

    for (int i=0; i<ciclos; i++) {
        scanf("%s", string);
        acharDiamantes(string);
    }

    return 0;
}