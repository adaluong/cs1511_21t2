// Modulo Calculator
// Source: https://repl.it/@Divinitus/Modulo-Calculator

#include <stdio.h>

int main(void) {
    
    int x = 0;
    int y = 0;
    printf("Enter modulo: ");

    while (scanf("%d%%%d", &x, &y) == 2) {
        printf("%d %% %d = %d\n\n", x, y, x%y);
        printf("Enter modulo: ");
    }

    printf("\n\nGoodbye!\n");

    return 0;
}

/* EXAMPLES TO TRY
    5 % 3
    1 % 2
   -1 % 2
*/