#include<stdio.h>

int main() {
    double nota_1, nota_2, media;

    scanf("%lf%lf", &nota_1, &nota_2);

    media = (3.5 * nota_1 + 7.5 * nota_2) / 11;

    printf("MEDIA = %.5lf\n", media);

    return 0;
}