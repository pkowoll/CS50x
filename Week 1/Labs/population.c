// Lab 1: Population Growth
// Determine how long it takes for a population to reach a particular size.
//  by Paweł Kowoll 2023

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int startSize;
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);

    // Prompt for end size
    int endSize;
    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);

    // Calculate number of years until we reach threshold
    int born;
    int passAway;
    int years = 0;
    if (startSize < endSize)    // Check if start size is smaller than end size to make calculations
    {
        do
        {
            born = startSize / 3;
            passAway = startSize / 4;
            startSize = startSize + born - passAway;
            years++;
        }
        while (startSize < endSize);
    }
    else    // Assign years = 0 when start size is equal to end size
    {
        years = 0;
    }

    // Print number of years
    if (startSize >= endSize)
    {
        printf("Years: %i\n", years);
    }

}