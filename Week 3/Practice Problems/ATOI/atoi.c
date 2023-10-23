// Practice Problems 3: Recursive atoi
// Practice with creating recursive functoins and deepen understanding of strings.
//  by Paweł Kowoll 2023

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int atoi(string input);
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
    int n = strlen(input);

    if (input[n + 1] == '\0')
    {
        return atoi(input); // Base case
    }
    else
    {
        return convert(input - 1); // Recursive call
    }
}