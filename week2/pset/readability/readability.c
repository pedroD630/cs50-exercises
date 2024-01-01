#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text, int lenght);
int count_words(string text, int lenght);
int count_sentences(string text, int lenght);
int calculate_grade(int letters, int words, int sentences);

int main(void)
{
    string text = " ";
    do
    {
        text = get_string("Type a text:\n");
    }
    while (!strcmp(text, " ") || !strcmp(text, ""));

    // get the lenght of the text
    int text_lenght = strlen(text);

    // count the letters of the text
    int num_letters = count_letters(text, text_lenght);
    // count the words of the text
    int num_words = count_words(text, text_lenght);
    // count the sentences of the text
    int num_sent = count_sentences(text, text_lenght);

    int grade = calculate_grade(num_letters, num_words, num_sent);

    // Print the result of the formula in a integer like: Grade X
    // if is < 1 print: Before grade 1
    // if > graqde 16 print: Grade 16+
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text, int lenght)
{
    int letters = 0;

    // loop: for each char check if is alphabethical, if yes increase the num of letters, if no, repeat on next
    for (int i = 0; i < lenght; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}
int count_words(string text, int lenght)
{
    int words = 0;

    // loop: sempre que tiver um espaço contar uma palavra
    for (int i = 0; i < lenght; i++)
    {
        if (isblank(text[i]))
        {
            // se o indice [0] for espaco, words = words
            if (!(i == 0) || (isblank(text[i]) && !isblank(text[i - 1])))
            {
                words++;
            }
        }
    }
    // se words = 0, nao achou nenhum espaço, logo deve ter uma palavra. A ultima palavra nao tem espaço + 1
    words += 1;

    return words;
}
int count_sentences(string text, int lenght)
{
    int sentences = 0;
    // rodar a string toda, se o caractere for !, ., ? adicionar +1
    for (int i = 0; i < lenght; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}
int calculate_grade(int letters, int words, int sentences)
{
    // use the formula, but first get:
    // L = average of leeter / words * 100
    float l = ((float) letters / (float) words) * 100;

    // S = average of sentences / words * 100
    float s = ((float) sentences / (float) words) * 100;

    double index = 0.0588 * l - 0.296 * s - 15.8;
    int grade = round(index);

    printf("%f, %f, %f, %i\n", s, l, index, grade);

    return grade;
}
