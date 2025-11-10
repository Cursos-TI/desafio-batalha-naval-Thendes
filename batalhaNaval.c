#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // 1. Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Posiciona 4 navios (todos com tamanho 3)
    // ---------------- NAVIOS HORIZONTAIS/VERTICAIS ----------------
    // Navio 1 (horizontal) -> linha 2, colunas 4,5,6
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    tabuleiro[2][6] = 3;

    // Navio 2 (vertical) -> coluna 8, linhas 5,6,7
    tabuleiro[5][8] = 3;
    tabuleiro[6][8] = 3;
    tabuleiro[7][8] = 3;

    // ---------------- NAVIOS DIAGONAIS ----------------
    // Navio 3 (diagonal principal) -> cresce linha e coluna
    // começa em (1,1), depois (2,2), (3,3)
    tabuleiro[1][1] = 3;
    tabuleiro[2][2] = 3;
    tabuleiro[3][3] = 3;

    // Navio 4 (diagonal invertida) -> cresce linha e diminui coluna
    // começa em (6,3), depois (7,2), (8,1)
    tabuleiro[6][3] = 3;
    tabuleiro[7][2] = 3;
    tabuleiro[8][1] = 3;

    // 3. Exibir o tabuleiro no console
    printf("    A B C D E F G H I J\n");
    printf("   ---------------------\n");

    for (i = 0; i < 10; i++) {
        printf("%2d |", i + 1);
        for (j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}