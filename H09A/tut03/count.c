// Write a C program count_up.c which reads an integer n and then
// prints the integers 1..n, one per line.

#include <stdio.h>

int main (void) {

    printf("Spawning assignments\n\n");

    /* Assume that on 
     * day 1, you get 1 assignment,
     * day 2, you get 2 assignments
     * etc...
     */

    printf("How many days do you want to give students assignments >:)\n");

    int total_days;
    scanf("%d", &total_days);

    // A counter for keeping track of the total number of assignments 
    int total_assignments = 0;

    int loop_counter = 1;

    while (loop_counter <= total_days) {

        printf("%d assignments today\n", loop_counter);

        total_assignments += loop_counter;

        loop_counter += 1;
    }

    printf("YOU HAVE ASSIGNED %d ASSIGNMENTS IN TOTAL\n", total_assignments);
    
    return 0;
}