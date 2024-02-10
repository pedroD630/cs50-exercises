#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    int size;
    int biggernum;
}
choices;

void generate_ramdom(int numbers[], int max, int size);
int convertto_int(string argument);

int main(int argc, string argv[])
{
    choices user_choices;
    int result, score;
    // receive in cli: list size and the max number of the list
    // if dont have 3 or have more than 3 comands: print usage help
    if (argc < 3 || argc > 3)
    {
        printf("Usage help:\n ./linear <ramdom list size> <max number of list>\n");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        if (i==1)
        {
            user_choices.size = convertto_int(argv[i]);
        }
        else
        {
            user_choices.biggernum = convertto_int(argv[i]);
        }
    }

    // generate a ramdom list with the user size and put random numers less than the max number
    int ramdom_numbers[user_choices.size];
    generate_ramdom(ramdom_numbers, user_choices.biggernum, user_choices.size);

    // receive the user number
    int user_guess = get_int("Try to match all the random numbers!\n Type here your guess: ");
    printf("\n");


    // use linear search for check if the user number is on the list. PRINT THE NUMBER OF STEPS
        // if is on the list print: you find! and add one point
            // call the function again, recursively, ask for another number and search on the same list
        // else: print you dont find, try again.
    // use binary search for check if the number is the list
        // sort the array with:
            // selection sort
            //bubble sort
            // merge sor
}

int convertto_int(string argument)
{
    return atoi(argument);
}

void generate_ramdom(int numbers[], int max, int size)
{
    for (int i = 0; i < size; i++)
    {
        numbers[i] = rand() % (max + 1);
    }
}
