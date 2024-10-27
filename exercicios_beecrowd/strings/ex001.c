#include<stdio.h>

int main() {
    char frase[1000], aux, bin;
    int i, linha, num;
    
    scanf("%d", &num);
    bin = getchar();

    for (linha=0; linha < num; linha++) {
        int size = 0;
        
        gets(frase);
        
        for (i = 0; frase[i] != '\0'; i++) {
            if (('a' <= frase[i] && frase[i] <= 'z') || ('A' <= frase[i] && frase[i] <= 'Z'))
                frase[i] += 3;
            size++;
        }
        for (i=0; i < size/2; i++) {
            aux = frase[size - 1 - i];
            frase[size - 1 - i] = frase[i];
            frase[i] = aux;
        }
        for (i=(size/2); i<size; i++)
            frase[i]--;

        puts(frase);   
    }

    return 0;
}