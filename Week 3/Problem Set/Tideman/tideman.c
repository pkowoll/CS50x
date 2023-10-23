// Problem Set 3: Tideman
// Implementation of tideman voting system.
//  by Paweł Kowoll 2023

#include <cs50.h>
#include <stdio.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
int is_cycle(int pair, int i);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    bool candidate = false; // Candidate name status

    // Validate candidate name
    for (int i = 0; i < candidate_count; i++)
    {
        int j = 0;
        if (candidate == false)
        {
            do
            {
                if (name[j] == candidates[i][j])
                {
                    candidate = true;
                }
                else
                {
                    candidate = false;
                    break;
                }
                j++;
            }
            while (name[j] != '\0' || candidates[i][j] != '\0');
            // Update ranks[] if a candidate with the name exist
            ranks[rank] = i;
        }
    }
    return candidate;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            int stronger = ranks[i];
            int weaker = ranks[j];
            preferences[stronger][weaker] += 1;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Initialize graph of clasified candidates
    bool clasified[candidate_count][candidate_count];

    // Clear graph of clasified candidates
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            clasified[i][j] = false;
        }
    }

    // Record pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // Check if there is no tie
            if (preferences[i][j] != preferences[j][i] && clasified[i][j] == false && clasified[j][i] == false)
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                }
                else if (preferences[i][j] < preferences[j][i])
                {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                }
                pair_count++;
            }
            // Update clasified graph
            clasified[i][j] = true;
            clasified[j][i] = true;
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    float strength[pair_count];
    int max;
    int currentWinner;
    int currentLoser;

    // Strength of victory
    for (int i = 0; i < pair_count; i++)
    {
        // index of winner of the i-th pair
        int m = pairs[i].winner;
        // index of loser of the i-th pair
        int n = pairs[i].loser;
        // calculated strength of victory for i-th pair
        strength[i] = (float) preferences[m][n] / (float) preferences[n][m];
    }

    // Selection sort algorithm
    for (int i = 0; i < pair_count; i++)
    {
        currentWinner = pairs[i].winner;
        currentLoser = pairs[i].loser;
        max = i + 1;

        for (int j = i + 1; j < pair_count; j++)
        {
            max = (strength[j] >= strength[max]) ? j : max;
        }
        if (strength[i] < strength[max])
        {
            pairs[i].winner = pairs[max].winner;
            pairs[i].loser = pairs[max].loser;
            pairs[max].winner = currentWinner;
            pairs[max].loser = currentLoser;
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // For each pair update the graph
    for (int i = 0; i < pair_count; i++)
    {
        int current_pair = i;
        int m = pairs[i].winner;
        int n = pairs[i].loser;

        // Before update the graph check if the pair will not form a cycle
        if (m == is_cycle(current_pair, i))
        {
            locked[m][n] = false;
        }
        else
        {
            locked[m][n] = true;
        }
    }
}

// Check if the pair will not form a cycle
int is_cycle(int pair, int i)
{
    int m = pairs[i].winner;
    int n = pairs[i].loser;

    // Search pair where n is a winner
    for (int j = 0; j < pair; j++)
    {
        // Recursive call
        if (n == pairs[j].winner)
        {
            n = is_cycle(pair, j);
        }
    }

    // Recrusion base case
    if (n != pairs[pair].loser)
    {
        if (n == pairs[pair].winner)
        {
            return n;
        }
        else
        {
            n = m;
        }
    }
    return n;
}

// Print the winner of the election
void print_winner(void)
{
    // Check which candidate has no candidates pointing to him in the graph
    int winner;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                winner = i;
            }
            else
            {
                break;
            }
        }
    }

    // Print the winner
    printf("%s\n", candidates[winner]);
}