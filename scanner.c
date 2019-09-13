#include <ctype.h>
#include "scanner.h"
int linenumber = 1;


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

CToken *get_identificator_token(FILE *fp, char ch) {
    int str_length = 0;
    CToken *token2 = malloc(sizeof(CToken));
    token2->code = TK_CODE_IDENTIFICATOR;
    while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_' || (ch >= '0' && ch <= '9')) {
        str_length++;
        ch = fgetc(fp);
    }

    if (ch == EOF)
        fseek(fp, -str_length, SEEK_END);
    else
        fseek(fp, -str_length-1, SEEK_CUR);

    // copy string to token
    token2->source = malloc((str_length + 1) * sizeof(char));
    for (int i = 0; i < str_length; ++i) {
        ch = fgetc(fp);
        *(token2->source + i) = ch;


    }

    token2->code = TK_CODE_IDENTIFICATOR;
    token2->span_line = linenumber;
    *(token2->source + str_length) = '\0';
    printf("%s\n", token2->source);

    return token2;
}



fcf is_keyword(const char *str) {
    fcf a;
    a.token_code = -1;
    a.length = 0;
    char keywords[32][9] = {"auto", "break", "case", "char", "const", "continue", "default",
                            "do", "double", "else", "enum", "extern", "float", "for", "goto",
                            "if", "int", "long", "register", "return", "short", "signed",
                            "sizeof", "static", "struct", "switch", "typedef", "union",
                            "unsigned", "void", "volatile", "while"};

    for (int i = 0; i <32 ; ++i) {
        if(!strcmp(str,keywords[i])){
            a.token_code = TK_CODE_KEYWORD;
            a.length = strlen(str);
            return a;
        }

    }
    return a;

}

CToken *get_keyword_token(FILE *fp, char ch) {
    char keywords[32][9] = {"auto", "break", "case", "char", "const", "continue", "default",
                            "do", "double", "else", "enum", "extern", "float", "for", "goto",
                            "if", "int", "long", "register", "return", "short", "signed",
                            "sizeof", "static", "struct", "switch", "typedef", "union",
                            "unsigned", "void", "volatile", "while"};

    int str_length = 0;
    CToken *token2 = malloc(sizeof(CToken));
    while (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_' || (ch >= '0' && ch <= '9')) && ch!=EOF ) {
        str_length++;
        ch = fgetc(fp);
    }

    if (ch == EOF)
        fseek(fp, -str_length, SEEK_END);
    else
        fseek(fp, -str_length-1, SEEK_CUR);

    // copy string to token
    token2->source = malloc((str_length + 1) * sizeof(char));
    for (int i = 0; i < str_length; ++i) {
        ch = fgetc(fp);
        *(token2->source + i) = ch;
    }
    *(token2->source + str_length) = '\0';
    fcf keyword = is_keyword(token2->source);


    if (keyword.token_code > -1 ) {

        printf("KEY WORD!!!!!!! %s\n", token2->source);
        token2->span_line = linenumber;
        return token2;
    }

    fseek(fp, -str_length+1, SEEK_CUR);


    token2->code = -1;

    return token2;
}

int is_begin_of_identificator(const char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_');
}

