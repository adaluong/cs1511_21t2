#include <stdio.h>

int main (void) {
    int a = 1;
    int b = 2;
    int c = 0;

    printf("%d\n", c || (a && b));

    return 0;

}