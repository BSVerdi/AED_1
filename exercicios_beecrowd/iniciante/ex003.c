#include<stdio.h>

int main() {
    double pi=3.14159, raio, area;

    scanf("%lf", &raio);

    area = pi * (raio * raio);

    printf("A=%lf", area);

    return 0;
}