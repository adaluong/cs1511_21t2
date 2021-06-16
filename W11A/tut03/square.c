// Program to print an asterisk the amount of times given by the user
// as a square

// Ada Luong March 2021

#include <stdio.h>

int main(void) {

    // Scan the size of the square we want to print
    int square_size;
    printf("What size do you want your square: ");
    scanf("%d", &square_size);

    // Creating our square of asterisks
    int row = 0;
    while (row < square_size) {

        // Ensure this second col counter is INSIDE the while loop
        // so it resets to 0 each time we go through the first while loop

        int col = 0;
        
        // Printing a horizontal line of asterisks with this while loop
        while (col < square_size) {
        
            printf("%d %d |", col, row);
            col++;
        
        }
        
        // Going to the next row
        printf("\n");
        row++;
    }

    return 0;
}