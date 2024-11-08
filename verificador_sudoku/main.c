/*
    Verificador de matriz solução sudoku
*/

#include<stdio.h>

int verificar(int matriz[9][9]) {
    int bloco_x=0, bloco_y=0;

    // analise das submatrizes 3x3 (blocos) presente na matriz 9x9
    while (bloco_x < 9) {
        while (bloco_y < 9) {
            int bloco[9] = {0}, aux_bloco;
            
            for (int i=bloco_x; i<(bloco_x + 3); i++) {
                for (int j=bloco_y; j<(bloco_y+ 3); j++) {                    
                    aux_bloco = matriz[i][j]; // recebe o valor contido na posição (i, j) da matriz
                    bloco[aux_bloco - 1]++; // soma +1 à posição do vetor correspondete ao valor contido em aux_bloco

                    if (bloco[aux_bloco - 1] > 1) // se a contagem for maior que 1 significa que há numeros repetidos
                        return 0;
                }
            }            
            bloco_y += 3; // desloca 3 posições para baixo
        }
        bloco_y = 0; // volta ao topo da matriz 9x9
        bloco_x += 3; // desloca 3 posições para direita
    }
    
    // analise das linha e colunas, mesma logica presente na verificação dos blocos
    for(int i=0; i<9; i++) {
        int linha[9] = {0}, coluna[9] = {0}, aux_linha, aux_coluna;
        
        for (int j=0; j<9; j++) {
            // verificação da linha
            aux_linha = matriz[i][j];
            linha[aux_linha - 1]++; 

            if (linha[aux_linha - 1] > 1)
                return 0;

            // verificação da coluna    
            aux_coluna = matriz[j][i];
            coluna[aux_coluna - 1]++;

            if (coluna[aux_coluna - 1] > 1)
                return 0;
        }
    }

    return 1;
}


int main() {
    int matriz[9][9], num;

    // lendo a quantidade de jogos
    scanf("%d", &num);

    for (int c=1; c<=num; c++) {
        // lendo os valores da matriz
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++)
                scanf("%d", &matriz[i][j]);
        }

        printf("Instancia %d\n", c);
        if (verificar(matriz))
            printf("SIM\n\n");
        else 
            printf("NAO\n\n");
    }
    
    return 0;
}
