#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3

int main()
{
    int tab[TAM][TAM];

    // Coordenadas dos navios
    int linhaH = 2, colunaH = 4; // Horizontal
    int linhaV = 5, colunaV = 1; // Vertical
    int linhaDP = 1, colunaDP = 1; // Diagonal Principal
    int linhaDI = 0, colunaDI = 9; // Diagonal Inversa


    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tab[i][j] = 0;
        }
    }


    if (colunaH + NAVIO_TAM > TAM) {
        printf("Navio horizontal não cabe\n");
        return 1;
    }
    if (linhaV + NAVIO_TAM > TAM) {
        printf("Navio vertical não cabe\n");
        return 1;
    }


    if (linhaDP + NAVIO_TAM > TAM || colunaDP + NAVIO_TAM > TAM) {
        printf("Navio diagonal principal não cabe\n");
        return 1;
    }
    if (linhaDI + NAVIO_TAM > TAM || colunaDI - (NAVIO_TAM - 1) < 0) {
        printf("Navio diagonal inversa não cabe\n");
        return 1;
    }


    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tab[linhaDP + i][colunaDP + i] == 3) {
            printf("Sobreposição na diagonal principal!\n");
            return 1;
        }
        if (tab[linhaDI + i][colunaDI - i] == 3) {
            printf("Sobreposição na diagonal inversa!\n");
            return 1;
        }
    }

    
    for (int i = 0; i < NAVIO_TAM; i++) {
        tab[linhaH][colunaH + i] = 3;        
        tab[linhaV + i][colunaV] = 3;          
        tab[linhaDP + i][colunaDP + i] = 3;    
        tab[linhaDI + i][colunaDI - i] = 3;     
    }

    // Exibe tabuleiro
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tab[i][j]);
        }
        printf("\n");
    }

    return 0;
}