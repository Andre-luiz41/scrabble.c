#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Tabela de pontos para as letras, indexada de A (0) até Z (25)
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Protótipo da função para calcular a pontuação de uma palavra
int compute_score(char word[]);

int main(void)
{
    // Variáveis para armazenar as palavras dos jogadores
    char word1[100];
    char word2[100];

    // Solicita a palavra do jogador 1
    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin);
    word1[strcspn(word1, "\n")] = '\0'; // Remove a quebra de linha

    // Solicita a palavra do jogador 2
    printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);
    word2[strcspn(word2, "\n")] = '\0'; // Remove a quebra de linha

    // Calcula os pontos para as duas palavras
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Exibe o vencedor e a pontuação
    if (score1 > score2)
    {
        printf("Player 1 wins! (%d points)\n", score1);
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins! (%d points)\n", score2);
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

// Função que calcula a pontuação de uma palavra
int compute_score(char word[])
{
    int score = 0;

    // Percorre cada caractere da palavra
    for (int i = 0; i < strlen(word); i++)
    {
        char c = toupper(word[i]); // Converte o caractere para maiúsculo

        // Verifica se o caractere é uma letra (A-Z)
        if (c >= 'A' && c <= 'Z')
        {
            // Calcula o índice na tabela de pontos (A=0, B=1, ..., Z=25)
            score += POINTS[c - 'A'];
        }
    }

    return score;
}
