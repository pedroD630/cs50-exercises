#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    // usar ctype e converter tudo pra maiusculo ( sem printar )
    int word_lenght = strlen(word);
    for (int i = 0; i < word_lenght; i++)
    {
        word[i] = toupper(word[i]);
    }

    int ascii_values[word_lenght];
    // converter cada letra da string para o seu codigo no ascii
    for (int i = 0; i < word_lenght; i++)
    {
        ascii_values[i] = (int) word[i];
    }

    int word_points[word_lenght];

    // loop 1: rodar a palavra inteira com o lenght
    // loop 2: pegar o ascci da letra, i = 65 e vai ate 90. Criar uma nova variavel de contagem
    // que a cada vez que o loop roda aumentada de 0 a frente. se o i = ascii da letra,
    for (int i = 0; i < word_lenght; i++)
    {
        if (isalpha(word[i]))
        {
            int count = 0;
            for (int j = 65; j != ascii_values[i]; j++)
            {
                count++;
            }
            // A pontuação para aquela letra pode ser achada usando a contagem como index pro array de pontos
            word_points[i] = POINTS[count];
        }
        else
        {
            word_points[i] = 0;
        }
    }
    // Somar ao fim todos os pontos desse array e retornar
    int sum = 0;
    for (int i = 0; i < word_lenght; i++)
    {
        sum = sum + word_points[i];
    }

    return sum;
}
