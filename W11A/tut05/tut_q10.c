// COMP1511 Tut05 (Q9) - Pointers 
// Note: This program won't compile or run
// Ada Luong, June 2021

int n = 42; // Creating a variable n which stores integer 42
int *p      // Creating two pointers p and q
int *q;     // which point to integers
 
p = &n;     // Now, the pointer p contains the address of n

*p = 5;     // Derefence p and assign it the value 5. 
            // n = 5
            // p = &n

*q = 17;    // Dereference q and assign it the value 17
            // This line will throw and error

q = p;      // Assign the pointer q to equal p
            // q = p = &n

*q = 8;     // Dereference q and assign it the value of 8
            // q = &n
            // n = 8
