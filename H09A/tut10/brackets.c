// Author: Dean Wunder (d.wunder@unsw.edu.au)
// Using a stack to match brackets

// To compile: 'dcc -o matching_brackets brackets.c stack.c'

#include <stdio.h>
#include "stack.h"

#define TRUE  1
#define FALSE 0

int opening_bracket(int bracket);
int closing_bracket(int bracket);
int brackets_match(int opening, int closing);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: ./matching_brackets [bracket_sequence]\n");
        return 1;
    }
    
    char *brackets = argv[1];
    Stack my_stack = create_stack();

    int valid = TRUE;
    int i = 0;
    while (brackets[i] != '\0' && valid == TRUE) {

        // if it's an opening bracket,
        // add it to the stack
        if (opening_bracket(brackets[i])) {
            stack_push(my_stack, brackets[i]);
        }

        // if it's a closing bracket
        // take it off the stack
        // []
        if (closing_bracket(brackets[i])) {

            // CONSIDER:
            // you can't pop from stack 
            // [](

            if (stack_size(my_stack) == 0) {
                valid = FALSE;
            } else {
                int bracket_from_stack = stack_pop(my_stack);
                if (!brackets_match(bracket_from_stack, brackets[i])) {
                    valid = FALSE;
                }
            }
        }
        i++;
    }

    // CONSIDER:
    // still have brackets on the stack
    // once we reach the end

    if (valid == TRUE && stack_size(my_stack) == 0) {
        printf("WOO valid brackets!!!\n");
    } else {
        printf("BAD bracket sequence\n");
    }

    free_stack(my_stack);
    return 0;
}

int opening_bracket(int bracket) {
    if (bracket == '(' || bracket == '{' || bracket == '[') {
        return 1;
    }
    return 0;
}

int closing_bracket(int bracket) {
    if (bracket == ')' || bracket == '}' || bracket == ']') {
        return 1;
    }
    return 0;
}

int brackets_match(int opening, int closing) {
    if (opening == '(' && closing == ')') {
        return 1;
    }
    if (opening == '{' && closing == '}') {
        return 1;
    }
    if (opening == '[' && closing == ']') {
        return 1;
    }
    return 0;
}
