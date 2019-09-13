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
    CToken* token;
    token = get_next_token(fp);
    while (token->code != -1) {
        token = get_next_token(fp);
    }


    fclose(fp);
    return 0;
}