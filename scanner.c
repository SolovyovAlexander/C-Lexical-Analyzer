#include <stdio.h>
#include <stdlib.h>
#include "token.h"

struct CToken* get_next_token(char* file_name) {

    char ch;
    FILE *fp;

    fp = fopen(file_name, "r"); // read mode

    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    printf("The contents of %s file are:\n", file_name);

    while((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);

    }


    fclose(fp);
    return 0;
}
