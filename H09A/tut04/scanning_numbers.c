// COMP1511 Tut04 25/26 - scanf and arrays
// Ada Luong, June 2021

// Creating a loop that would continually read values in from standard input 
// until the user inputs anything other than a number (or the input ends).

// Integers scanned in are placed into an array called inputs of size 1000
// Assume no more than 1000 numbers will be entered

#include <stdio.h>

#define SIZE 1000

int main (void) {

    printf("Enter a number: ");

    int inputs[SIZE] = {0};

    int index = 0;
    while (scanf("%d", &inputs[index]) == 1) {
        index++;
    }
    
    return 0;
}
