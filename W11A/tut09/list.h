// Emily Chen & Tom Kunc
// Defines a linked list and basic functions to debug it

struct node {
	int data;		// data item at this node
	struct node *next;		// pointer to the next node
};

// Append to a linked list
struct node *add_last(struct node *head, int data);

// Deletes the last element of a linked list (returns NULL if list empty)
struct node *delete_last(struct node *head);

// returns a copy of the linked list
struct node *copy(struct node *old_head);

// Returns a new linked list where it is the second appended to the first
struct node *list_append(struct node *first_list, struct node *second_list);

// returns 1 if the two lists are identical, otherwise returns 0
int identical(struct node *head1, struct node *head2);

// given two lists in strictly increasing order, return a new linked list
// (in strictly increasing order) of the elements in both the first and second list
struct node *set_intersection(struct node *first_list, struct node *second_list);

// === Revision Functions ===

// returns 1 if list is in strictly increasing order, otherwise returns 0
int ordered(struct node *head);

// given two linked lists in strictly increasing order,
// return a new linked list (in strictly increasing order) of the elements in either set1 or set2
// no duplicates (only include them once)
struct node *set_union(struct node *set1, struct node *set2);

// === Basic Functions ===
// creates a linked list from the given array of values
struct node *create_list(int values[], int size);
// creates a node with the given data item
struct node *create_node(int dat);
// print out the link list starting at head
void print_list(struct node *head);
// frees all the elements in a linked list
void free_list(struct node *head);
// return the number of items in the linked list
int num_items(struct node *head);