// COMP1511 Tut09 - Linked Lists
// Implementation of functions in list.h
// Ada Luong, July 2021

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

#define IDENTICAL 1
#define NOT_IDENTICAL 0

// Append to a linked list
struct node *add_last(struct node *head, int data) {

    struct node *new_node = create_node(data);

    // CASE 0: The list is EMPTY
    if (head == NULL) {
        return new_node;
    } 

    // CASE 1: The list has ONE NODE
    // this case is already considered in the next case! 
    
    /*
    if (head->next == NULL) {
        head->next = new_node;
        return head;
    }
    */

    // CASE 2: there are many nodes in the list
    // loop through the list until current is the final node
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // current now points to the last node of the list
    // so we can append the new node

    current->next = new_node;

    return head; 
}

// Deletes the last element of a linked list (returns NULL if list empty)
struct node *delete_last(struct node *head) {
    
    // CASE 0: no node in the list
    if (head == NULL) {
        return NULL;
    }

    // CASE 1: one node in the list
    // alternatively: you can consider this case after the while loop
    // and check if (prev == NULL) aka the last node is also the first node
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // CASE 2: multiple nodes in the list    
    struct node *prev = NULL;
    struct node *curr = head;

    while(curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    /* at this point of the program:
     prev pointing at second last node
     curr pointing at the last node
     */

    prev->next = curr->next;
    
    /* for this function: prev->next = NULL
     but this method is generalisable to removing nodes
     in the middle of a list
    */

    free(curr);

    return head;
}

// returns a copy of the linked list
struct node *copy(struct node *old_head) {

    if (old_head == NULL){
        return NULL;
    }    

    struct node *new_head = create_node(old_head->data);

    // pointers to keep track of where we are in both lists
    struct node *new_list_last_node = new_head;
    
    struct node *to_copy = old_head->next;
    while (to_copy != NULL) {
        // note here we are MALLOC'ing memory
        struct node *new_node = create_node(to_copy->data);
        new_list_last_node->next = new_node;
        new_list_last_node = new_list_last_node->next;
        to_copy = to_copy->next;
    }
    
    // make sure you return the head of the NEW list!
    return new_head;
}

// Returns a new linked list where it is the second appended to the first
struct node *list_append(struct node *first_list, struct node *second_list) {

    if (first_list == NULL) {
        return copy(second_list);
    }

    // We want to create copies of the list so they are independent
    // of the original two lists
    struct node *first_copy = copy(first_list);
    struct node *second_copy = copy(second_list);
    
    struct node *curr = first_copy;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    // and the second list to the first list
    curr->next = second_copy;

    // the first list is the head of the new joined lists
    return first_copy;
}

// returns 1 if the two lists are identical, otherwise returns 0
int identical(struct node *head1, struct node *head2) {

    // creating two pointers - no memory allocated here!
    struct node *first_curr = head1;
    struct node *second_curr = head2;

    // checking we are not at the end of either lists
    while (first_curr != NULL && second_curr != NULL) {

        // at any point, list is not identical if 
        // two nodes contain different values
        if (first_curr->data != second_curr->data) {
            return NOT_IDENTICAL;
        }

        // increment both lists simultaneously 
        first_curr = first_curr->next;
        second_curr = second_curr->next;
    }

    // dealing with the case where one list finishes earlier than the other
    // if they aren't the same length, they're not identical
    if (first_curr != NULL || second_curr != NULL) {
        return NOT_IDENTICAL;
    }

    // otherwise, the lists are identical
    return IDENTICAL;
}


// given two lists in strictly increasing order, return a new linked list 
// (in strictly increasing order) of the elements in both the first and second list
struct node *set_intersection(struct node *first_list, struct node *second_list) {
    
    struct node *head = NULL;

    /* Loop through both lists at the same time.
     We're not going to be at exactly the same place
     in both lists, we might move asymetrically
     based on which numbers are higher in which list.
    */

    struct node *first_curr = first_list;
    struct node *second_curr = second_list;
    
    // We don't need to check if either is NULL because that means
    // there are extra hanging elements which aren't a part of either.
    
    while (first_curr != NULL && second_curr != NULL) {

        if (first_curr->data < second_curr->data) {
            // Since the data from the first list is less than the data from
            // the second list, we add from the first list
            first_curr = first_curr->next;
        
        } else if (second_curr->data < first_curr->data) {
            // Since the data from the second list is less than the data from
            // the first list, we add from the second list
            second_curr = second_curr->next;
        
        } else {
            // The last case is if both first_curr and second_curr hold the same
            // data which is when we add it and then increment them both
            head = add_last(head, first_curr->data);
            first_curr = first_curr->next;
            second_curr = second_curr->next;
        }
    }
    return head;
}

// ===== REVISION =====================

// returns 1 if list is in strictly increasing order, otherwise returns 0
int ordered(struct node *head) {
    return 0;   // replace this
}

// given two linked lists in strictly increasing order,
// return a new linked list (in strictly increasing order) of the elements in either set1 or set2
// no duplicates (only include them once)
struct node *set_union(struct node *set1, struct node *set2) {
    return NULL;    // replace this
}

// =================================

// given an array of integer values for data items
// returns the head of a linked list with these values
// in the order as they appear in the array
// size gives the size of the array
struct node *create_list(int values[], int size) {
    int i = 0;

    if (size <= 0) {
        // empty linked list (or invalid size)
        return NULL;
    }

    struct node *head = NULL;   // head of the linked list
    struct node *tmp = NULL;    // temporary item we're working with
    struct node *curr = NULL;   // current node we're looking at in the linked list

    while (i < size) {
        tmp = create_node(values[i]);

        // link this node onto our list
        if (head == NULL) {
            // this is the first node in the list
            head = tmp;
            curr = head;
        } else {
            // this is not the first node in the list
            // add it to the end, i.e. after curr
            curr->next = tmp;

            // reset curr to point at the new last node
            curr = tmp;
        }
        i = i + 1;
    }

    return head;
}

// creates a struct node with the given data value
// returns a pointer to this node
struct node *create_node(int dat) {
    struct node *new = malloc(sizeof(struct node));
    assert(new != NULL);
    new->data = dat;
    new->next = NULL;

    return new;
}

// prints out the list given the head of a list
void print_list(struct node *head) {
    struct node *curr;
    curr = head;

    while (curr != NULL) {
        printf("[ %d ]-->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");

}

// frees all the elements in a linked list
void free_list(struct node *head) {
    if (head == NULL) {
        return;
    }
    free_list(head->next);
    free(head);
}

// return the number of items in the linked list
int num_items(struct node *head) {
    struct node *curr = head;
    int count = 0;

    while (curr != NULL) {
        count = count + 1;
        curr = curr->next;
    }

    return count;
}