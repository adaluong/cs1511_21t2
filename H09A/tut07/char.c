// Tut07 - Characters and ASCII Representation
// Ada Luong, July 2021

#include <stdio.h>

int main (void) {

    // Declaring a char variable
    char character = 'a';

    // printing the character a
    printf("%c\n", character);

    // printing the ascii value of the character a
    printf("%d\n", 'a');

    // the ascii value represents a character
    // note: in general, don't hardcode ascii values
    printf("%c\n", 97);

    // checking that a character is a lower case letter
    if (character >= 'a' && character <= 'z') {
        int difference = 'a' - 'A';
        character = character - difference;
        printf("this is a lower case letter!\n");
        printf("the upper case letter is: %c\n", character);
    }

    // a = 97 | A = 65 | -32 'a' - 'A'
    // b = 98 | B = 66 | -32

    return 0;
}

/* NOTES
 * When entering a character in C, use single quotes
 * Try the command 'ascii' to see the ascii table
 * You usually won't need to hardcode any ascii values
 * Characters are just numbers in C
 - if statements
 - maths
 * Consider: converting from lower to upper case
        a = 97 | A = 65 | -32
        b = 98 | B = 66 | -32
 */