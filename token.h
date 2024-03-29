


#ifndef CC_COURSE_TOKENS_H
#define CC_COURSE_TOKENS_H

#endif //CC_COURSE_TOKENS_H


//SIMPLE OPERATORS
#define TK_CODE_NOT 0 // '!'
#define TK_CODE_MOD 1 // '%'
#define TK_CODE_POWER 2 // '^'
#define TK_CODE_BITWISE_AND 3 // '&'
#define TK_CODE_MULTIPLICATION 4 // '*'
#define TK_CODE_MINUS 5 // '-'
#define TK_CODE_PLUS 6 // '+'
#define TK_CODE_EQUAL 7 // '='
#define TK_CODE_BITWISE_OR 8 // '|'
#define TK_CODE_DIRECT_SELECTION 9 // '.'
#define TK_CODE_LESS 10 // '<'
#define TK_CODE_GREATER 11 // '>'
#define TK_CODE_DIVISION 12 // '/'
#define TK_CODE_QUESTION 13 // '?'
#define TK_CODE_TILDE 14 // '~'

//COMPOUND ASSIGNMENT OPERATORS
#define TK_CODE_PLUS_EQUAL 15 // '+='
#define TK_CODE_MINUS_EQUAL 16 // '-='
#define TK_CODE_MULTIPLICATION_EQUAL 17 // '*='
#define TK_CODE_DIVISION_EQUAL 18 // '/='
#define TK_CODE_MOD_EQUAL 19 // '%='
#define TK_CODE_LESS_EQUAL 20 // '<='
#define TK_CODE_GREATER_EQUAL 21 // '>='
#define TK_CODE_AND_EQUAL 22 // '&='
#define TK_CODE_POWER_EQUAL 23 // '^='
#define TK_CODE_OR_EQUAL 24 // '|='
#define TK_CODE_INCREMENT 25 // '++'
#define TK_CODE_DECREMENT 26 // '--'
#define TK_CODE_SHIFT_LEFT 27 // '<<'
#define TK_CODE_SHIFT_RIGHT 28 // '>>'
#define TK_CODE_EQUAL_EQUAL 29 // '=='
#define TK_CODE_NOT_EQUAL 30 // '!='
#define TK_CODE_AND_AND 31 // '&&'
#define TK_CODE_OR_OR 32 // '||'
#define TK_CODE_IMPLICATION 33 // '-->'
#define TK_CODE_SHIFT_LEFT_EQUAL 34 // '<<='
#define TK_CODE_SHIFT_RIGHT_EQUAL 35 // '>>='

//DELIMITERS
#define TK_CODE_OPEN_BRACKET 36 // '('
#define TK_CODE_CLOSE_BRACKET 37 // ')'
#define TK_CODE_SQUARE_OPEN_BRACKET 38 // '['
#define TK_CODE_SQUARE_CLOSE_BRACKET 39 // ']'
#define TK_CODE_FIGURE_OPEN_BRACKET 40 // '{'
#define TK_CODE_FIGURE_CLOSE_BRACKET 41 // '}'
#define TK_CODE_COMMA 42 // ','
#define TK_CODE_SEMICOLON 43 // ';'
#define TK_CODE_COLON 44 // ':'
#define TK_CODE_ELLIPSIS 45 // '...'

//KEYWORDS
#define TK_CODE_KEYWORD 46

//String const
#define  TK_CODE_STRING 47

//Char const
#define  TK_CODE_CHAR 48

//INT const
#define  TK_CODE_INT 49

//IDENTIFIERS
#define  TK_CODE_IDENTIFICATOR 50


struct CToken {
    int code;
    int span_line;
    int span_position;
    short category;
    char* source;
    short binary;
}typedef CToken;


