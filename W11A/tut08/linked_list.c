// COMP1511 Tut08 - Linked Lists
// Printing a linked list
// Ada Luong, April 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAX_LENGTH 100

struct destination *create_struct(char name[MAX_LENGTH], double cost, int rating);

// DEFINING A STRUCT
struct destination {

    // has some sort of data
    char name[MAX_LENGTH];
    double cost;
    int rating;

    // pointer to another struct OF THE SAME TYPE
    struct destination *next;
};

int main (void) {

    //////////////////////////////////////////////////////////////////
    
    /* CREATING A LINKED LIST */
    struct destination *sydney = create_struct("sydney", 300.00, 5);
    struct destination *tokyo = create_struct("tokyo", 300.00, 5);
    struct destination *genovia = create_struct("genovia", 300.00, 5);

    // sydney -> tokyo -> genovia -> NULL
    sydney->next = tokyo;
    tokyo->next = genovia;
    genovia->next = NULL;

    //////////////////////////////////////////////////////////////////
    
    /* PRINTING A LINKED LIST */

    // creating a new variable called current to 
    // keep track of where we are at in the list
    struct destination *current = sydney;
    
    // check that we are not at the last element of the list
    while (current != NULL) {
        
        printf("we are at %s\n", current->name);

        // go to the next node of the linked list
        current = current->next;
    }

    //////////////////////////////////////////////////////////////////

    /* FREEING ALL THE NODES IN THE LIST */
    
    // for every malloc there is an equal and opposite free
    // try creating a loop that does the same thing!
    free(sydney);
    free(tokyo); 
    free(genovia);

    return 0;
}

// Function which returns a pointer to a new struct destination
struct destination *create_struct(char name[MAX_LENGTH], double cost, int rating) {

    struct destination *new_destination = malloc(sizeof(struct destination));
    
    strcpy(new_destination->name, name);

    new_destination->cost = cost;
    new_destination->rating = rating;
    new_destination->next = NULL;
    
    return new_destination;
}
