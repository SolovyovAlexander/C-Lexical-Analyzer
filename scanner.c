#include <ctype.h>
#include "scanner.h"


int is_begin_of_identificator(const char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_');
}

int is_identificator_one(char *str) {
    char keywords[32][9] = {"auto", "break", "case", "char", "const", "continue", "default",
                            "do", "double", "else", "enum", "extern", "float", "for", "goto",
                            "if", "int", "long", "register", "return", "short", "signed",
                            "sizeof", "static", "struct", "switch", "typedef", "union",
                            "unsigned", "void", "volatile", "while"};
    for (int i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], str) == 0) {
            return 0;
        }
    }

    return 1;
}

fcf is_identificator(char *str) {
    fcf a;

    int i = 0;
    while ((*(str + i) >= 'a' && *(str + i) <= 'z') || (*(str + i) >= 'A' && *(str + i) <= 'Z') || (*(str + i) == '_')) {
        i++;
    }

    a.token_code = TK_CODE_IDENTIFIER;
    a.length = i;
    return a;
}

int is_keyword_one(char str) {
    char keywords[32][9] = {"auto", "break", "case", "char", "const", "continue", "default",
                            "do", "double", "else", "enum", "extern", "float", "for", "goto",
                            "if", "int", "long", "register", "return", "short", "signed",
                            "sizeof", "static", "struct", "switch", "typedef", "union",
                            "unsigned", "void", "volatile", "while"};
    for (int i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], &str) == 0) {
            return 1;
        }
    }

    return 0;
}
fcf is_keyword(const char *str) {
    fcf a;

    char keywords[32][9] = {"auto", "break", "case", "char", "const", "continue", "default",
                            "do", "double", "else", "enum", "extern", "float", "for", "goto",
                            "if", "int", "long", "register", "return", "short", "signed",
                            "sizeof", "static", "struct", "switch", "typedef", "union",
                            "unsigned", "void", "volatile", "while"};

    if (*str == 'a' && *(str + 1) == 'u' && *(str + 2) == 't' && *(str + 3) == 'o') {
        a.token_code = TK_CODE_AUTO;
        a.length = 4;
        return a;
    } else if (*str == 'b' && *(str + 1) == 'r' && *(str + 2) == 'e' && *(str + 3) == 'a' && *(str + 4) == 'k') {
        a.token_code = TK_CODE_BREAK;
        a.length = 5;
        return a;
    } else if (*str == 'c' && *(str + 1) == 'a' && *(str + 2) == 's' && *(str + 3) == 'e') {
        a.token_code = TK_CODE_CASE;
        a.length = 4;
        return a;
    } else if (*str == 'c' && *(str + 1) == 'h' && *(str + 2) == 'a' && *(str + 3) == 'r') {
        a.token_code = TK_CODE_CHAR;
        a.length = 4;
        return a;
    } else if (*str == 'c' && *(str + 1) == 'o' && *(str + 2) == 'n' && *(str + 3) == 's' && *(str + 4) == 't') {
        a.token_code = TK_CODE_CONST;
        a.length = 5;
        return a;
    } else if (*str == 'c' && *(str + 1) == 'o' && *(str + 2) == 'n' && *(str + 3) == 't' && *(str + 4) == 'i' &&
                *(str + 5) == 'n' && *(str + 6) == 'u' && *(str + 7) == 'e') {
        a.token_code = TK_CODE_CONTINUE;
        a.length = 8;
        return a;
    } else if (*str == 'd' && *(str + 1) == 'e' && *(str + 2) == 'f' && *(str + 3) == 'a' && *(str + 4) == 'u' &&
                *(str + 5) == 'l' && *(str + 6) == 't') {
        a.token_code = TK_CODE_DEFAULT;
        a.length = 7;
        return a;
    } else if (*str == 'd' && *(str + 1) == 'o') {
        a.token_code = TK_CODE_DO;
        a.length = 2;
        return a;
    } else if (*str == 'd' && *(str + 1) == 'o' && *(str + 2) == 'u' && *(str + 3) == 'b' && *(str + 4) == 'l' &&
                *(str + 5) == 'e') {
        a.token_code = TK_CODE_DOUBLE;
        a.length = 6;
        return a;
    } else if (*str == 'e' && *(str + 1) == 'l' && *(str + 2) == 's' && *(str + 3) == 'e') {
        a.token_code = TK_CODE_ELSE;
        a.length = 4;
        return a;
    } else if (*str == 'e' && *(str + 1) == 'n' && *(str + 2) == 'u' && *(str + 3) == 'm') {
        a.token_code = TK_CODE_ENUM;
        a.length = 4;
        return a;
    } else if (*str == 'e' && *(str + 1) == 'x' && *(str + 2) == 't' && *(str + 3) == 'e' && *(str + 4) == 'r' &&
                *(str + 5) == 'n') {
        a.token_code = TK_CODE_EXTERN;
        a.length = 6;
        return a;
    } else if (*str == 'f' && *(str + 1) == 'l' && *(str + 2) == 'o' && *(str + 3) == 'a' && *(str + 4) == 't') {
        a.token_code = TK_CODE_FLOAT;
        a.length = 5;
        return a;
    } else if (*str == 'f' && *(str + 1) == 'o' && *(str + 2) == 'r') {
        a.token_code = TK_CODE_FOR;
        a.length = 3;
        return a;
    } else if (*str == 'g' && *(str + 1) == 'o' && *(str + 2) == 't' && *(str + 3) == 'o') {
        a.token_code = TK_CODE_GOTO;
        a.length = 4;
        return a;
    } else if (*str == 'i' && *(str + 1) == 'f') {
        a.token_code = TK_CODE_IF;
        a.length = 2;
        return a;
    } else if (*str == 'i' && *(str + 1) == 'n' && *(str + 2) == 't') {
        a.token_code = TK_CODE_INT;
        a.length = 3;
        return a;
    } else if (*str == 'l' && *(str + 1) == 'o' && *(str + 2) == 'n' && *(str + 3) == 'g') {
        a.token_code = TK_CODE_LONG;
        a.length = 4;
        return a;
    } else if (*str == 'r' && *(str + 1) == 'e' && *(str + 2) == 'g' && *(str + 3) == 'i' && *(str + 4) == 's' &&
                *(str + 5) == 't' && *(str + 6) == 'e' && *(str + 7) == 'r') {
        a.token_code = TK_CODE_REGISTER;
        a.length = 8;
        return a;
    } else if (*str == 'r' && *(str + 1) == 'e' && *(str + 2) == 't' && *(str + 3) == 'u' && *(str + 4) == 'r' &&
                *(str + 5) == 'n') {
        a.token_code = TK_CODE_RETURN;
        a.length = 6;
        return a;
    } else if (*str == 's' && *(str + 1) == 'h' && *(str + 2) == 'o' && *(str + 3) == 'r' && *(str + 4) == 't') {
        a.token_code = TK_CODE_SHORT;
        a.length = 5;
        return a;
    } else if (*str == 's' && *(str + 1) == 'i' && *(str + 2) == 'g' && *(str + 3) == 'n' && *(str + 4) == 'e' &&
                *(str + 5) == 'd') {
        a.token_code = TK_CODE_SIGNED;
        a.length = 6;
        return a;
    } else if (*str == 's' && *(str + 1) == 'i' && *(str + 2) == 'z' && *(str + 3) == 'e' && *(str + 4) == 'o' &&
                *(str + 1) == 'f') {
        a.token_code = TK_CODE_SIZEOF;
        a.length = 6;
        return a;
    } else if (*str == 's' && *(str + 1) == 't' && *(str + 2) == 'a' && *(str + 3) == 't' && *(str + 4) == 'i' &&
                *(str + 1) == 'c') {
        a.token_code = TK_CODE_STATIC;
        a.length = 6;
        return a;
    } else if (*str == 's' && *(str + 1) == 't' && *(str + 2) == 'r' && *(str + 3) == 'u' && *(str + 4) == 'c' &&
                *(str + 1) == 't') {
        a.token_code = TK_CODE_STRUCT;
        a.length = 6;
        return a;
    } else if (*str == 's' && *(str + 1) == 'w' && *(str + 2) == 'i' && *(str + 3) == 't' && *(str + 4) == 'c' &&
                *(str + 1) == 'h') {
        a.token_code = TK_CODE_SWITCH;
        a.length = 6;
        return a;
    } else if (*str == 't' && *(str + 1) == 'y' && *(str + 2) == 'p' && *(str + 3) == 'e' && *(str + 4) == 'd' &&
                *(str + 5) == 'e' && *(str + 6) == 'f') {
        a.token_code = TK_CODE_TYPEDEF;
        a.length = 7;
        return a;
    } else if (*str == 'u' && *(str + 1) == 'n' && *(str + 2) == 'i' && *(str + 3) == 'o' && *(str + 4) == 'n') {
        a.token_code = TK_CODE_UNION;
        a.length = 5;
        return a;
    } else if (*str == 'u' && *(str + 1) == 'n' && *(str + 2) == 's' && *(str + 3) == 'i' && *(str + 4) == 'g' &&
                *(str + 5) == 'n' && *(str + 6) == 'e' && *(str + 7) == 'd') {
        a.token_code = TK_CODE_UNSIGNED;
        a.length = 8;
        return a;
    } else if (*str == 'v' && *(str + 1) == 'o' && *(str + 2) == 'i' && *(str + 3) == 'd') {
        a.token_code = TK_CODE_VOID;
        a.length = 4;
        return a;
    } else if (*str == 'v' && *(str + 1) == 'o' && *(str + 2) == 'l' && *(str + 3) == 'a' && *(str + 4) == 't' &&
                *(str + 5) == 'i' && *(str + 6) == 'l' && *(str + 7) == 'e') {
        a.token_code = TK_CODE_VOLATILE;
        a.length = 8;
        return a;
    } else if (*str == 'w' && *(str + 1) == 'h' && *(str + 2) == 'i' && *(str + 3) == 'l' && *(str + 4) == 'e') {
        a.token_code = TK_CODE_WHILE;
        a.length = 5;
        return a;
    }
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



        //identificator
        if (is_begin_of_identificator(ch)) {

        }
        ch = fgetc(fp);

    }

    return token2;
}


