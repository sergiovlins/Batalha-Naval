#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3
#define ENTRE(x, lo, hi) ((x) >= lo && (x) < hi)

int cone[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}};

int cruz[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}};

int octaedro[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0}};

int main()
{
    int tab[TAM][TAM];

    // Coordenadas dos navios
    int linhaH = 2, colunaH = 4;   // Horizontal
    int linhaV = 5, colunaV = 1;   // Vertical
    int linhaDP = 1, colunaDP = 1; // Diagonal Principal
    int linhaDI = 0, colunaDI = 9; // Diagonal Inversa
    int oriConeL = 2, oriConeC = 2;
    int oriCruzL = 5, oriCruzC = 5; // meio do tabuleiro
    int oriOctL = 7, oriOctC = 2;

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            tab[i][j] = 0;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (cone[i][j] == 1)
            {
                int L = oriConeL + (i - 2);
                int C = oriConeC + (j - 2);
                if (ENTRE(L, 0, TAM) && ENTRE(C, 0, TAM) && tab[L][C] == 0)
                    tab[L][C] = 5;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (cruz[i][j] == 1)
            {
                int L = oriCruzL + (i - 2);
                int C = oriCruzC + (j - 2);
                if (ENTRE(L, 0, TAM) && ENTRE(C, 0, TAM) && tab[L][C] == 0)
                    tab[L][C] = 5;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (octaedro[i][j] == 1)
            {
                int L = oriOctL + (i - 2);
                int C = oriOctC + (j - 2);
                if (ENTRE(L, 0, TAM) && ENTRE(C, 0, TAM) && tab[L][C] == 0)
                    tab[L][C] = 5;
            }
        }
    }

    if (colunaH + NAVIO_TAM > TAM)
    {
        printf("Navio horizontal não cabe\n");
        return 1;
    }
    if (linhaV + NAVIO_TAM > TAM)
    {
        printf("Navio vertical não cabe\n");
        return 1;
    }

    if (linhaDP + NAVIO_TAM > TAM || colunaDP + NAVIO_TAM > TAM)
    {
        printf("Navio diagonal principal não cabe\n");
        return 1;
    }
    if (linhaDI + NAVIO_TAM > TAM || colunaDI - (NAVIO_TAM - 1) < 0)
    {
        printf("Navio diagonal inversa não cabe\n");
        return 1;
    }

    for (int i = 0; i < NAVIO_TAM; i++)
    {
        if (tab[linhaDP + i][colunaDP + i] == 3)
        {
            printf("Sobreposição na diagonal principal!\n");
            return 1;
        }
        if (tab[linhaDI + i][colunaDI - i] == 3)
        {
            printf("Sobreposição na diagonal inversa!\n");
            return 1;
        }
    }

    for (int i = 0; i < NAVIO_TAM; i++)
    {
        tab[linhaH][colunaH + i] = 3;
        tab[linhaV + i][colunaV] = 3;
        tab[linhaDP + i][colunaDP + i] = 3;
        tab[linhaDI + i][colunaDI - i] = 3;
    }

    // Exibe tabuleiro
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf("%2d ", tab[i][j]);
        }
        printf("\n");
    }
    return 0;
}