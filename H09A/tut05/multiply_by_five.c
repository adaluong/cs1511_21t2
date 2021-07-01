// COMP1511 Tut05 - Pointers
// Program to demonstrate pass by value vs pass by reference 
// Multiplying an integer by five within two void functions
// Ada Luong, March 2021

#include <stdio.h>

void multiply_by_five(int a);
void multiply_by_five_pointer(int *b);

int main(void) {

    int a = 5; 
    int c = 5;

    multiply_by_five(a);
    printf("%d\n", a);

    int b = 5;
    multiply_by_five_pointer(&b);
    printf("%d\n",b);

    return 0;
}

// This is a void function (no return value) that takes in an integer
// and multiplies it by five
void multiply_by_five(int a) {

    /*
    In the first example, a COPY of the variable 'a' is created and modified.
    It does not modify the original variable a passed in from man.

    Since this value is not RETURNED, it just disappears into memory,
    never 2 be seen again. 
    */

    a = a * 5;
}

// This is a void function that takes in a POINTER TO AN INTEGER (address of b),
// dereferences the pointer, and then modifies the original variable b
void multiply_by_five_pointer(int *b) {

    // The function modifies the ORIGINAL variable b

    *b = *b * 5;
}