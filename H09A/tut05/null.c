// COMP1511 Tut05 - Common Pointer Error
// Dereferencing a NULL pointer
// Ada Luong, March 2021

#include <stdio.h>

int main(void) {

    int *p = NULL;
    printf("the address of p is %p\n", p);

    // This line will throw an error because you are 
    // dereferencing a NULL pointer
    *p = 10;

    // This line will also throw an error for the same reason
    printf("p is pointing at %d", *p);
    
    return 0;
}