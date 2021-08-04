// COMP1511 Tut09 - Recursion 
// A function which returns the nth factorial
// Ada Luong, August 2021

#include <stdio.h>

int factorial(int n);

int main(void) {

    printf("%d\n", factorial(1));
    printf("%d\n", factorial(2));
    printf("%d\n", factorial(3));
    printf("%d\n", factorial(4));
    printf("%d\n", factorial(5));

    return 0;
}

int factorial(int n) {

    if (n == 0) {
        return 1;
    }

    return n * factorial(n - 1);
}