// Tut07 - prints out the values of argc and argv
// Ada Luong, July 2021

#include <stdio.h>

int main (int argc, char* argv[]) {

    printf("argc = %d\n", argc);

    int i = 0;
    while (i < argc) {

        printf("argv[%d] = %s\n", i, argv[i]);

        i++;
    }

}