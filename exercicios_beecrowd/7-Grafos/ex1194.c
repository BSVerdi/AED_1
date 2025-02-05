#include<stdio.h>
#include<string.h>

void posfixa(char *prefixo, char *infixo, int n) {
    if (n == 0) return;

    char raiz = prefixo[0];

    int raizpos = strchr(infixo, raiz)- infixo;

    posfixa(prefixo + 1, infixo, raizpos);
    posfixa(prefixo + raizpos + 1, infixo + raizpos + 1, n - raizpos - 1);

    printf("%c", raiz);
}


int main() {
    int cases;

    scanf("%d", &cases);

    while (cases--) {
        int n;
        char string_1[55], string_2[55];

        scanf("%d %s %s", &n, string_1, string_2);

        posfixa(string_1, string_2, n);
        printf("\n");
    }

    return 0;
}