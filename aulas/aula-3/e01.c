#include<stdio.h>

int main(int argc, char *argv[]) {
    printf("numero de entradas = %d\n", argc);
    printf("executavel = %s\n", argv[0]);
    printf("nome = %s\n", argv[1]);
    printf("sobrenome = %s\n", argv[2]);

    return 0;
}