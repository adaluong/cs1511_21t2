// Write a C program count_up.c which reads an integer n and then
// prints the integers 1..n, one per line.

#include <stdio.h>

int main (void) {

    printf("Spawning assignments\n\n");

    int ending_number;
    scanf("%d", &ending_number);

    int counter = 1;

    while (counter <= ending_number) {
        
        printf("%d\n", counter);
        
        counter = counter + 1;
    }

    return 0;
}