int is_begin_of_keyword(const char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

int is_operator_one(char ch){
    int a = 0;
    char operators[46][3] = {"!", "%", "^", "&", "*", "-", "+", "=", "|", ".", "<", ">", "/", "?", "~", "+=", "-=",
                             "*=",
                             "/=", "%=", "<=", ">=", "&=", "^=", "|=", "++", "--", "<<", ">>", "==", "!=", "&&", "||",
                             "-->", "<<=", ">>=", "(", ")", "[", "]", "{", "}", ",", ";", ":", "..."};
    for (int i = 0; i <46 ; ++i) {
        if(ch == operators[i][0]){
            a = 1;
        }
    }
    return a;
}




int is_escape_secuence_char(char ch) {
    if (ch == '"') return 1;
    if (ch == '\'') return 1;
    if (ch == '\\') return 1;
    if (ch == '?') return 1;
    if (ch == 'a') return 1;
    if (ch == 'b') return 1;
    if (ch == 'f') return 1;
    if (ch == 'n') return 1;
    if (ch == 'r') return 1;
    if (ch == 't') return 1;
    if (ch == 'v') return 1;
    return 0;
}

int is_char_from_a_to_f(char ch) {
    if (ch == 'a' || ch == 'A') return 1;
    if (ch == 'b' || ch == 'B') return 1;
    if (ch == 'c' || ch == 'C') return 1;
    if (ch == 'd' || ch == 'D') return 1;
    if (ch == 'e' || ch == 'E') return 1;
    if (ch == 'f' || ch == 'F') return 1;
    return 0;
}


CToken *get_string_token(FILE *fp) {
    int str_length = 0;
    char ch = fgetc(fp);
    CToken *token2 = malloc(sizeof(CToken));
    token2->code = TK_CODE_STRING;
    while (ch != '"') {
        str_length++;
        if (ch == EOF) {
            printf("Pls close string, line = %d", linenumber);
            exit(1);
        }
        ch = fgetc(fp);
        if (ch == '"') {
            fseek(fp, -3, SEEK_CUR);
            char ch1 = fgetc(fp);
            char ch2 = fgetc(fp);
            if (ch1 != '\\' && ch2 == '\\') {
                fgetc(fp);
                ch = fgetc(fp);
                str_length++;
                fseek(fp, -1, SEEK_CUR);
            }
        }
    }
    char *str_const = malloc((str_length + 1) * sizeof(char));
    fseek(fp, -str_length, SEEK_CUR);

    for (int i = 0; i < str_length; ++i) {
        *(str_const + i) = fgetc(fp);
    }
    token2->source = malloc((str_length + 1) * sizeof(char));

    // copy string to token
    for (int j = 0; j < str_length; ++j) {
        *(token2->source + j) = *(str_const + j);
    }
    token2->code = TK_CODE_STRING;
    token2->span_line = linenumber;
    *(token2->source + str_length) = '\0';
    printf("%s\n", token2->source);

    fgetc(fp);

    return token2;
}

CToken *get_char_token(FILE *fp) {
    //check char constant
    char ch = fgetc(fp);
    CToken *token = malloc(sizeof(CToken));
    token->code = TK_CODE_CHAR;
    int length = 0;
    char *src;
    //escape sequence
    if (ch == '\\') {
        src = malloc((++length) * sizeof(char));
        src[length - 1] = ch;
        ch = fgetc(fp);
        if (isdigit(ch) && ch != '8' && ch != '9') {
            src = realloc(src, (++length) * sizeof(char));
            src[length - 1] = ch;

            ch = fgetc(fp);
            if (isdigit(ch) && ch != '8' && ch != '9') {
                src = realloc(src, (++length) * sizeof(char));
                src[length - 1] = ch;

                ch = fgetc(fp);
                if (isdigit(ch) && ch != '8' && ch != '9') {
                    src = realloc(src, (++length) * sizeof(char));
                    src[length - 1] = ch;
                    ch = fgetc(fp);
                }
            }
        } else if (is_escape_secuence_char(ch)) {
            src = realloc(src, (++length) * sizeof(char));
            src[length - 1] = ch;
            ch = fgetc(fp);
        } else if (ch == 'x') {
            src = realloc(src, (++length) * sizeof(char));
            src[length - 1] = ch;
            ch = fgetc(fp);
            while (isdigit(ch) || is_char_from_a_to_f(ch)) {
                src = realloc(src, (++length) * sizeof(char));
                src[length - 1] = ch;
                ch = fgetc(fp);
            }
        }
    } else {
        src = malloc((++length) * sizeof(char));
        src[length - 1] = ch;
        ch = fgetc(fp);
    }
    if (ch != '\'') {
        src = realloc(src, (++length) * sizeof(char));
        src[length - 1] = ch;
        fprintf(stderr, "Multiple SYMBOLS in character: %s\n", src);


        exit(-1);
    }
    token->source = src;
    printf("This is CHAR %s\n", token->source);
    return token;

}

CToken *get_next_value(FILE *fp, char start) {
    CToken *token = malloc(sizeof(CToken));
    int length = 0;
    char *src = malloc((++length) * sizeof(char));
    char ch;
    src[length - 1] = start;
    if (start == '0') {
        ch = fgetc(fp);
        if (ch == 'x' || ch == 'X') {
            src = realloc(src, (++length) * sizeof(char));
            src[length - 1] = ch;
            ch = fgetc(fp);
            if (isdigit(ch) || is_char_from_a_to_f(ch)) {
                while (isdigit(ch) || is_char_from_a_to_f(ch)) {
                    src = realloc(src, (++length) * sizeof(char));
                    src[length - 1] = ch;
                    ch = fgetc(fp);
                }
            } else {
                src = realloc(src, (++length) * sizeof(char));
                src[length - 1] = ch;
                fprintf(stderr, "No value after '0x' in: %s\n", src);
                exit(-1);
            }

        } else {
            while (isdigit(ch) && ch != 8 && ch != 9) {
                src = realloc(src, (++length) * sizeof(char));
                src[length - 1] = ch;
                ch = fgetc(fp);
            }
        }
    } else if (isdigit(start)) {
        ch = fgetc(fp);
        while (isdigit(ch)) {
            src = realloc(src, (++length) * sizeof(char));
            src[length - 1] = ch;
            ch = fgetc(fp);
        }
    } else {
        fprintf(stderr, "Error in int value checker [passed not correct starting char]: %s\n", src);
        exit(-1);
    }

    if (ch == 'l' || ch == 'L') {
        src = realloc(src, (++length) * sizeof(char));
        src[length - 1] = ch;
        ch = fgetc(fp);
        if (ch == 'u' || ch == 'U') {
            src = realloc(src, (++length) * sizeof(char));
            src[length - 1] = ch;
        } else {
            if (is_operator(&ch).token_code || ch == ' ' || ch == '\n') {
                fseek(fp, -1, SEEK_CUR);
            } else {
                fprintf(stderr, "Not a token: %s\n", src);
                exit(-1);
            }
        }
    } else if (ch == 'u' || ch == 'U') {
        src = realloc(src, (++length) * sizeof(char));
        src[length - 1] = ch;
        ch = fgetc(fp);
        if (ch == 'l' || ch == 'L') {
            src = realloc(src, (++length) * sizeof(char));
            src[length - 1] = ch;
        } else {
            if (is_operator(&ch).token_code || ch == ' ' || ch == '\n') {
                fseek(fp, -1, SEEK_CUR);
            } else {
                fprintf(stderr, "Not a token: %s\n", src);
                exit(-1);
            }
        }
    } else {
        //конец, взял лишний чар
        if (is_operator(&ch).token_code != -1 || ch == ' ' || ch == '\n' || ch == '\r') {
            fseek(fp, -1, SEEK_CUR);
        } else {
            fprintf(stderr, "Not a token: %s\n", src);
            exit(-1);
        }
    }
    token->code = TK_CODE_INT;
    token->source = src;
    printf("%s\n", token->source);
    return token;
}

CToken *get_operator_token(FILE *fp, char ch) {
    int flag = 0;
    char operators[46][3] = {"!", "%", "^", "&", "*", "-", "+", "=", "|", ".", "<", ">", "/", "?", "~", "+=", "-=",
                             "*=",
                             "/=", "%=", "<=", ">=", "&=", "^=", "|=", "++", "--", "<<", ">>", "==", "!=", "&&", "||",
                             "-->", "<<=", ">>=", "(", ")", "[", "]", "{", "}", ",", ";", ":", "..."};
    CToken *token2 = malloc(sizeof(CToken));
    token2->code = -1;
    char *op_str = malloc(3 * sizeof(char));
    char kek[3];
    kek[0] = ch;
    kek[1] = fgetc(fp);
    kek[2] = fgetc(fp);
    if (kek[1] == EOF ){
        flag = 1;
        fseek(fp, 0, SEEK_END);
    } else if (kek[2] == EOF ){
        flag = 1;
        fseek(fp, -1, SEEK_END);
    }

    fcf operat = is_operator(kek);
    if (operat.token_code > -1) {
        if (operat.length == 1) {
            if(!flag){
                fseek(fp, -2, SEEK_CUR);
            }
            token2->code = operat.token_code;
        } else if (operat.length == 2) {
            fseek(fp, -1, SEEK_CUR);
            token2->code = operat.token_code;
        } else {
            token2->code = operat.token_code;
        }
        token2->source = operators[token2->code];
        printf("%s\n", token2->source);
        return token2;
    }
    if(!flag){
        fseek(fp, -2, SEEK_CUR);
    }

    return token2;
}

CToken *get_next_token(FILE *fp) {

    char ch;

    CToken *token2;
    ch = (char)fgetc(fp);
    while (ch != EOF) {
        if (ch == '\n') {
            linenumber++;
            ch = fgetc(fp);
            if (ch == '\r') ch = fgetc(fp);
            continue;
        }
        //avoid comments
        if (ch == '/') {
            if (fgetc(fp) == '/') {
                while (ch != '\n') { ch = fgetc(fp); }
                linenumber++;
                ch = fgetc(fp);
                if (ch == '\r') ch = fgetc(fp);
                continue;
            } else
                fseek(fp, -1, SEEK_CUR);
        }

        //avoid preprocessing
        if (ch == '#') {
            while (ch != '\n') { ch = fgetc(fp); }
            linenumber++;
            ch = fgetc(fp);
            if (ch == '\r') ch = fgetc(fp);
            continue;
        }

        //check string constant
        if (ch == '"') {

            return get_string_token(fp);
        }

        if (ch == '\'') {
            return get_char_token(fp);
        }

        if (isdigit(ch)) {
            return get_next_value(fp, ch);
        }

        // detection of operators
        if (is_operator_one(ch)){
            token2 = get_operator_token(fp, ch);
            if (token2->code > -1) {
                return token2;
            }
        }

        //keyword
        if (is_begin_of_keyword(ch)) {
            if(get_keyword_token(fp, ch)->code>-1){
                ch = fgetc(fp);
                continue;
            }

        }



        //identificator

        if (is_begin_of_identificator(ch)) {
            get_identificator_token(fp, ch);

        }

        ch = fgetc(fp);


    }

    return token2;
}


