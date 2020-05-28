#include <stdio.h>

// Practice of different sorting strategies

typedef struct
{
    int num;
}
number;
number numbers[5];

// first sorting strat, not sure what type of sort yet
void bubble_sort(void);
int main(void)
{
    // Just an array of 5 numbers in seemingly random order
    numbers[0].num = 5;
    numbers[1].num = 3;
    numbers[2].num = 1;
    numbers[3].num = 2;
    numbers[4].num = 4;

    for (int i = 0; i < 5; i++)
    {
        printf("%i ", numbers[i].num);
    }
    printf("\n");

    bubble_sort();
}

void bubble_sort(void)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i - 1; j++)
        {
            if (numbers[j].num > numbers[j + 1].num)
            {
                int temp = numbers[j].num;
                numbers[j].num = numbers[j+1].num;
                numbers[j + 1].num = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%i ", numbers[i].num);
    }
    printf("\n");
}
