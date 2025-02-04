#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char string[55];
    int strsize;
} Array;


int strlen(char *string) {
    int size;

    for (size = 0; string[size] != '\0'; size++);

    return size;
}


int separar(char *string, Array *words) {
    int i, j = 0, k = 0;

    //puts(string);

    for (i = 0; i <= strlen(string); i++) {
        if (string[i] != ' ' && string[i] != '\0') {
            words[j].string[k++] = string[i];
        } else {
            words[j].string[k] = '\0';
            words[j].strsize = strlen(words[j].string);
            j++;
            k = 0;
        }
    }

    return j;
}


void insertionSort(Array *words, int size) {
    int i, j;
    Array aux;

    for (i = 1; i < size; i++) {
        aux = words[i];

        for (j = i - 1; (j >= 0 && aux.strsize > words[j].strsize); j--)
            words[j + 1] = words[j];
        words[j + 1] = aux;
    }
}


void printArray(Array *words, int size) {
    for (int i = 0; i < size; i++)
        printf("%s ", words[i].string);
    printf("\n");
}


int main() {
    int cases;
    char string[60];
    Array words[50];

    scanf("%d", &cases);
    getchar();

    for (int i = 0; i < cases; i++) {
        int size;

        gets(string);

        size = separar(string, words);

        insertionSort(words, size);

        printArray(words, size);
    }


    return 0;
}