// Practice Problems 2: Hours
// Practice with arrays, passing arrays as parameters to a functions, integer division and type casting.
//  by Paweł Kowoll 2023

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// calc_hours function declaration
float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// Defining a calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    float calc = 0;

    for (int i = 0; i < weeks; i++)
    {
        calc = calc + hours[i];
    }

    if (output == 'A')
    {
        calc = calc / weeks;
        return calc;
    }
    else
    {
        return calc;
    }
}