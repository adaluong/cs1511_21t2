// list_example.c
// Khiet Tam Nguyen - z5313514
// COMP1511 21T2 Tut09 - Q12-14

// Demonstration for common list operations

//===========================================================================//

#include <stdio.h>
#include <stdlib.h>

//===========================================================================//

#define ADD_LAST        1
#define DELETE_LAST     2

//===========================================================================//

struct node {
    int          data;
    struct node *next;
}; // don't forget this semicolon here :).

//===========================================================================//

struct node *create_node(int data);
void print_list(struct node *head);

struct node *add_last(struct node *head, int data);
struct node *delete_last(struct node *head);
struct node *copy(struct node *old_head);

//===========================================================================//

int main(void) {
    struct node *head = NULL;
    printf(
        "Commands:\n\t"
        "%d [DATA]     ADD_LAST\n\t"
        "%d            DELETE_LAST\n",
        ADD_LAST, DELETE_LAST
    );
    
    // Similar to assignment 1 - Minesweeper :).
    printf("Enter command: ");
    int command;
    while (scanf("%d", &command) == 1) {
        if (command == ADD_LAST) {
            int data;
            scanf("%d", &data);
            head = add_last(head, data);
        } else if (command == DELETE_LAST) {
            head = delete_last(head);
        }
        print_list(head);
        printf("Enter command: ");
    }

    return 0;
}

//===========================================================================//

// Allocate memory for node, initialise all fields in node struct and returns
// a pointer to this node.
struct node *create_node(int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    return new;
}

// Prints all the elements in the list given the head node, e.g.
// 0 -> 1 - > 2 -> 3 -> NULL
void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

//===========================================================================//

// add_last should call malloc to allocate memory for the new node
// it adds.
// add_last should return a pointer to the head of the list.
struct node *add_last(struct node *head, int data) {
    struct node *new = create_node(data);
    if (head == NULL) {
        // list is empty
        return new;
    }

    // When there are multiple elements in the list.
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    // loop stops when curr is the last node in the list.
    curr->next = new;

    return head;
}

// delete_last should call free to free the memory of the node it deletes.
// delete_last should return a pointer to the head of the list.
struct node *delete_last(struct node *head) {

    if (head == NULL) {
        // list is empty
        return NULL;
    }

    // Handle case where there are multiple nodes in the list.
    struct node *curr = head;
    struct node *prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    // if (curr == head) {
    if (prev == NULL) {
        // There is one node in the list.
        head = NULL;
    } else {
        // There are multiple nodes in the list.
        prev->next = NULL;
    }
    free(curr);
    return head; 
}

// Implement a function copy which returns a copy of a linked list.
// copy should call malloc to create a new linked list of the same length and
// which contains the same data.
struct node *copy(struct node *old_head) {
    // When the old list is empty
    if (old_head == NULL) {
        return NULL;
    }

    // Create a new node that has the same data as the head node in the old list
    struct node *new_head = create_node(old_head->data);

    // when there are multiple nodes in the list
    struct node *new_curr = new_head;

    // since the head is already copied, we start at the second node
    // in the old list, or NULL if there is only one node.
    struct node *old_curr = old_head->next;

    while (old_curr != NULL) {
        // copy old node and append to new node.
        new_curr->next = create_node(old_curr->data);
        new_curr = new_curr->next;
        old_curr = old_curr->next;
    }
    return new_head;
}
