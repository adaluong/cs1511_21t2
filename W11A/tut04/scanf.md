# wait there's more: scanf()
Markdown by Ada Luong, June 2021

Reference: [COMP1511 Tutorial 04](https://cgi.cse.unsw.edu.au/~cs1511/21T2/tut/04/questions)

## The return value of scanf()

In week 2, we were introduced to scanf() as a function that scans in input from a user and stores it in a variable.

This code snippet scans in an integer from the user and stores it in the variable "number":

```
int number;
scanf("%d", &number);
```

This week, we also look at scanf() as a function that returns an output! This output is the **number of values that are successfully scanned in with scanf - the number of values it has read and assigned to variables.** 

If you aren't sure what we mean by "return an output", I suggest revising your understanding of functions [here](https://cgi.cse.unsw.edu.au/~cs1511/21T2/lec/functions/slides)

The following code snippet stores the result of scanf in the variable `result` and then prints the result out.

```
int result = scanf("%d", &number);
printf("%d\n", result);
```

In this example:

* If the user enters an integer, like the number 21, scanf returns 1 because it has successfully scanned in one value, and then stores it into result.

* If the user enters something that is NOT an integer, like a random letter or "CTRL-D" (EOF), then scanf returns 0, because it was expecting an integer, and hence has not scanned in any values successfully.

You can try this out yourself by compiling and running `scanf.c`.

## Using scanf() in a loop

Recall the structure of a while loop:
```
while (EXPRESSION IS TRUE) {
    //SOMETHING HAPPENS
}
```
The code inside the curly braces execute whenever the while condition is TRUE.

Question: what if I wanted to create a loop that continually reads values in from standard input until the user inputs anything other than a number (or the input ends)?

We can use our knowledge of scanf's return value here! If scanf can be used to give a result, then it can be used as the tested expression in an if statement or while loop.

If we put scanf in the while loop condition, we will read the input everytime we try to look, and then we will only enter the loop's code if scanf gives us a 1.

```
int input_variable;
while (scanf("%d", &input_variable) == 1) {
    // successfully read an integer into input_variable
    printf("Read %d", input_variable);
}
```

This strategy will be helpful for the `painterbot` and `cs_calculator` lab exercises, as well as assignment 1.

Think about how you could use this technique alongside other control structures you have learnt in the past few weeks.

```

// A list of potential commands
#define START_ASSIGNMENT 1
#define PROCRASTINATE    2

int command;
while (scanf("%d", &command) == 1) {

    // successfully read an integer into command

    if (command == START_ASSIGNMENT) {
        printf("nice work!\n");
    } else if (command == PROCRASTINATE) {
        printf("how would you like to procrastinate?\n");

        int procrastination_option;
        scanf("%d", &procrastination_option);

        if (procrastination_option == ...) {
            ....
        }
        .....

    }

}

```

To see how you can use `scanf` to scan integers into an array, see `scanning_numbers.c`
