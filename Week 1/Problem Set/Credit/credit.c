// Problem Set 1: Credit
// Simple script to validate the credit card number
//  by Paweł Kowoll 2023

#include <cs50.h>
#include <stdio.h>

long get_number(void);
void validate(long number);

int main(void)
{
    long number = get_number();

    // Last digit variable initialization
    long i = 10;
    long modulo = 0;
    long digit = 0;
    long x = 0;

    // Second-to-last digit variable initialization
    long j = 1;
    long secondModulo = 0;
    long secondDigit = 0;
    long x2 = 0;

    // Main loop (Luhn's Algorithm)
    while ((modulo % number != 0 && secondModulo % number != 0) || (digit == 0 && secondDigit == 0))
    {
        // Using modulo operator (%) get the last number
        modulo = number % i;
        if (modulo == 0)
        {
            digit = 0;
        }
        else
        {
            digit = (modulo - secondModulo) / j;
        }
        j = i * 10;

        // Calculate checksum of last digit
        x = x + digit;

        // Using modulo operator (%) get the second-to-last number
        secondModulo = number % j;
        if (secondModulo == 0)
        {
            secondDigit = 0;
        }
        else
        {
            secondDigit = (secondModulo - modulo) / i;
        }
        i = j * 10;

        // Calculate checksum of second-to-last digit
        if (secondDigit * 2 >= 10)
        {
            x2 = x2 + (((secondDigit * 2) - ((secondDigit * 2) % 10)) / 10) + ((secondDigit * 2) % 10);
        }
        else
        {
            x2 = x2 + (secondDigit * 2);
        }
    }
    // Validate card number if the checksum is 0
    if (((x + x2) % 10) == 0)
    {
        validate(number);
    }
    else
    {
        printf("INVALID\n");
    }
}

// Prompt for credit card number function
long get_number(void)
{
    long number;

    do
    {
        number = get_long("Number: ");
    }
    while (number < 1 || number > 9999999999999999);
    return number;

}

// Validate card length and starting numbers function
void validate(long number)
{
    if (number >= 4000000000000 && number <= 4999999999999)
    {
        printf("VISA\n");
    }
    else if ((number >= 340000000000000 && number <= 349999999999999) || (number >= 370000000000000 && number <= 379999999999999))
    {
        printf("AMEX\n");
    }
    else if (number >= 4000000000000000 && number <= 5599999999999999)
    {
        if ((((number % 10000000000000000) - (number % 1000000000000000)) / 1000000000000000) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("MASTERCARD\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}