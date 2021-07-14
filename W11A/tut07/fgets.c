// Tut07 - fgets
//
// Write a program which reads lines from its input and prints them twice.
// You can assume lines contain at most 4096 characters.
//
// Ada Luong, July 2021

#include <stdio.h>

#define SIZE 4096

int main (void) {
    
    char string[SIZE];
    fgets(string, SIZE, stdin);

    printf("%s", string);
    printf("%s", string);

    return 0;
}

