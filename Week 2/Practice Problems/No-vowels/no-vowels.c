// Practice Problems 2: N0 V0w3ls
// Convert word to "leetspeak" with command-line arguments.
// Practice with strings, command-line arguments and switch-case statements.
//  by Paweł Kowoll 2023

#include <cs50.h>
#include <stdio.h>

// Declaration of function that will replace 'a' to '6', 'e' to '3', 'i' to '1' and 'o' to '0'
string replace(string argv);

int main(int argc, string argv[])
{
    // Print an error if there is no just one command-line argument after program call.
    if (argc != 2)
    {
        printf("Error: missing command-line argument!\nUsage: ./no-vowels word\n");
        return 1;
    }
    else
    {
        printf("%s\n", replace(argv[1]));
    }
}

string replace(string word)
{
    int i = 0;
    // Loop for replacing individual letters to leetspeak
    do
    {
        switch (word[i])
        {
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
        }
        i++;
    }
    while (word[i] != '\0'); // null - end of string.
    // return converted string
    return word;
}