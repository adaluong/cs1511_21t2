// COMP1511 Tut09 - Recursion 
// A function which returns the nth fibonacci number
// Ada Luong, August 2021

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);
int fibonacci_iterative(int n);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("USAGE: ./fibonacci n\n");
        return 1;
    } 

    int num = atoi(argv[1]);

    int fib = fibonacci(num);
    printf("fibonacci number #%d is... %d\n", num, fib);

    return 0;
}

// FIBONACCI SEQUENCE - 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...

// fibonacci(0) = 0
// fibonacci(3) = 2
//

// Recursive approach
int fibonacci(int n) {
    printf("calling function for %d\n", n);
    // Base Case(s)
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Iterative approach for comparison
int fibonacci_iterative(int n) {

    int a = 0;
    int b = 1;

    int i = 0;
    while (i < n) {

        int new_b = a + b;

        a = b;
        b = new_b;

        i++;
    }

    return a;
}
