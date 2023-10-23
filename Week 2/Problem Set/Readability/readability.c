// Problem Set 2: Readability
// Calculate the approximate grade level needed to comprehend some text.
//  by Paweł Kowoll 2023

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// Function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for text to analize
    string text;
    do
    {
        text = get_string("Text: ");
    }
    while (text[0] == '\0' || count_sentences(text) <= 0); // PROBLEM: if input text has 0 sentences prompt again.

    // Calculate avreage number of letters per 100 words
    float L = ((float) count_letters(text) / (float) count_words(text)) * 100;

    // Calculate avreage number of sentences per 100 words
    float S = ((float) count_sentences(text) / (float) count_words(text)) * 100;

    // Colleman-Liau index
    float index = ((0.0588 * L) - (0.296 * S)) - 15.8;

    // Print out calculated grade
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade: %1.f\n", index);
    }
}

// Letter count function
int count_letters(string text)
{
    int i = 0;
    int letters = 0;

    do
    {
        char c = text[i];
        (islower(c) || isupper(c)) ? letters++ : letters;
        i++;
    }
    while (text[i] != '\0');
    return letters;
}

// Word count function
int count_words(string text)
{
    int i = 0;
    int words = 0;
    bool isWord = false;
    do
    {
        char c = text[i];
        (c == ' ') ? words++ : words;
        i++;
    }
    while (text[i] != '\0');
    words++;
    return words;
}

// Sentence count function
int count_sentences(string text)
{
    int i = 0;
    int sentences = 0;
    do
    {
        char c = text[i];
        (c == '.' || c == '!' || c == '?') ? sentences++ : sentences;
        i++;
    }
    while (text[i] != '\0');
    return sentences;
}