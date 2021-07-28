# Tutorial 09 Notes
Acknowledgements: [UNSW COMP1511 21T2 Course Material](https://cgi.cse.unsw.edu.au/~cs1511/21T2/)

## Memory Allocation: `malloc` and `free`
* `malloc` allocates memory dynamically on the heap. This is outside of the memory for any function, so it lasts beyond the function themselves.
* checkout `man 3 malloc` to see how to use `malloc`
    - **input**: the number of bytes needed tostore a variable (nearly always use the `sizeof` function to find this value)
    - **output**: returns a pointer that gives us the address of this memory
* **Common Error**: instead of malloc'ing enough space for a struct `sizeof(struct node)`, you only allocae enough space for a pointer `sizeof(struct node *)`
* Any memory allocated with `malloc` needs an accompanying `free`
    - **input**: a pointer that was returned by a previous call to `malloc`

## Use After Free Errors
* A use after free error occurs when memory that has been deallocated with `free` is subsequently used
* Commonly, `free` will change the contents of the memory chunk it is given to record some associated housekeeping metadata
* Here is a simple example of a use after free error:
    ```
    free(p);    
    p = p->next;
    ```
* Another common way a use after free could occur is if a programmer frees some memory (for example, holding a struct) but forgets that it is still being used elsewhere in their code (probably via a different pointer)

#### What could possibly go wrong?
* Generally, in a threaded program, a different `malloc` could be called in another thread between the `free` and the use-after-free.
* Because of the way `malloc` and `free` are implemented, this is likely to be allocated in the recently freed memory
* This means the same piece of memory is now being occupied by what's meant to be two structs containing different values
* This has disasterous results, as assignments to one struct changes the other struct
    - On an extreme level, imagine if you have a struct for "usernames" and one for "admin privileges" overlapping

#### What's the worse that could happen?
* A malicious user could exploit these errors to bypass security (COMP6447 teaches you how to do this!)
* Essentially:
    1. You `malloc` some memory
    2. You `free` that memory
    3. You forget you've freed it and try to use it again (eg. dereference fields in a struct)
    4. Somewhere between steps 2 and 3, I malloc memory which ended up in the same memory as yours was
    5. I put whatever I want in that memory; when you try to use it, you get whatever I've put there >:)
* This might not sound so bad in the scope of COMP1511 code, but there's things like function pointers... where a use after free might mean some malicious user can get your program to arbitrarily execute things they've written

## Memory Leaks
* You can check for memory leaks with `dcc --leak-check -o insert_program_name insert_program_name.c`
* A memory leak is when a program doesn't free memory alloated with `malloc`
* This is (generally) not important in the programs we write in COMP1511 since they only run for short periods of time and allocate small amounts of memory
* However, consider:
    - A web browser which allocates memory every time a user visits a page but doesn't free the memory when they leave the page... the web browser's memory use will steadily grow, eventually causing performance problems, and then if it exhausts available memory, termination
    - A memory leak in a game... the longer you play, the more memory it uses up until you exit the program (the operating system reclaims all memory when a program exits)

## Solving Linked List Problems
* Take a look at tut08 for an introduction to linked lists
* TIP #1: DRAW DIAGRAMS!!! Figure out how you would solve the problem on paper first and then try to code it up.
* TIP #2: Consider different CASES including
    - The number of nodes in a list (empty, one node, many nodes)
    - Location in the list (start, middle, end)
    - Whether or not you need to iterate through the list
        - What loop condition?
        - How many iterators do I need?
    - Do I need to `malloc`/`free` memory?
* SOME TECHNIQUES FOR PROBLEM SOLVING (insights from tutorial questions):
    - `add_last`: considering cases, using a while loop to get to the last node of the list
    - `delete_last`: using two pointers (`prev` and `curr`) to find the last node of the list and the second last node
    - `copy`: using malloc() to create new nodes, rather than just having pointers to nodes
    - `list_append`: need to copy both lists in order to return a new list... simply modifying pointers means changing the old lists will also change the new list
    - `identical`: how do you interact with two loops simultaneously?
    * `set_intersection`: how do you use nested loops and linked lists?