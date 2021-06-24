// COMP1511 Tut04 Q25 - demonstrating the return value of scanf
// Ada Luong, June 2021

#include <stdio.h>

int main(void) {

    // Scanning in one integer

    int number_one;
    printf("Enter a number: ");

    int result_one = scanf("%d", &number_one);
    printf("successfully scanned in %d value(s)\n", result_one);

    if (result_one > 0) {
        printf("the value scanned in was %d\n", number_one);
    }

    // Scanning in two integers
    
    int number_two;
    int number_three;

    printf("\nThis example scans in two numbers.\nEnter two values: ");

    int result_two = scanf("%d %d", &number_two, &number_three);
    printf("successfully scanned in %d value(s)\n", result_two);

    if (result_two > 0) {
        printf("the values scanned in were %d %d\n", number_two, number_three);
    }

    return 0;
}

/* VALUES TO TRY
 * an integer
 * a character
 * EOF (CTRL-D)
 */ 
