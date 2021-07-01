// Write a void function which places the sum of two numbers
// inside a variable passed in by reference.

#include <stdio.h>

int sum_nums(int a, int b);
void sum_nums_pointer(int a, int b, int *sum2);

int main (void) {

    int num1 = 9;
    int num2 = 10;

    int sum = sum_nums(num1, num2);
    printf("the sum is %d\n", sum);

    int sum2 = -1;
    sum_nums_pointer(num1, num2, &sum2);
    printf("the sum is %d\n", sum2);

    return 0;
}

int sum_nums(int a, int b) {
    return a + b;
}

void sum_nums_pointer(int a, int b, int *sum2) {
    *sum2 = a + b;
}