#include <stdio.h>

#define TAMANHO 3

void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++)
        for (int j = 0; j < TAMANHO; j++)
            tabuleiro[i][j] = ' ';
}

void exibirTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAMANHO - 1) printf("|");
        }
        printf("\n");
        if (i < TAMANHO - 1) printf("---+---+---\n");
    }
    printf("\n");
}

int verificarVitoria(char tabuleiro[TAMANHO][TAMANHO], char jogador) {
    for (int i = 0; i < TAMANHO; i++) {
        // Verifica linhas e colunas
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) ||
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador))
            return 1;
    }

    // Verifica diagonais
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador))
        return 1;

    return 0;
}

int verificarEmpate(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++)
        for (int j = 0; j < TAMANHO; j++)
            if (tabuleiro[i][j] == ' ')
                return 0; // Ainda há jogadas possíveis

    return 1; // Todas as casas preenchidas (empate)
}

void jogar() {
    char tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    char jogadorAtual = 'X';
    int linha, coluna;
    int jogoAtivo = 1;

    while (jogoAtivo) {
        exibirTabuleiro(tabuleiro);
        printf("Jogador %c, informe linha e coluna (1-3 1-3): ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        // Ajusta índices para começar do zero
        linha--;
        coluna--;

        // Verifica se a jogada é válida
        if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }

        // Faz a jogada
        tabuleiro[linha][coluna] = jogadorAtual;

        // Verifica vitória
        if (verificarVitoria(tabuleiro, jogadorAtual)) {
            exibirTabuleiro(tabuleiro);
            printf("Parabéns! O jogador %c venceu!\n", jogadorAtual);
            jogoAtivo = 0;
        } 
        // Verifica empate
        else if (verificarEmpate(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("Empate! O jogo terminou sem vencedor.\n");
            jogoAtivo = 0;
        } 
        // Alterna jogador
        else {
            jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    char jogarNovamente;

    do {
        jogar();
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente);
    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    printf("Obrigado por jogar! Até a próxima!\n");
    return 0;
}
