#include <stdio.h>

int main() {
    int tabuleiro[10][10]; // matriz 10x10
    int linha, coluna;

    // 1. Inicializa o tabuleiro com 0
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // 2. Posiciona o primeiro navio (horizontal em 4EFG -> linha 3, colunas 4,5,6)
    tabuleiro[3][4] = 3;
    tabuleiro[3][5] = 3;
    tabuleiro[3][6] = 3;

    // 3. Posiciona o segundo navio (vertical em C789 -> coluna 2, linhas 6,7,8)
    tabuleiro[6][2] = 3;
    tabuleiro[7][2] = 3;
    tabuleiro[8][2] = 3;

    // 4. Imprime cabeçalho com letras A–J
    printf("    A B C D E F G H I J\n");
    printf("   ---------------------\n");

    // 5. Exibe o tabuleiro
    for (linha = 0; linha < 10; linha++) {
        printf("%2d |", linha + 1); // numeração das linhas
        for (coluna = 0; coluna < 10; coluna++) {
            printf(" %d", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}