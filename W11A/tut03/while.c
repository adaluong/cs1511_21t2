// Program to print "hello" 10 times using a while loop
// Ada Luong June 2021

#include <stdio.h>

int main (void) {
    
    // 1. initialise counter
    int counter = 0;

    // 2. while condition 
    while (counter < 10) {

        // 3. do something
        printf("hello\n");

        // 4. increment the counter
        counter = counter + 1;
    }

    return 0;
}

/* Things to note
- When does a while loop stop running?
- The 3 most important things that should happen in (almost) every while loop
    1. Initialising the counter
    2. Having a condition
    3. Incrementing the counter
- Uninitialized value error
- Infinite loops yikes
*/