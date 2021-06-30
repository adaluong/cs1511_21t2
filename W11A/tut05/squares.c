// COMP1511 Tut05 - 2D Arrays
// Modifying squares.c into a 2D array 
// Ada Luong, June 2021

#include <stdio.h>

#define SIZE 7

void print_array(int rows, int columns, int array[rows][columns]);

int main(void) {

    int row, column;

    int array[SIZE][SIZE];

    row = 0;
    while (row < SIZE) {
        column = 0;
        while (column < SIZE) {
            array[row][column] = 1;
            column = column + 1;
        }
        row = row + 1;
    }

    print_array(SIZE, SIZE, array);

    return 0;
}

// Function to print the array
void print_array(int rows, int columns, int array[rows][columns]) {
    int r = 0;
    while (r < rows) {
        int c = 0;
        while (c < columns) {
            printf("%d", array[r][c]);
            c++;
        }
        printf("\n");
        r++;
    }
    printf("\n");
}

/* DISCUSSION POINTS
 - What are the benefits of storing the values of the grid in a 2D array?
 --- Easily modify elements in the array
 */