// Practice Problems 3: Max
// Practice writing a function to find a max value
//  by Paweł Kowoll 2023

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    // Prompt the user for array size
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    // Prompt the user for array values
    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    // Using function max, check the maximum value in the array
    printf("The max value is %i.\n", max(arr, n));
}

int max(int array[], int n)
{
    int max = array[0]; // Set the first element of the array as a first max value
    // Compare each element of the array
    for (int i = 0; i < n; i++)
    {
        max = (max < array[i]) ? array[i] : max;
    }
    return max;
}