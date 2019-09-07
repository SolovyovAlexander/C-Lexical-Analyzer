#include "scanner.h"




void define_token(char *str) {

}

int is_begin_of_identificator(const char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_');
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

fcf is_operator(const char *ch) {
    fcf a;

    if (*ch == '!') {
        if (*(ch + 1) == '=') {
            a.token_code = TK_CODE_NOT_EQUAL;
            a.length = 2;
            return a;
        } else {
            a.token_code = TK_CODE_NOT;
            a.length = 1;
            return a;
        }
    } else if (*ch == '%') {
        if (*(ch + 1) == '=') {
            a.token_code = TK_CODE_MOD_EQUAL;
            a.length = 2;
            return a;
        } else {
            a.token_code = TK_CODE_MOD;
            a.length = 1;
            return a;
        }
    } else if (*ch == '^') {
        if (*(ch + 1) == '=') {
            a.token_code = TK_CODE_POWER_EQUAL;
            a.length = 2;
            return a;
        } else {
            a.token_code = TK_CODE_POWER;
            a.length = 1;
            return a;
        }
    } else if (*ch == '&') {
        if (*(ch + 1) == '=') {
            a.token_code = TK_CODE_AND_EQUAL;
            a.length = 2;
            return a;
        } else if (*(ch + 1) == '&') {
            a.token_code = TK_CODE_AND_AND;
            a.length = 2;
            return a;
        } else {
            a.token_code = TK_CODE_BITWISE_AND;
            a.length = 1;
            return a;
        }
    } else if (*ch == '*') {
        if (*(ch + 1) == '=') {
            a.token_code = TK_CODE_MULTIPLICATION_EQUAL;
            a.length = 2;
            return a;
        } else {
            a.token_code = TK_CODE_MULTIPLICATION;
            a.length = 1;
            return a;
        }
    } else if (*ch == '-') {
        if (*(ch + 1) == '=') {
            a.token_code = TK_CODE_MINUS_EQUAL;
            a.length = 2;
            return a;
        } else if (*(ch + 1) == '-') {
            if (*(ch + 2) == '>') {
                a.token_code = TK_CODE_IMPLICATION;
                a.length = 3;
                return a;
            } else {
                a.token_code = TK_CODE_DECREMENT;
                a.length = 2;
                return a;
            }

        } else {
            a.token_code = TK_CODE_MINUS;
            a.length = 1;
            return a;
        }
    } else if (*ch == '+') {
        if (*(ch + 1) == '=') {
            a.token_code = TK_CODE_PLUS_EQUAL;
            a.length = 2;
            return a;
        } else if (*(ch + 1) == '+') {
            a.token_code = TK_CODE_INCREMENT;
            a.length = 2;
            return a;
        } else {
            a.token_code = TK_CODE_PLUS;
            a.length = 1;
            return a;
        }
    } else if (*ch == '=') {
        if (*(ch + 1) == '=') {
            a.token_code = TK_CODE_EQUAL_EQUAL;
            a.length = 2;
            return a;
        } else {
            a.token_code = TK_CODE_EQUAL;
            a.length = 1;
            return a;
        }
    } else if (*ch == '~') {
        a.token_code = TK_CODE_TILDE;
        a.length = 1;
        return a;
    } else if (*ch == '|') {
        if (*(ch + 1) == '=') {
            a.token_code = TK_CODE_OR_EQUAL;
            a.length = 2;
            return a;
        } else if (*(ch + 1) == '|') {
            a.token_code = TK_CODE_OR_OR;
            a.length = 2;
            return a;
        } else {
            a.token_code = TK_CODE_BITWISE_OR;
            a.length = 1;
            return a;
        }
    } else if (*ch == '.') {
        if (*(ch + 1) == '.' && *(ch + 2) == '.') {
            a.token_code = TK_CODE_ELLIPSIS;
            a.length = 3;
            return a;
        } else {
            a.token_code = TK_CODE_DIRECT_SELECTION;
            a.length = 1;
            return a;
        }
    } else if (*ch == '<') {
        if (*(ch + 1) == '=') {
            a.token_code = TK_CODE_LESS_EQUAL;
            a.length = 2;
            return a;
        } else if (*(ch + 1) == '<') {
            if (*(ch + 2) == '=') {
                a.token_code = TK_CODE_SHIFT_LEFT_EQUAL;
                a.length = 3;
                return a;
            } else {
                a.token_code = TK_CODE_SHIFT_LEFT;
                a.length = 2;
                return a;
            }
        } else {
            a.token_code = TK_CODE_LESS;
            a.length = 1;
            return a;
        }
    } else if (*ch == '>') {
        if (*(ch + 1) == '=') {
            a.token_code = TK_CODE_GREATER_EQUAL;
            a.length = 2;
            return a;
        } else if (*(ch + 1) == '>') {
            if (*(ch + 2) == '=') {
                a.token_code = TK_CODE_SHIFT_RIGHT_EQUAL;
                a.length = 3;
                return a;
            } else {
                a.token_code = TK_CODE_SHIFT_RIGHT;
                a.length = 2;
                return a;
            }
        } else {
            a.token_code = TK_CODE_GREATER;
            a.length = 1;
            return a;
        }
    } else if (*ch == '/') {
        if (*(ch + 1) == '=') {
            a.token_code = TK_CODE_DIVISION_EQUAL;
            a.length = 2;
            return a;
        } else {
            a.token_code = TK_CODE_DIVISION;
            a.length = 1;
            return a;
        }
    } else if (*ch == '?') {
        a.token_code = TK_CODE_QUESTION;
        a.length = 1;
        return a;
    } else if (*ch == '(') {
        a.token_code = TK_CODE_OPEN_BRACKET;
        a.length = 1;
        return a;
    } else if (*ch == ')') {
        a.token_code = TK_CODE_CLOSE_BRACKET;
        a.length = 1;
        return a;
    } else if (*ch == '[') {
        a.token_code = TK_CODE_SQUARE_OPEN_BRACKET;
        a.length = 1;
        return a;
    } else if (*ch == ']') {
        a.token_code = TK_CODE_SQUARE_CLOSE_BRACKET;
        a.length = 1;
        return a;
    } else if (*ch == '{') {
        a.token_code = TK_CODE_FIGURE_OPEN_BRACKET;
        a.length = 1;
        return a;
    } else if (*ch == '}') {
        a.token_code = TK_CODE_FIGURE_CLOSE_BRACKET;
        a.length = 1;
        return a;
    } else if (*ch == ',') {
        a.token_code = TK_CODE_COMMA;
        a.length = 1;
        return a;
    } else if (*ch == ';') {
        a.token_code = TK_CODE_SEMICOLON;
        a.length = 1;
        return a;
    } else if (*ch == ':') {
        a.token_code = TK_CODE_COLON;
        a.length = 1;
        return a;
    }

    a.token_code = -1;
    a.length = 0;
    return a;
}

int linenumber = 1;

CToken *get_next_token(FILE *fp) {

    char ch;

    CToken *token2 = malloc(sizeof(CToken));

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            linenumber++;
        }
        //avoid comments
        if (ch == '/') {
            if (fgetc(fp) == '/') {
                while ((ch = fgetc(fp)) != '\n') {}
                linenumber++;
            } else
                fseek(fp, -1, SEEK_CUR);
        }

        //avoid preprocessing
        if (ch == '#') {
            while ((ch = fgetc(fp)) != '\n') {}
            linenumber++;
        }

        //check string constant
        if (ch == '"' ) {
            int str_length = 0;
            ch = fgetc(fp);
            while (ch != '"') {
                str_length++;
                if(ch == EOF){
                    printf("Pls close string, line = %d", linenumber);
                    exit(1);
                }
                ch = fgetc(fp);
                if(ch == '"'){
                    fseek(fp, -3, SEEK_CUR);
                    char ch1 = fgetc(fp);
                    char ch2 = fgetc(fp);
                    if (ch1 != '\\' && ch2 == '\\'){
                        fgetc(fp);
                        ch = fgetc(fp);
                        str_length++;
                        fseek(fp, -1, SEEK_CUR);
                    }
                }
            }
            char *str_const = malloc((str_length+1) * sizeof(char));
            fseek(fp, -str_length, SEEK_CUR);

            for (int i = 0; i <str_length ; ++i) {
                *(str_const+i) = fgetc(fp);
            }
            token2->source = malloc((str_length+1) * sizeof(char));

            // copy string to token
            for (int j = 0; j <str_length ; ++j) {
                *(token2->source + j) = *(str_const+j);
            }
            token2->code = TK_CODE_STRING;
            token2->span_line = linenumber;
            *(token2->source + str_length) = '\0';
            printf("%s\n", token2->source);

            fgetc(fp);

            return token2;
        }


        //check char constant
        if (ch == '\''){
            ch = fgetc(fp);
            while(ch != '\''){
                
            }
        }

        // detection of operators
        char *op_str = malloc(3 * sizeof(char));
        *op_str = ch;
        *(op_str + 1) = fgetc(fp);
        *(op_str + 2) = fgetc(fp);
        fcf operat = is_operator(op_str);


        if (operat.token_code > -1) {
            if (operat.length == 1) {
                fseek(fp, -2, SEEK_CUR);
                token2->code = operat.token_code;
            } else if (operat.length == 2) {
                fseek(fp, -1, SEEK_CUR);
                token2->code = operat.token_code;
            } else {
                token2->code = operat.token_code;
            }
            printf("%d\n", token2->code);

            return token2;
        }
        fseek(fp, -2, SEEK_CUR);

        //identificator
        if (is_begin_of_identificator(ch)) {

        }

    }


    fclose(fp);
    return 0;
}


