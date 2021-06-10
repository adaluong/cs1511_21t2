// COMP1511 Tut02 - variables, if statements, program flow
// Quiz to determine what kind of pasta you are
// Ada Luong, June 2021

#include <stdio.h>

#define FROZEN_2        1
#define THE_EMOJI_MOVIE 2
#define CATS            3

int main (void) {

    printf("WHAT KIND OF PASTA ARE YOU?????\n");

    /* SETTING UP "TYPES OF PASTA" VARIABLES 
     * -------------------------------------
     * declaring a variable (integer)
     * assigning a value to the variable
     *
     */

    int good_pasta_counter = 0;
    int bad_pasta_counter = 0;

    /* QUESTION ONE: ENTER A NUMBER
     * -------------------------------------     
     * scanning from the terminal
     * printing to the terminal
     * if statement conditions
     * -> using == instead of =
     * -> operators for comparison >, <, >=, <=, !
     * when do if statements run?
     *
     */ 

    printf("\nHow many lizards would you like to have?\n");

    int lizard_counter;
    scanf("%d", &lizard_counter); 

    if (lizard_counter > 0) {
        printf("WHAT!? YOU WANNA HAVE %d LIZARDS???? lol. %d is a lotta lizards\n", lizard_counter, lizard_counter);
        good_pasta_counter += 1;
    } else {
        printf("That's not POSSIBLE >:(\n");
        lizard_counter = lizard_counter * -1;
        printf("well... you now have %d lizards!\n", lizard_counter);
        bad_pasta_counter += 10;
    }

    /* QUESTION TWO: THREE CHOICES
     * -------------------------------------
     * program flow: else if vs another if
     * constants and #defines
     *
     */
    
    printf("\nWhich movie out of these three would you most want to watch now?\n");
    printf("Type in a number from the options below\n");
    printf("1: Frozen 2\n");
    printf("2: The Emoji Movie\n");
    printf("3: Cats\n");

    int movie_option;
    scanf("%d", &movie_option); 

    if (movie_option == FROZEN_2) {
        good_pasta_counter += 2;

    } else if (movie_option == THE_EMOJI_MOVIE) {
        bad_pasta_counter += 10;

    } else if (movie_option == CATS) {
        good_pasta_counter += 1;

    } else {
        bad_pasta_counter += 100;
    }

    // printf("good pasta counter is at %d and bad pasta counter is at %d\n", good_pasta_counter, bad_pasta_counter);

    /* DECIDING WHAT PASTA YOU ARE */
    if (good_pasta_counter > bad_pasta_counter) {
        printf("you are GOOD PASTA\n");
    } else {
        printf("u are BAD pasta~ uwu\n");
    }

    return 0;
}