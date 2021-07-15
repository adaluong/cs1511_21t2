// Tut07 - Looping through strings read in through argv
// Ada Luong, July 2021

#include <stdio.h>

void print_character(char *string);

int main (int argc, char* argv[]) {

    int i = 1;
    while (i < argc) {

        // eg. argv = {"./program_name", "hello", "world"};
        char *string = argv[i];

        // calling a function which prints each character
        print_character(string);

        i++;
    }

}

// print out a word character by character cause why not
void print_character(char *string) {
    
    int c = 0;

    // A string is just an array of characters 
    // the NULL terminator tells us we're at the end of a string
    while (string[c] != '\0') {
        putchar(string[c]);
        c++;
    }
    putchar('\n');
}   