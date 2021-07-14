// Tut07 - sum_digits.c
//
// A program which reads characters from its input. 
// When the end of input is reached it should print a count of the 
// number of digits in its input and their sum.
//
// Ada Luong, July 2021

#include <stdio.h>

int main (void) {

    int c;
    c = getchar();

    int digit_count = 0;
    int digit_sum = 0;
    int digit_value;

    while (c != EOF) {
        
        // check if character is a digit
        if (c >= '0' && c <= '9') {
            digit_count += 1;
            digit_value = c - '0';
            digit_sum += digit_value;
        }
        c = getchar();
    }

    printf("This input contained %d digits.\n", digit_count);
    printf("This summed to %d\n.", digit_sum);

    return 0;
}

/* DISCUSSION QUESTION
 * What is EOF?
 * What does getchar() do?
 * What does putchar(..) do?
 * Why are we using an int to store a character? 
 */