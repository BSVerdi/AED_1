#include<stdio.h>
#include<stdlib.h>


void readBoard(char **matriz,int height) {
    getchar();

    for (int i=0; i<height; i++)
        gets(matriz[i]);
}


int main() {
    int width, height, i=0, j=0;
    char **matriz, atual;

    scanf("%d %d", &width, &height);

    matriz = (char**)malloc(sizeof(char*) * height);
    for (int i=0; i<height; i++)
        matriz[i] = (char*)malloc(sizeof(char) * width + 1);

    readBoard(matriz, height);

    while (i < height && j < width && i >= 0 && j >= 0) {
        atual = matriz[i][j];

        matriz[i][j] = 'X';

        if (atual == '*') {
            printf("*\n");
            break;
        } else if (atual == '>') {
            do {
                matriz[i][j] = 'X';
            } while (matriz[i][++j] == '.');
        } else if (atual == 'v') {
            do {
                matriz[i][j] = 'X';
            } while (matriz[++i][j] == '.');
        } else if (atual == '<') {
            do {
                matriz[i][j] = 'X';
            } while (matriz[i][--j] == '.');
        } else if (atual == '^') {
            do {
                matriz[i][j] = 'X';
            } while (matriz[--i][j] == '.');
        } else {
            printf("!\n");
            break;
        }
    }

    free(matriz);

    return 0;
}