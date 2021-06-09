// COMP1511 - Floating Point Error Example
// Ada Luong, June 2021

#include <stdio.h>

int main(void) {

    double frac = 10.1;

    printf("The fraction is: %.1lf\n", frac);
    printf("The fraction is: %.21lf\n", frac);

    return 0;
}

/* FLOATING POINT ERROR NOTES
-- Floating point numbers aren't stored perfectly
-- What are the implications? (Don't check exact values of floats in if statements)
*/