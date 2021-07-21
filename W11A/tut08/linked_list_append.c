// COMP1511 Tut08 - Linked Lists
// Appending the head of a linked list
// Ada Luong, April 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAX_LENGTH 100

struct destination *create_struct(char name[MAX_LENGTH], double cost, int rating);

// Defining a struct to store nodes of our destinations
struct destination {

    // has some sort of data
    char name[MAX_LENGTH];
    double cost;
    int rating;

    // pointer to another struct OF THE SAME TYPE
    struct destination *next;
};

// Defining ANOTHER STRUCT type to store the first element of our destination
// linked list, type `struct travel_plan` 
struct travel_plan {

    // has some sort of data
    int data;

    // pointer to the first element of destination list
    // note this is NOT a node of the same type
    struct destination *head;
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

    /* CREATING A NEW STRUCT TYPE */
    struct travel_plan *ada_2025_plans = malloc(sizeof(struct travel_plan));
    ada_2025_plans->head = sydney;

    // append to the head of the list
    struct destination *new_node = create_struct("melbz", 50.00, 10);

    // set the next field of the new node to the current head
    new_node->next = ada_2025_plans->head;

    // make the new node the new head of the list
    ada_2025_plans->head = new_node;

    //////////////////////////////////////////////////////////////////

    // PRINTING A LINKED LIST
    struct destination *current = ada_2025_plans->head;
    while (current != NULL) {
        printf("we are at %s\n", current->name);
        current = current->next;
    }

    // FREE ALL THE NODES!!
    struct destination *to_free;

    current = ada_2025_plans->head;
    while (current != NULL) {

        // created a to_free variable to avoid
        // use after free errors
        to_free = current;

        current = current->next;
        free(to_free);
    }

    // we used malloc here, so also have to free this node!
    free(ada_2025_plans);

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