#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char word[20];
    int price;
} Array;


int main() {
    char string[10000];
    int palavras, descricao;
    Array *dicionario;

    scanf("%d %d", &palavras, &descricao);

    dicionario = (Array*)malloc(palavras * sizeof(Array));

    for (int i = 0; i < palavras; i++) {
        getchar();
        scanf("%[^ ] %d", dicionario[i].word, &dicionario[i].price);
    }

    for (int i = 0; i < descricao; i++) {
        int total = 0;
        
        while (1) {
            scanf("%s", string);

            if (string[0] == '.') break;
            
            for (int j = 0; j < palavras; j++) {
                if (!strcmp(string, dicionario[j].word)) {
                    total += dicionario[j].price;
                    break;
                }
            }
        }
        printf("%d\n", total);
    }

    
    return 0;
}