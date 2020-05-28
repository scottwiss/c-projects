#include <stdio.h>

typedef struct 
{
    char* name;
    int votes; 
}
candidate;

// An array of candidates
candidate candidates[2];

// Function prototypes
void print_winner(void);

int main(void)
{
    candidates[0].name = "Bob";
    candidates[0].votes = 3;

    candidates[1].name = "Phil";
    candidates[1].votes = 1;

    // Print candidates
    for (int i = 0; i < 2; i++)
    {
        printf("%s ", candidates[i].name);
        printf("%i", candidates[i].votes);
        printf("\n");
    }

    print_winner();
}

void print_winner(void)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i - 1; j++)
        {
            if (candidates[j].votes > candidates[j + 1].votes)
            {
                candidate temp = candidates[j];
                candidates[j] = candidates[j + 1];
                candidates[j + 1] = temp;
            }
        }
    }
    // Print candidates after sorting
    printf("Post Sort\n");
    for (int i = 0; i < 2; i++)
    {
        printf("%s ", candidates[i].name);
        printf("%i", candidates[i].votes);
        printf("\n");
    }
}
