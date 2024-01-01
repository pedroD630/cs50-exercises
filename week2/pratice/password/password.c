// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int pass_size = strlen(password);
    bool haveLower = false;
    bool haveSym = false;
    bool haveNum = false;
    bool haveUpper = false;

    // the passwords need have one lowercase, one uppercase, one number and one symbol
    for (int i = 0; i < pass_size; i++)
    {
        if(islower(password[i]))
        {
            haveLower = true;
        }
        else if (isupper(password[i]))
        {
            haveUpper = true;
        }
        else if (isdigit(password[i]))
        {
            haveNum = true;
        }
        else if (isdigit(password[i]) == false && isalpha(password[i]) == false)
        {
            haveSym = true;
        }
    }

    // if all the criteria are true return true

    if (haveLower == true && haveUpper == true && haveNum == true && haveSym == true)
    {
        return true;
    }
    else{
        return false;
    }

}
