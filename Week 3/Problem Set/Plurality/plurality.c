// Problem Set 3: Plurality
// Complete the implementation of plurality.c in such a way that the program simulates a plurality vote election.
//  by Paweł Kowoll 2023

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    bool search = false;
    for (int i = 0; i < candidate_count; i++)
    {
        // Search the array for name
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Update votes and set return condition
            candidates[i].votes++;
            search = true;
            break;
        }
        else
        {
            search = false; // Name is not found in the array
        }
    }
    return search;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Initialize votes variable with the votes of first candidate
    int votes = candidates[0].votes;

    // Find the max value of votes
    for (int i = 0; i < candidate_count; i++)
    {
        votes = (votes < candidates[i].votes) ? candidates[i].votes : votes;
    }
    // Comparison of the maximum value of votes with all votes of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        if (votes == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name); // Print out winner or winners
        }
    }
}