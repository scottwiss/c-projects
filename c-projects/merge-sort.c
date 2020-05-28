#include <stdio.h>

#define SIZE 9
// Function prototypes
void print_array(int array[]);
void merge(int array[], int l, int m, int r);
void merge_sort(int array[], int l, int r);

int main(void)
{
    int nums[SIZE] = {5, 2, 1, 7, 6, 4, 9, 8, 3};

    print_array(nums);
    merge_sort(nums, 0, SIZE-1);
    print_array(nums);
}

// Prints all elements in an array in a single line with spaces between elements
void print_array(int array[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}

void merge(int array[], int l, int m, int r)
{
    // Initialize needed variabls
    int i; int j; int k;
    // Assign size of L and R temp arrays
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays for left and right side
    int L[n1];
    int R[n2];

    // Copy data from array to L and R temp arrays
    for (i = 0; i < n1; i++)
    {
        L[i] = array[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = array[m + 1 + j];
    }

    // Merge L and R array into array, in order of least to greatest
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged array (usually 0, but could be different)

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L and R to array if there are any. (I'm not sure how there would be)
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    while (i < n1)
    {
        array[k] = R[j];
        j++;
        k++;
    }

}

void merge_sort(int array[], int l, int r)
{
    if (l < r)
    {
        //Find m element
        int m = (l + r) / 2;

        //Merge sort left half
        merge_sort(array, l, m);

        //Merge sort right half
        merge_sort(array, m + 1, r);
        
        //Merge the halves
        merge(array, l, m, r);
    }
}
