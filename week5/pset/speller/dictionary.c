// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 204419;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    char wordCopy[strlen(word) + 1];
    strcpy(wordCopy, word);
    for (int i = 0; wordCopy[i] != '\0'; i++)
    {
        wordCopy[i] = tolower(wordCopy[i]);
    }

    unsigned int hash_value = hash(word);

    node *result = table[hash_value];
    while (result != NULL)
    {
        if (!strcmp(result->word, wordCopy))
        {
            return true;
        }
        else
        {
            result = result->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hashValue = 0;

    char wordCopy[strlen(word) + 1];
    strcpy(wordCopy, word);

    for (int i = 0; wordCopy[i] != '\0'; i++)
    {
        wordCopy[i] = toupper(wordCopy[i]);
        // Multiply by 31 because is prime, and give more variation for the hashes
        hashValue = (hashValue * 31 + wordCopy[i]) % N; // using % to receive in the correct interval
    }

    return (unsigned int) (hashValue % N);
    /*return toupper(word[0]) - 'A';*/
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // inicializa a tabela com 0
    for (int i = 0; i < N; i++)
    {
        table[i] = 0;
    }

    FILE *dict_file = fopen(dictionary, "r");
    if (dict_file == NULL)
    {
        return false;
    }

    char c;
    char word[LENGTH + 1];
    int index = 0;

    while (fread(&c, sizeof(char), 1, dict_file))
    {
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            word[index] = c;
            index++;
        }
        else
        {
            word[index] = '\0';
            unsigned int hash_value = hash(word);

            node *new = malloc(sizeof(node));
            strcpy(new->word, word);

            node *temp = table[hash_value];
            table[hash_value] = new;
            new->next = temp;

            index = 0;
        }
    }

    fclose(dict_file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    bool loaded = false;
    unsigned int words = 0;

    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            loaded = true;
            node *temp = table[i];
            while (temp != NULL)
            {
                words++;
                temp = temp->next;
            }
        }
    }
    if (loaded)
    {
        return words;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *temp = table[i];
            while (table[i] != NULL)
            {
                table[i] = table[i]->next;
                free(temp);
                temp = table[i];
            }
        }
    }

    return true;
}
