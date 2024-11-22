#include<stdio.h>

int main() {
    double nota_1, nota_2, nota_3, media;

    scanf("%lf%lf%lf", &nota_1, &nota_2, &nota_3);

    media = (2 * nota_1 + 3 * nota_2 + 5 * nota_3) / 10;

    printf("MEDIA = %.1lf\n", media);

    return 0;
}