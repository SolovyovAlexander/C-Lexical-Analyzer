#include "scanner.h"



int main() {

    char file_name[1024];
    printf("Enter name of a file you wish to see\n");
    gets(file_name);

    char ch;

    FILE *fp;

    fp = fopen(file_name, "r"); // read mode

    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    int i =0;
    while (i<10000) {

        get_next_token(fp);

        i++;

    }



    return 0;
}