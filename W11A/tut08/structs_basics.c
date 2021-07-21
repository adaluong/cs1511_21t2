// COMP1511 - Tut08
//
// Demonstration of structs
// defining, declaring, initialising
// accessing fields and modifying them in functions
//
// Ada Luong, July 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAX_LENGTH 100

// DEFINING A STRUCT
struct destination {
    char name[MAX_LENGTH];
    double cost;
    int rating; // out of 10
};

// FUNCTION PROTOTYPES
void change_rating(struct destination *canberra);

int main(void) {

    // Declaring a variable type struct destination in main
    struct destination canberra;

    // Initialising the values of the struct
    canberra.rating = 2;
    canberra.cost = 200.00;
    strncpy(canberra.name, "canberra", MAX_LENGTH);

    // Saving canberra.rating in a new variable 
    int canberra_rating_variable = canberra.rating;
    printf("The rating of canberra is %d\n", canberra_rating_variable);
    printf("The new rating of canberra is %d\n", canberra.rating);

    // Using a function to update the struct with pointers
    change_rating(&canberra);
    printf("The new rating of canberra is %d\n", canberra.rating);
    
    return 0;
}

void change_rating(struct destination *canberra) {
    // * dereferencing a pointer
    // *canberra.rating = 0;
    // is equivalent to
    canberra->rating = 0;
}