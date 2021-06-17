// Program to print "are we there yet" 10 times using a while loop
// Ada Luong June 2021

#include <stdio.h>

int main (void) {

    // 1. initialise the loop counter
    int loop_counter = 0;

    // 2. set up a condition
    while (loop_counter < 10) {

        // 3. do something
        printf("are we there yet?\n");

        // 4. increment the loop counter
        loop_counter += 1;
        /* This is equivalent to
         * loop_counter++;
         * loop_coun
         */
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