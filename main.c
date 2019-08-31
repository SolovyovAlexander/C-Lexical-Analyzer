#include <stdio.h>
#include "scanner.h"

int main() {

    char file_name[1024];
    printf("Enter name of a file you wish to see\n");
    gets(file_name);

    get_next_token(file_name);

    return 0;
}