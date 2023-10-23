// Practice Problems 2: Password
// Simple program that check if password has at least one lowercase letter, uppercase letter, number and symbol.
// Practice iterating through a stringm, using the ctype library and using Boolean variables.
//  by Paweł Kowoll 2023

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

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

bool valid(string password)
{
    bool lowercase = false;
    bool uppercase = false;
    bool number = false;
    bool symbol = false;
    int i = 0;

    do
    {
        char c = password[i];
        // Check for lower caseletter in all string elements
        if (islower(c))
        {
            lowercase = true;
        }
        // Check for uppercase letter in all string elements
        else if (isupper(c))
        {
            uppercase = true;
        }

        else if (isdigit(c))
        {
            number = true;
        }
        // If the checked string element is not lowercase letter or uppercase letter or number is a symbol
        else
        {
            symbol = true;
        }
        i++;
    }
    while (password[i] != '\0');
    // Return true if all criteria are met
    if (lowercase == true && uppercase == true && number == true && symbol == true)
    {
        return true;
    }
    // Or return false if not
    else
    {
        return false;
    }
}