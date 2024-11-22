#include<stdio.h>

int main() {
    int cod, quantidade, i;
    float valor, total = 0;

    for (i=0; i<2; i++) {
        scanf("%d %d %f", &cod, &quantidade, &valor);
        total += (quantidade * valor); 
    }

    printf("VALOR A PAGAR: R$ %.2f\n", total);

    return 0;
}