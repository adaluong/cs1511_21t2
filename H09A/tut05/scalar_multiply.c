// COMP1511 Tut05 - 2D Arrays
// A function that takes in a 2D array of ints and multiplies
// every value in the array by a given int
// Ada Luong, March 2021

#include <stdio.h>

#define ROWS    3
#define COLUMNS 3

void scalar_multiply(int num_of_rows, int num_of_columns, int matrix[ROWS][COLUMNS], int scalar);
void print_matrix(int rows, int columns, int matrix[rows][columns]);

int main(void) {
    int matrix[ROWS][COLUMNS] = {{1,2,3},
                                {4,5,6},
                                {7,8,9}};

    printf("original matrix:\n");
    print_matrix(ROWS,COLUMNS,matrix);

    scalar_multiply(ROWS, COLUMNS, matrix, 3);
    
    printf("new matrix:\n");
    print_matrix(ROWS,COLUMNS,matrix);

    return 0;
}

// Loop through a 2D array and multiply every element by a given scalar
void scalar_multiply(int num_of_rows, int num_of_columns, int matrix[ROWS][COLUMNS], int scalar) {
    int row = 0;
    while (row < num_of_rows) {

        int col = 0;
        while (col < num_of_columns) {

            matrix[row][col] *= scalar;

            col++;
        }

        row++;
    }


}

// Function to print a 2D array
void print_matrix(int rows, int columns, int matrix[rows][columns]) {
    int r = 0;
    while (r < rows) {
        int c = 0;
        while (c < columns) {
            printf("%d ", matrix[r][c]);
            c++;
        }
        printf("\n");
        r++;
    }
    printf("\n");
}