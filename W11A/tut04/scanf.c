// COMP1511 Tut04 Q25 - demonstrating the return value of scanf
// Ada Luong, June 2021

#include <stdio.h>

int main(void) {

    int number;

    printf("Enter a number: ");
    int result = scanf("%d", &number);
    printf("%d\n", result);
    
    return 0;
}

/* VALUES TO TRY
 * an integer
 * a character
 */ 
