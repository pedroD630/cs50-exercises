// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    //convert percentage to decimal
    tax = tax/100;
    float percent_tip = (float) tip / 100;

    float taxed_value = bill + ( bill * tax);
    float total_value = taxed_value + ( taxed_value * percent_tip );

    float half_value = total_value / 2;

    return half_value;
}
