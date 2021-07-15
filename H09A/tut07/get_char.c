// Tut07 - getchar and putchar
// Ada Luong, July 2021

#include <stdio.h>

int main (void) {

    int c; // use int not char
    c = getchar();

    while (c != EOF) {
        putchar(c);
        c = getchar();
    }

    return 0;
}

/* DISCUSSION QUESTION
 * What is EOF?
 * What does getchar() do?
 * What does putchar(..) do?
 * Why are we using an int to store a character? 
 */