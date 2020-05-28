#include <stdio.h>
#include <stdlib.h>

// Find the factoral of a number using recursion

// Function prototypes
int fact(int n);

int main(int argc, char* argv[]) {

    if (argc > 2){
        printf("Enter a number...");
        return 1;
    }
    
    else{
        printf("%i", fact(atoi(argv[1])));
    }
}
// Factoral function that uses recursion
int fact(int n) {
    if (n == 0) 
        return 1;
    else
        return n * fact(n-1);
}