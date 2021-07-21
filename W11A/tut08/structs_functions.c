// COMP1511 - Tut08
//
// Demonstration of structs
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
struct destination create_canberra(void);
struct destination *create_canberra_pointer(void);

int main(void) {

    // Creating a struct called canberra of type struct destination

    /* struct destination canberra = create_canberra(); */
    struct destination *canberra = create_canberra_pointer();

    printf("canberra rating: %d\n", canberra->rating);

    // don't forget to free any memory you have malloc'd!
    free(canberra);

    // use after free error: don't do this
    /* printf("%d\n", canberra->rating); */

    return 0;
}

// Creating a destination struct by returning a pointer to a struct
// This is what we will be using for the rest of the course
struct destination *create_canberra_pointer(void) {

    // Declaring a variable type struct destination
    struct destination *canberra = malloc(sizeof(struct destination));

    // Initialising the values of the struct
    canberra->rating = 2;
    canberra->cost = 200.00;
    strncpy(canberra->name, "canberra", MAX_LENGTH);

    return canberra;
}

// Creating a destination struct by returning the entire struct 
// Demonstration that structs are simply variables
struct destination create_canberra(void) {
    
    // Declaring a variable type struct destination
    struct destination canberra;

    // Initialising the values of the struct
    canberra.rating = 2;
    canberra.cost = 200.00;
    strncpy(canberra.name, "canberra", MAX_LENGTH);

    // Returning the entire struct
    return canberra;
}