// Author: Dean Wunder (d.wunder@unsw.edu.au)
// Using a stack to match brackets

// To compile: 'dcc -o matching_brackets brackets.c stack.c'

#include <stdio.h>
#include "stack.h"

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
    
    int i = 0;
    int valid = 1;
    while (brackets[i] != '\0' && valid == 1) {
    
        // If opening bracket, push onto the stack 
        if (opening_bracket(brackets[i])) {
            stack_push(my_stack, brackets[i]);
        }
        
        // If closing bracket, pop off the stack and check if it matches
        if (closing_bracket(brackets[i])) {
            if (stack_size(my_stack) == 0) {
                // Stack is empty
                valid = 0;
            } else {
                char bracket_from_stack = stack_pop(my_stack);
                if (!brackets_match(bracket_from_stack, brackets[i])) {
                    // Closing bracket does not match opening bracket
                    valid = 0;
                }
            }
        }
        i++;
    }

    if (valid == 0 || stack_size(my_stack) != 0) {
        printf("Bad bracket sequence :(\n");
    } else {
    
        printf("Good bracket sequence :)\n");
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
