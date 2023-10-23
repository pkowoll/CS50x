// Prime numbers generator
// Practice using for loops, using modulo, creating a Boolean function.

#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    // Using do-while loop to ask when "min" input > 1
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    // Using do-while loop to ask when "max" input >= "min"
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // Main function for testing numbers from user input range.
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
    // Test every number > 1 if they have a reminder.
    if (number > 1)
    {
        for (int i = 2; i < number; i++)
        {
            if (number % i == 0)
            {
                number = false; // Asign false argument to "number"
                break;  // Stop the loop when number has no reminder
            }
        }
    }
    else
    {
        number = false;
    }
    return number;
}