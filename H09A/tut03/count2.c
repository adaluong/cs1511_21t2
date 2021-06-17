// Write a C program count_up.c which reads an integer n and then
// prints the integers 1..n incrementing at a value given by the user

#include <stdio.h>

int main (void) {

    printf("Spawning assignments\n\n");

    // Asking the user to input the ending number
    printf("Enter n\n");
    int n;
    scanf("%d", &n);

    // Asking the user to input the value we want to step by
    printf("Enter increment\n");
    int increment;
    scanf("%d", &increment);

    int loop_counter = 1;

    while (loop_counter <= n) {

        printf("%d\n", loop_counter);

        loop_counter += increment;
    }

    return 0;
}