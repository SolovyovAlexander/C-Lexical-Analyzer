//
// Created by trov on 10.09.2019.
//

#include "../scanner.h"

int main() {

    FILE *fp;

    fp = fopen("C:/Users/trov/CLionProjects/C-Lexical-Analyzer/tests/value.txt", "r"); // read mode

    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    int i =0;
    while (i<1000) {

        fprintf(stdout, "%s\n", get_next_token(fp)->source);

        i++;
    }



    return 0;
}