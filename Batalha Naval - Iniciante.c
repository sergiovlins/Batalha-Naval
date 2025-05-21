#include <stdio.h>
#define TAM 10
#define NAVIO_TAM 3
int main()
{

    int tab[TAM][TAM];
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 1;

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
         tab[i][j] = 0;
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

    for (int i = 0; i < NAVIO_TAM; i++)
    {
        tab[linhaH][colunaH + i] = 3; 
    }
    for (int i = 0; i < NAVIO_TAM; i++)
    {
        tab[linhaV + i][colunaV] = 3; 
    }
    
    for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
        printf("%d ", tab[i][j]);
    }
    printf("\n");
}
    
}