// Tut07 - sum_digits.c
//
// A program which reads characters from its input. 
// When the end of input is reached it should print a count of the 
// number of digits in its input and their sum.
//
// Ada Luong, July 2021

#include <stdio.h>

int main (void) {

    int c; // use int not char
    c = getchar();

    int digit_count = 0;
    int digit_sum = 0;

    while (c != EOF) {

        if (c >= '0' && c <= '9') {
            digit_count += 1;

            // ch| ascii| 
            // 0 |  48  | 48 - 48
            // 1 |  49  | 49 - 48
            // 2 |  50  | 50 -48 

            int digit_value = c - '0';
            // atoi()
            digit_sum += digit_value;
        }

        // putchar(c);

        c = getchar();
    }

    printf("the digit count is %d\n", digit_count);
    printf("the sum of the digits are %d\n", digit_sum);

    return 0;
}

/* DISCUSSION QUESTION
 * What is EOF?
 * What does getchar() do?
 * What does putchar(..) do?
 * Why are we using an int to store a character? 
 */