// COMP1511 Tut04 Q16 - initialising and printing an array demo
// Ada Luong, June 2021

#include <stdio.h>

#define SIZE 5

int main (void) {

    int number = 0;

    // declaring and initialising an array 
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;
    int num4 = 4;
    int num5 = 5;

    ///
    int array[SIZE] = {1, 2, 3, 4, 5};
    ///

    int array2[SIZE] = {1, 2, 3, 0, 0};
    int array_zero[SIZE] = {0};

    // printing every element of an array
    //int first_element = array[0];
    //printf("%d\n", first_element);

    int i = 0;
    while (i < SIZE) {

        printf("%d\n", array[i]);

        i++;
    }



    return 0;
}

/* THINGS TO KEEP NOTE OF
 * Declaring variable type
 * Naming the array
 * Size of the array
 * Initialising elements
 * Initialising all elements to zero 
 * Printing elements of an array
 * Printing in a function
 */