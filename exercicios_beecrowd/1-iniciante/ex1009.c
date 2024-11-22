#include<stdio.h>

int main() {
    char nome[20];
    double salario, vendas;

    scanf("%s %lf %lf", &nome, &salario, &vendas);

    salario += (0.15 * vendas);

    printf("TOTAL = R$ %.2f\n", salario);

    return 0;
}