// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    // aceitar apenas um cli argument
    if (argc > 2)
    {
        printf("Type only one word to replace!\n");
        return 1;
    }
    // se nao tiver nenhum argumento a mais que ./no-vowels printar erro e retorn 1
    if (argc == 1)
    {
        printf("To replace a word type: ./no-vowels word\n");
        return 1;
    }
    // a string passado pra replace deve ser argv[1]
    printf("%s\n", replace(argv[1]));
}

string replace(string word)
{
    // contar o tamanho do array
    int word_size = strlen(word);
    string replaced_word = word;

    // conferir cada letra da palavra
    for (int i = 0; i < word_size; i++)
    {
        // dentro do loop conferir cada caso
        switch (word[i])
        {
            case 'a':
                replaced_word[i] = '6';
                break;
            case 'e':
                replaced_word[i] = '3';
                break;
            case 'i':
                replaced_word[i] = '1';
                break;
            case 'o':
                replaced_word[i] = '0';
                break;
            default:
                replaced_word[i] = word[i];
        }
    }
    return replaced_word;
}
