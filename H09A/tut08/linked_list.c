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
    char name[MAX_LENGTH];
    double cost;
    int rating;
    struct destination *next;
};

int main (void) {

    // CREATING A LINKED LIST
    // you may want to use a while loop to do this
    struct destination *auckland = create_struct("sydney", 300.00, 5);
    struct destination *tokyo = create_struct("tokyo", 300.00, 5);
    struct destination *korea = create_struct("korea", 300.00, 5);
    struct destination *denmark = create_struct("denmark", 300.00, 5);
    struct destination *paris = create_struct("paris", 300.00, 5);

    // auckland -> Tokyo -> Korea -> denmark -> paris
    auckland->next = tokyo;
    tokyo->next = korea;
    korea->next = denmark;
    denmark->next = paris;
    paris->next = NULL;

    // PRINTING A LINKED LIST

    // curr saves the first element of the linked list here
    // note: we're not malloc'ing any memory here
    struct destination *curr = auckland;

    // checking that we are not at the last element of the list
    while (curr != NULL) {

        printf("Yay we're at %s\n", curr->name);

        // going to the next node of the linked list
        curr = curr->next;
    }

    // FREEING NODES IN A LINKED LIST
    // we need to free all the memory we allocated with malloc

    struct destination *to_free;
    curr = auckland; // reset current to head of the list

    while (curr != NULL) {
        
        to_free = curr;

        // moving curr to the next node before freeing
        // to avoid having a use after free error with curr->next 

        curr = curr->next;
        free(to_free);
    }

    return 0;
}

// Returns a pointer to a new struct (type `struct destination`)
// and initialises the fields of that struct with user input
struct destination *create_struct(char name[MAX_LENGTH], double cost, int rating) {

    struct destination *new_destination = malloc(sizeof(struct destination));
    
    strcpy(new_destination->name, name);

    new_destination->cost = cost;
    new_destination->rating = rating;
    new_destination->next = NULL;
    
    return new_destination;
}