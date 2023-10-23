// Lab 2: Scrabble
// Determine which of two Scrabble words is worth more.
//  by Paweł Kowoll 2023

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print if player 1 wins
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    // Print if player 2 wins
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    // Trint if it is a tie
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int i = 0;
    int score = 0;

    do
    {
        int c = word[i];
        // Score lowercase letters
        if (islower(c))
        {
            score += POINTS[c - 97];
        }
        // Score uppercase letters
        else if (isupper(c))
        {
            score += POINTS[c - 65];
        }
        // Every other characters have 0 points
        else
        {
            score += 0;
        }
        i++;
    }
    while (word[i] != '\0');
    return score;
}