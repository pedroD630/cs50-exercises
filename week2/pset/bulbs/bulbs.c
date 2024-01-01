#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
int getAscii(char symbol);

int main(void)
{

    // TODO
    // get a message
    string message = get_string("Type a message to convert:\n");
    int message_lenght = strlen(message);
    // encode text sequence as binary:

    // convert a char in ascii
    int ascii[message_lenght];
    for (int i = 0; i < message_lenght; i++)
    {
        ascii[i] = getAscii(message[i]);
    }

    int binary[8];
    // convert ascii in binary
    for (int i = 0; i < message_lenght; i++)
    {
        int value = ascii[i];
        int result = value;
        // get the binary
        for (int j = 0; j < 8; j++)
        {
            int remainder = result % 2;
            binary[j] = remainder;
            result = result / 2;
        }
        // invert binary
        int invert_binary[8];
        int z = 0;
        for (int k = 7; k >= 0; k--)
        {
            invert_binary[z] = binary[k];
            z++;
        }
        // print the bulbs
        for (int x = 0; x < 8; x++)
        {
            print_bulb(invert_binary[x]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
int getAscii(char symbol)
{
    int ascii_code = (int) symbol;
    return ascii_code;
}
// PSEUDOCODE ( other parts i pasted on the code )
//  take the number
//  divide by 2
//  save the remainder
//  take the int result of division until the result = 0
//  repeat the process and divide the actual result by 2, saving the remainders in a array
//  on the final of the process, print the numbers in reverse order
// print the char in bulbs format
// if is 0 -> light off
// if is 1 -> light is on
// each char needs have one line and \n
