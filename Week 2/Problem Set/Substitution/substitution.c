// Problem Set 2: Substitution
// Simple program to encrypt a message by replacing every letter with another letter from the key.
// To encrypt a message type: ./substitution KEY, where KEY is a 26-characters key from which letters will be replaced.
// Then type a plaintext you want to encrypt and then you get ciphertext.
//  by Paweł Kowoll 2023

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// Determinating the key length
#define keyLength 26 // English alphabet has 26 letters, so the key has to be 26

// Global variables:
char key[keyLength];

// Function prototypes:
bool validate(string argv);
string encrypt(string plaintext);

int main(int argc, string argv[])
{
    // Check if the key is the only one argument
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    // Validate the key
    else if (validate(argv[1]) == false)
    {
        printf("Error: Key must contain %i letters!\n", keyLength);
        return 1;
    }
    // Prompt the user for plaintext if no errors
    else
    {
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: %s\n", encrypt(plaintext));
    }
}

bool validate(string argv)
{
    int i = 0;
    int j;
    bool status = false;

    do
    {
        // Change all the key letters to uppercase
        char c = toupper(argv[i]);
        j = 0;
        do
        {
            // Check the key characters
            if (isupper(c))
            {
                // Check if characters of the key are repeating
                if (c != key[j])
                {
                    status = true;
                }
                else
                {
                    status = false;
                    return status;
                }
                j++;
            }
            // Key contain characters that are not letters
            else
            {
                status = false;
                return status;
            }
        }
        while (key[j] != '\0');
        key[i] = c;
        i++;
        // Check key length
        (i != keyLength) ? status = false : status;
    }
    while (argv[i] != '\0');
    return status;
}

string encrypt(string plaintext)
{
    int i = 0;
    string ciphertext = plaintext;
    do
    {
        int c = plaintext[i];
        // Encrypt uppercase letters
        if (isupper(c))
        {
            c = key[c - 65];
            ciphertext[i] = c;
        }
        // Encrypt lowercase letters
        else if (islower(c))
        {
            c = key[c - 97];
            ciphertext[i] = tolower(c);
        }
        // Don't encrypt every other characters
        else
        {
            ciphertext[i] = c;
        }
        i++;
    }
    while (plaintext[i] != '\0');
    return ciphertext;
}