#include <stdio.h>
#include <cs50.h>

int main(void){
    string name = get_string("Type a name:");
    int age = get_int("Type an age:");
    long phoneNumber = get_long("Type a phone number:");

    printf("Confirm the values: \nName: %s\nAge: %i\nPhone Number: %li\n", name, age, phoneNumber);
}
