// COMP1511 Tut05 - Pointers
// A short program to illustrate how pointers work
// Ada Luong, March 2021

#include <stdio.h>

int main(void) {

    // create an integer num
    int num = 21;

    // create a pointer which stores the address of num
    int *pointer = &num;

    // print the address of num
    printf("the address of num is %p\n", &num);
    printf("the address of num is %p\n", pointer);

    // printing the address of pointer
    printf("the address of pointer is %p\n", &pointer);

    // dereference the pointer
    printf("the value of num is %d\n", num);
    printf("the value of num is %d\n", *pointer);

    return 0;
}

/* THINGS TO KEEP NOTE OF

 * Pointers are just variables 
   - It stores memory addresses of other variables
   - Like any other variable, you have to declare it
   - It is always aimed at a particular type
   --- eg int * holds the address of an integer variable
   --- double * holds the address of a float variable

 * There are three reasons why we use the * symbol in C
   - Multiplication             | x*y
   - Declaring a pointer        | type *
   - Dereferencing a pointer    | *pointer

 * The & symbol reads as "address"
   - Pointers store the address of the variable it points to
   --- This is similar to the way an int variable stores the number 10
   - You can also get the address of a non-pointer variable with &variable

 * When you "dereference" a pointer you get the VALUE that is stored in the memory location
   - You do this with the operator * (eg. *pointer)
   - *num = the value of num (eg. 5)
 */