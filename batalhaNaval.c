#include <stdio.h>


int main() {
    printf("Desafio Batalha Naval!! \n");

// Tamanho fixo do tabuleiro e dos navios
#define TamanhoTabuleiro 10
#define TamanhoNavio 3

// Função para imprimir o tabuleiro na tela
void exibirTabuleiro(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro]) {
    printf("   ");
    for (int i = 0; i < TamanhoTabuleiro; i++) {
        printf("%2d ", i);  // cabeçalho das colunas
    }
    printf("\n");

    for (int i = 0; i < TamanhoTabuleiro; i++) {
        printf("%2d ", i);  // índice da linha
        for (int j = 0; j < TamanhoTabuleiro; j++) {
            printf(" %d ", tabuleiro[i][j]);  // 0 = água, 3 = parte do navio
        }
        printf("\n");
    }
}

// Função para verificar se é possível posicionar o navio
int podePosicionarNavio(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro],
                        int linha, int coluna, char direcao) {
    for (int i = 0; i < TamanhoNavio; i++) {
        int l = linha + (direcao == 'V' ? i : 0);
        int c = coluna + (direcao == 'H' ? i : 0);

        // Verifica se está fora dos limites do tabuleiro
        if (l >= TamanhoTabuleiro || c >= TamanhoTabuleiro) {
            return 0;
        }

        // Verifica se já existe um navio nesta posição
        if (tabuleiro[l][c] != 0) {
            return 0;
        }
    }
    return 1;  // Ok para posicionar
}

// Função para posicionar um navio
void posicionarNavio(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro],
                     int linha, int coluna, char direcao) {
    for (int i = 0; i < TamanhoNavio; i++) {
        int l = linha + (direcao == 'V' ? i : 0);
        int c = coluna + (direcao == 'H' ? i : 0);
        tabuleiro[l][c] = 3;  // Marca a posição do navio
    }
}

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro] = {0};

    // Coordenadas dos navios (definidas no código)
    int linhaNavioH = 2, colunaNavioH = 3; // Navio horizontal
    int linhaNavioV = 5, colunaNavioV = 7; // Navio vertical

    // Posiciona navio horizontal
    if (podePosicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, 'H')) {
        posicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, 'H');
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
    }

    // Posiciona navio vertical
    if (podePosicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, 'V')) {
        posicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, 'V');
    } else {
        printf("Erro ao posicionar navio vertical!\n");
    }

    // Exibe o tabuleiro final
    printf("Tabuleiro com navios posicionados:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}

    

    return 0;
}
