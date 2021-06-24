// COMP1511 Tut04 Q19 - accessing element of array
// Ada Luong, June 2021

// Writing a function called first_plus_third that sums the first and third 
// element of an array called numbers and returns the answer.

#include <stdio.h>

#define SIZE 2

int first_plus_third(int numbers[SIZE], int size);

int main (void) {

    int numbers[SIZE] = {1,2};
    
    int result = first_plus_third(numbers, SIZE);
    printf("%d\n", result);

    return 0;
}

int first_plus_third(int numbers[SIZE], int size) {

    if (size <= 2) {
        return -1;
    }
    
    int sum = numbers[0] + numbers[2];
    return sum;
}

/* DISCUSSION (TUT Q20)

If an array is declared as int numbers[20]; and 
your program assigns a value to each element in the array, 
what's the problem with the statement x = numbers[20];?

*/