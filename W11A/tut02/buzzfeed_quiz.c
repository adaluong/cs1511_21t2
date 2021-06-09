// COMP1511 Tut02 - variables, if statements, program flow
// Program to decide what kind of pasta you are
// Ada Luong, June 2021

#include <stdio.h>

#define SHREK           1
#define WRECK_IT_RALPH  2

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

    printf("\nHow many dogs would you like to have?\n");

    int dog_count;
    scanf("%d", &dog_count);

    printf("you would like to have %d dogs???\n", dog_count);

    // dogs >= 5
    if (dog_count >= 5) {
        bad_pasta_counter += 1;
    } else {
        good_pasta_counter += 1;
    }

    // negative dogs (good)
    if (dog_count < 0) {
        good_pasta_counter += 1;
    }
    
    // odd dogs (good), even dogs (bad)
    if (dog_count % 2 == 0) {
        bad_pasta_counter += 1;
    } else {
        good_pasta_counter += 1;
    }

    /* QUESTION TWO: THREE CHOICES
     * -------------------------------------
     * program flow: else if vs another if
     * constants and #defines
     *
     */
    
    printf("\nWhich movie out of these three would you most want to watch now?\n");
    printf("1: Shrek\n");
    printf("2: Wreck It Ralph\n");
    printf("3: The Emoji Movie\n");
    
    int movie_number;
    scanf("%d", &movie_number);

    if (movie_number == SHREK) {
        good_pasta_counter += 1;
    } else if (movie_number == WRECK_IT_RALPH) {
        good_pasta_counter += 1;
    } else {
        bad_pasta_counter += 1;
    }

    /* DECIDING WHAT PASTA YOU ARE */
    if (good_pasta_counter >= bad_pasta_counter) {
        printf("You're good pasta!\n");
    } else {
        printf("lol you're BAD pasta~\n");
    }

    return 0;
}