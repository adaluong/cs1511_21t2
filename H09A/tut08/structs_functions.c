// COMP1511 - Tut08
// Demonstration of creating structs with functions
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
struct destination *create_destination_struct(void);


int main(void) {

    struct destination *auckland = create_destination_struct();
    printf("the rating of auckland here is %d\n", auckland->rating);

    // Everytime you call malloc, you are responsible for that memory
    // FREE THE MEMORY
    free(auckland);
    
    // DO NOT USE AFTER FREEEE 
    // printf("the rating of auckland here is %d\n", auckland->rating);

    return 0;
}

// This function allocates memory for a struct and 
// then returns a pointer to a struct (type: struct destination)
struct destination *create_destination_struct(void) {

    // Allocating memory for a struct on the heap
    struct destination *auckland = malloc(sizeof(struct destination));

    // Initialising the values of the struct
    auckland->cost = 300.00;
    auckland->rating = 9;
    strncpy(auckland->name, "auckland", MAX_LENGTH);

    // Returning a POINTER to a struct
    return auckland;
}

