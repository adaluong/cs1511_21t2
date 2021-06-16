// Program to print an asterisk the amount of times given by the user
// in a square and particular pattern

// Ada Luong June 2021

#include <stdio.h>

int main(void) {

    // Scan the size of the square we want to print
    int square_size;
    printf("What size do you want your square: ");
    scanf("%d", &square_size);

    // Creating our square of symbols
    int row = 0;
    while (row < square_size) {

        int col = 0;
        while (col < square_size) {
            
            // Creating our pattern (triangle)

            if (col >= square_size - row - 1) {
                printf("*");
            } else {
                printf("-");
            }


            col++;
        }
        
        printf("\n");
        row++;
    }
    return 0;
}


/* 

>> PATTERN FOR BARS 

if (col % 2 == 1) {
    printf("*");
} else {
    printf("-");
}

>> PATTERN FOR TRIANGLES

if (col >= square_size - row - 1) {
    printf("*");
} else {
    printf("-");
}

>> PATTERN FOR DIAGONAL

if (row == col) {
    printf("*");
} else {
    printf("-");
}

*/