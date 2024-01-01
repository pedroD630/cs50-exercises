#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // base case: lenght == 0; return 0
    int lenght = strlen(input);

    if (lenght == 0)
    {
        return 0;
    }

    // get last char ( lenght - 1 )
    int last_char = lenght - 1;

    int convert_last = input[last_char] - '0';
    // convert char in int ( char - '0' will print the value of distance between 0 and the numeric char, resulting in a int value)

    // remove last char ( change \0 position to the actual index )
    input[last_char] = '\0';

    // return the converted digit + 10 * convert() passing the new string without the last
    // need to make * 10 because is decimal number
    // if we are on the last, it will be a unity + 10 times the decimal value + 10 times the hundred value
    // to this make sense think in a group of friends that one needs to whait the other to got travel
    // the other needs to wait other, and other, until one of the friends leave home with the car and take all in reverse order
    return convert_last + 10 * convert(input);
}
