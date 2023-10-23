// Problem Set 1: Mario - adjacent pyramids
// Draw a two adjacent pyramids with a height defined by user.
//  by Paweł Kowoll 2023

#include <cs50.h>
#include <stdio.h>

int get_height(void);
void drawPyramid(int height);

int main(void)
{
    // Using get_height function prompt for height of pyramids.
    int height = get_height();
    // Draw adjacent pyramids using drawPyramid function.
    drawPyramid(height);
}


// Function to execute pyramid height
int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

// Function to draw pyramid
void drawPyramid(int height)
{
    const int gap = 2;
    int block = 1;
    int blankBlock;

    for (int i = 0; i < height; i++)
    {
        blankBlock = height - block;
        for (int j = 0; j < blankBlock; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < block; k++)
        {
            printf("#");
        }
        for (int l = 0; l < gap; l++)
        {
            printf(" ");
        }
        for (int m = 0; m < block; m++)
        {
            printf("#");
        }
        printf("\n");
        block++;
    }
}