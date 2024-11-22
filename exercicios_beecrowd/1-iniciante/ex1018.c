#include<stdio.h>

int main() {
    int valor, cedulas[7] = {0, 0, 0, 0, 0, 0, 0};

    scanf("%d", &valor);

    printf("%d\n", valor);

    cedulas[0] = valor / 100;
    valor %= 100;
    cedulas[1] = valor / 50;
    valor %= 50;
    cedulas[2] = valor / 20;
    valor %= 20;
    cedulas[3] = valor / 10;
    valor %= 10;
    cedulas[4] = valor / 5;
    valor %= 5;
    cedulas[5] = valor / 2;
    valor %= 2;
    cedulas[6] = valor / 1;

    printf("%d nota(s) de R$ 100,00\n", cedulas[0]);
    printf("%d nota(s) de R$ 50,00\n", cedulas[1]);
    printf("%d nota(s) de R$ 20,00\n", cedulas[2]);
    printf("%d nota(s) de R$ 10,00\n", cedulas[3]);
    printf("%d nota(s) de R$ 5,00\n", cedulas[4]);
    printf("%d nota(s) de R$ 2,00\n", cedulas[5]);
    printf("%d nota(s) de R$ 1,00\n", cedulas[6]);

    return 0;
}