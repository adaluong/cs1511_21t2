// COMP1511 Tut05 - Pointers
// Program to demonstrate that the address of the first element of the array
// is equal to the address of the array
// Ada Luong, March 2021

#include <stdio.h>

#define SIZE 5

int main(void) {

    int fav_numbers[SIZE] = {1, 2, 3, 4, 5};

    int *array_pointer = &fav_numbers;
    int *array_index0_pointer = &fav_numbers[0];
    int *array_index1_pointer = &fav_numbers[1];

    printf("%p is the address of the array\n", array_pointer);
    printf("%p is the address of the 1st element of the array\n", array_index0_pointer);
    printf("%p is the address of the 2nd element of the array\n", array_index1_pointer);

    return 0;
}

/* NOTES
 * When you pass an array into a function, you are actually passing in a 
 * POINTER to the array, which is why the original array is modified
 * whenever you modify the array within the function
 */ 