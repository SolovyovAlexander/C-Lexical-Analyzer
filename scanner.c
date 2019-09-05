#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "string.h"

struct CToken *get_next_token(char *file_name) {

    char ch;
    FILE *fp;

    fp = fopen(file_name, "r"); // read mode

    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    printf("The contents of %s file are:\n", file_name);

    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);

    }


    fclose(fp);
    return 0;
}

void define_token(char *str) {

}

int is_keyword(char *str) {
    char keywords[32][9] = {"auto", "break", "case", "char", "const", "continue", "default",
                            "do", "double", "else", "enum", "extern", "float", "for", "goto",
                            "if", "int", "long", "register", "return", "short", "signed",
                            "sizeof", "static", "struct", "switch", "typedef", "union",
                            "unsigned", "void", "volatile", "while"};
    for (int i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], str) == 0) {
            return 1;
        }
    }
    return 0;

}

int is_operator(const char *ch) {
    if (*ch == '!') {
        if (*(ch + 1) == '=') {
            return TK_CODE_NOT_EQUAL;
        } else {
            return TK_CODE_NOT;
        }
    } else if (*ch == '%') {
        if (*(ch + 1) == '=') {
            return TK_CODE_MOD_EQUAL;
        } else {
            return TK_CODE_MOD;
        }
    } else if (*ch == '^') {
        if (*(ch + 1) == '=') {
            return TK_CODE_POWER_EQUAL;
        } else {
            return TK_CODE_POWER;
        }
    } else if (*ch == '&') {
        if (*(ch + 1) == '=') {
            return TK_CODE_AND_EQUAL;
        } else if (*(ch + 1) == '&') {
            return TK_CODE_AND_AND;
        } else {
            return TK_CODE_BITWISE_AND;
        }
    } else if (*ch == '*') {
        if (*(ch + 1) == '=') {
            return TK_CODE_MULTIPLICATION_EQUAL;
        } else {
            return TK_CODE_MULTIPLICATION;
        }
    } else if (*ch == '-') {
        if (*(ch + 1) == '=') {
            return TK_CODE_MINUS_EQUAL;
        } else if (*(ch + 1) == '-') {
            if (*(ch + 2) == '>') {
                return TK_CODE_IMPLICATION;
            } else {
                return TK_CODE_DECREMENT;
            }

        } else {
            return TK_CODE_MINUS;
        }
    } else if (*ch == '+') {
        if (*(ch + 1) == '=') {
            return TK_CODE_PLUS_EQUAL;
        } else if (*(ch + 1) == '+') {
            return TK_CODE_INCREMENT;
        } else {
            return TK_CODE_PLUS;
        }
    } else if (*ch == '=') {
        if (*(ch + 1) == '=') {
            return TK_CODE_EQUAL_EQUAL;
        } else {
            return TK_CODE_EQUAL;
        }
    } else if (*ch == '~') {
        return TK_CODE_TILDE;
    } else if (*ch == '|') {
        if (*(ch + 1) == '='){
            return TK_CODE_OR_EQUAL;
        } else if (*(ch + 1) == '|'){
            return TK_CODE_OR_OR;
        } else {
            return TK_CODE_BITWISE_OR;
        }
    } else if (*ch == '.') {
        if (*(ch + 1) == '.' && *(ch + 2) == '.'){
            return TK_CODE_ELLIPSIS;
        } else {
            return  TK_CODE_DIRECT_SELECTION;
        }
    } else if (*ch == '<'){
        if (*(ch + 1) == '='){
            return TK_CODE_LESS_EQUAL;
        } else if (*(ch + 1) == '<'){
            if (*(ch + 2) == '='){
                return TK_CODE_SHIFT_LEFT_EQUAL;
            } else {
                return TK_CODE_SHIFT_LEFT;
            }
        } else {
            return TK_CODE_LESS;
        }
    } else if (*ch == '>'){
        if (*(ch + 1) == '='){
            return TK_CODE_GREATER_EQUAL;
        } else if (*(ch + 1) == '>'){
            if (*(ch + 2) == '='){
                return TK_CODE_SHIFT_RIGHT_EQUAL;
            } else {
                return TK_CODE_SHIFT_RIGHT;
            }
        } else {
            return TK_CODE_GREATER;
        }
    } else if (*ch == '/'){
        if (*(ch + 1) == '='){
            return TK_CODE_DIVISION_EQUAL;
        } else {
            return TK_CODE_DIVISION;
        }
    } else if (*ch == '?'){
        return TK_CODE_QUESTION;
    } else if (*ch == '('){
        return TK_CODE_OPEN_BRACKET;
    } else if (*ch == ')'){
        return TK_CODE_CLOSE_BRACKET;
    } else if (*ch == '['){
        return TK_CODE_SQUARE_OPEN_BRACKET;
    } else if (*ch == ']'){
        return TK_CODE_SQUARE_CLOSE_BRACKET;
    } else if (*ch == '{'){
        return TK_CODE_FIGURE_OPEN_BRACKET;
    } else if (*ch == '}'){
        return TK_CODE_FIGURE_CLOSE_BRACKET;
    } else if (*ch == ','){
        return TK_CODE_COMMA;
    } else if (*ch == ';'){
        return TK_CODE_SEMICOLON;
    } else if (*ch == ':'){
        return TK_CODE_COLON;
    }

    return 0;
}
