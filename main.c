#include "scanner.h"


int main() {

    char file_name[6];
    printf("Enter name of a file you wish to see\n");
    fgets(file_name, 6, stdin);
    char ch;
    FILE *fp;
    fp = fopen(file_name, "r"); // read mode
    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    int i =0;
    CToken* token;


    while (i<10000 ) {

        printf("%d",i);
        get_next_token(fp);

        i++;

    }


    fclose(fp);
    return 0;
}