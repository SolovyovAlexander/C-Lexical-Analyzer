#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "string.h"

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

void define_token(char* str){

}

int is_keyword(char* str){
    char keywords[32][8] = {"auto","break","case","char","const","continue","default",
                             "do","double","else","enum","extern","float","for","goto",
                             "if","int","long","register","return","short","signed",
                             "sizeof","static","struct","switch","typedef","union",
                             "unsigned","void","volatile","while"};
    for (int i = 0; i <32 ; ++i) {
        if(strcmp(keywords[i],str) == 0){
            return 1;
        }
    }
    return 0;

}

int is_operator(){}
