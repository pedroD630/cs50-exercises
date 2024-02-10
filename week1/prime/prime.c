#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    bool isPrime = true;

    if ( number == 1 ){
        isPrime = false;
        return isPrime;
    }
    
    for (int i = 2; i <number; i++)
    {
        if ( number % i == 0 ){
            isPrime = false;
        }
    }
    return isPrime;
}
