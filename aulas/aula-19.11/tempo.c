#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 100000; //constante para tamanho do vetor

void bubbleSort (int v[TAM]) {
    int a, b, aux;
    for (a=TAM-1; a>=1; a--) {
        for (b=0; b<a; b++) {
            if (v[b]>v[b+1]) {
                aux = v[b];
                v[b] = v[b+1];
                v[b+1] = aux;
            }
        }
    }
}


int buscaSequencial(int x, int size, int *v) {
    int j = 0;

    while (j < size && v[j] < x) ++j;

    return j;
}


int buscaBinaria(int x, int size, int *v) {
    int e = -1, d = (size-1), m;
    while (e < d - 1) {
        m = (e + d) / 2;

        if (v[m] < x)
            e = m;
        else
            d = m;
    }

    return d;
}

int main(){
    clock_t t; //variável para armazenar tempo
    int vetor[TAM], num=100904;
    
    //semente de aleatoriedade
    srand((unsigned)time(NULL));

    //geração aleatório dos valores do vetor
    for(int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    bubbleSort(vetor);

    t = clock(); //armazena tempo
    printf("pos = %d\n", buscaSequencial(num, TAM, vetor));
    t = clock() - t; //tempo final - tempo 

    printf("Tempo de execucao busca sequencial: %.6lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double

    t = clock(); //armazena tempo
    printf("pos = %d\n", buscaBinaria(num, TAM, vetor));
    t = clock() - t; //tempo final - tempo 

    printf("Tempo de execucao busca binaria: %.6lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double

    return 0;
}