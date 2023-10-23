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

float half(float bill, float tax, int tip)
{

    // Calculating bill tax
    tax = (tax / 100) * bill;
    // Adding tax to the bill
    bill = bill + tax;
    // Calculating tip of the bill and tax
    float tipF = ((float) tip / 100) * bill;
    // Divide the total of bill, tax and tip by 2
    bill = (bill + tipF) / 2;

    return bill;
}