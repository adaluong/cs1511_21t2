// Tut07 - Strings
// Ada Luong, July 2021

#include <stdio.h>
#include <string.h>

int main (void) {

    char line[8] = {'w','o','w','!','\n','\0'};

    char *string = "wow!\n";

    printf("%s", line);
    printf("%s", string);

    int size = strlen(line);
    printf("size = %d\n", size);

    line[3] = '\0';
    // {'w','o','w','\0','\n','\0'};

    printf("%s", line);

    return 0;
}
