#include <stdio.h>

// Write a void function which places the sum of two numbers 
// inside a variable passed in by reference.

int add_two_numbers(int a, int b);
void sum_nums_pointer(int a, int b, int *sum);

int main (void) {

    int num1 = 10;
    int num2 = 8;

    int sum1 = add_two_numbers(num1, num2);
    printf("%d is the sum of the two numbers\n", sum1);

    int sum2;
    sum_nums_pointer(num1, num2, &sum2);
    printf("%d is the sum of the two numbers\n", sum2);


    return 0;
}

int add_two_numbers(int a, int b) {
    return a + b;
}

void sum_nums_pointer(int a, int b, int *sum) {
    *sum = a + b;
}