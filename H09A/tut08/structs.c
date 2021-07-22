// COMP1511 - Tut08
// Demonstration of structs
// defining, initialising, accessing fields
// changing fields with funtions
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
    int rating;
};

// FUNCTION PROTOTYPES
struct destination change_rating(struct destination location);
void change_rating_pointers(struct destination *location);

// int change_rating ((int) location);

int main(void) {

    // Declaring a variable type struct destination in main
    // equivalent to int number;
    struct destination auckland;

    // Initialising the values of the struct
    auckland.cost = 300.00;
    auckland.rating = 9;
    strncpy(auckland.name, "auckland", MAX_LENGTH);

    // Accessing struct fields
    printf("auckland's rating is %d\n", auckland.rating);
    int auckland_rating_saved = auckland.rating;
    printf("auckland's SAVED rating is %d\n", auckland_rating_saved);

    // Changing the rating of a struct with a function that 
    // returns the entire struct
    auckland = change_rating(auckland);
    printf("auckland's new rating is %d\n", auckland.rating);

    change_rating_pointers(&auckland);
    printf("auckland's new new rating is %d\n", auckland.rating);

    return 0;
}

// Changing the rating of a struct with a function that 
// returns the entire struct
void change_rating_pointers(struct destination *location) {
    // (*location).rating = 11;
    location->rating = 12;
}

// Changing the rating of a struct with a function that 
// returns the entire struct
struct destination change_rating(struct destination location) {
    location.rating = 11;
    return location;
}