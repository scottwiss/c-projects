#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Array of winners
candidate winners[MAX];

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
    // Cycle through canidates array, if name is in canidates return true. Need to search better.
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes +=1;
            return true;
        }

    }
     return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
     // Sort candidates from least votes to most votes
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count - i - 1; j++)
        {
            if (candidates[j].votes > candidates[j + 1].votes)
            {
                // Bubble sort that swaps each candidate to sort lowest to highest votes
                candidate temp = candidates[j];
                candidates[j] = candidates[j + 1];
                candidates[j + 1] = temp;
            }
        }
    }
    // Highest votes recieved
    int winning_votes = candidates[candidate_count-1].votes;
    // Prints all candidates with the the winning vote total
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == winning_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

