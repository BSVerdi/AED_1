#include<stdio.h>

int main() {
    int distancia;
    float c_gasto, media_consumo;

    scanf("%d %f", &distancia, &c_gasto);

    media_consumo = distancia / c_gasto;

    printf("%.3f km/l\n", media_consumo);

    return 0;
}