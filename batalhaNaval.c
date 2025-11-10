#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // 1) Inicializa tabuleiro com água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2) Coloca 4 navios (3 casas) como no nível anterior (0-index)
    // 2.1 Horizontal (linha 3, colunas 4..6) -> 4EFG na sua notação
    tabuleiro[3][4] = 3;
    tabuleiro[3][5] = 3;
    tabuleiro[3][6] = 3;

    // 2.2 Vertical (coluna 2, linhas 6..8) -> C789 na sua notação
    tabuleiro[6][2] = 3;
    tabuleiro[7][2] = 3;
    tabuleiro[8][2] = 3;

    // 2.3 Diagonal principal (1,1)-(3,3)
    tabuleiro[1][1] = 3;
    tabuleiro[2][2] = 3;
    tabuleiro[3][3] = 3;

    // 2.4 Diagonal invertida (6,3)-(8,1)
    tabuleiro[6][3] = 3;
    tabuleiro[7][2] = 3; // já é navio vertical, mantém 3
    tabuleiro[8][1] = 3;

    // 3) Matrizes de habilidade 5x5 (0 = fora, 1 = dentro)
    int cone[5][5];
    int cruz[5][5];
    int octa[5][5];

    // 3.1 Monta CONE (apontando para baixo, topo na linha 0, centro na coluna 2)
    // regra: em cada linha r, colunas de (2 - r) até (2 + r) são 1 (se estiverem no 0..4)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (j >= (2 - i) && j <= (2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // 3.2 Monta CRUZ (centro em (2,2))
    // regra: mesma linha do centro ou mesma coluna do centro
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // 3.3 Monta OCTAEDRO (losango) com raio 2 (centro (2,2))
    // regra: |i-2| + |j-2| <= 2
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int di = (i > 2) ? (i - 2) : (2 - i);
            int dj = (j > 2) ? (j - 2) : (2 - j);
            if (di + dj <= 2) {
                octa[i][j] = 1;
            } else {
                octa[i][j] = 0;
            }
        }
    }

    // 4) Define origens no tabuleiro (0-index)
    //    - cone: origem é o TOPO do cone (ancoramos a linha 0 da matriz nessa origem)
    //    - cruz e octa: origem é o CENTRO da matriz (2,2) centralizada no ponto
    int linCone = 1, colCone = 7;   // topo do cone no tabuleiro
    int linCruz = 5, colCruz = 5;   // centro da cruz no tabuleiro
    int linOcta = 8, colOcta = 7;   // centro do octaedro no tabuleiro

    // 5) Sobrepõe CONE no tabuleiro
    // mapeamento: (i,j) da matriz -> (linCone + i, colCone + (j-2))
    // pois o topo do cone (i=0) fica na origem; a coluna 2 é o "meio" do topo.
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int li = linCone + i;       // desce a partir do topo
                int cj = colCone + (j - 2); // espalha para os lados a partir da coluna central
                if (li >= 0 && li < 10 && cj >= 0 && cj < 10) {
                    if (tabuleiro[li][cj] == 0) { // não sobrescreve navio
                        tabuleiro[li][cj] = 5;
                    }
                }
            }
        }
    }

    // 6) Sobrepõe CRUZ no tabuleiro (matriz centralizada na origem)
    // mapeamento: (i,j) -> (linCruz + (i-2), colCruz + (j-2))
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int li = linCruz + (i - 2);
                int cj = colCruz + (j - 2);
                if (li >= 0 && li < 10 && cj >= 0 && cj < 10) {
                    if (tabuleiro[li][cj] == 0) {
                        tabuleiro[li][cj] = 5;
                    }
                }
            }
        }
    }

    // 7) Sobrepõe OCTAEDRO no tabuleiro (matriz centralizada na origem)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (octa[i][j] == 1) {
                int li = linOcta + (i - 2);
                int cj = colOcta + (j - 2);
                if (li >= 0 && li < 10 && cj >= 0 && cj < 10) {
                    if (tabuleiro[li][cj] == 0) {
                        tabuleiro[li][cj] = 5;
                    }
                }
            }
        }
    }

    // 8) Imprime cabeçalho e tabuleiro (0 = água, 3 = navio, 5 = área de habilidade)
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
