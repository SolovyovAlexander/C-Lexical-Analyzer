


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
#define TK_CODE_AUTO 46 // 'auto'
#define TK_CODE_BREAK 47 // 'break'
#define TK_CODE_CASE 48 // 'case'
#define TK_CODE_CHAR 49 // 'char'
#define TK_CODE_CONST 50 // 'const'
#define TK_CODE_CONTINUE 51 // 'continue'
#define TK_CODE_DEFAULT 52 // 'default'
#define TK_CODE_DO 53 // 'do'
#define TK_CODE_DOUBLE 54 // 'double'
#define TK_CODE_ELSE 55 // 'else'
#define TK_CODE_ENUM 56 // 'enum'
#define TK_CODE_EXTERN 57 // 'extern'
#define TK_CODE_FLOAT 58 // 'float'
#define TK_CODE_FOR 59 // 'for'
#define TK_CODE_GOTO 60 // 'goto'
#define TK_CODE_IF 61 // 'if'
#define TK_CODE_INT 62 // 'int'
#define TK_CODE_LONG 63 // 'long'
#define TK_CODE_REGISTER 64 // 'register'
#define TK_CODE_RETURN 65 // 'return'
#define TK_CODE_SHORT 66 // 'short'
#define TK_CODE_SIGNED 67 // 'signed'
#define TK_CODE_SIZEOF 68 // 'sizeof'
#define TK_CODE_STATIC 69 // 'static'
#define TK_CODE_STRUCT 70 // 'struct'
#define TK_CODE_SWITCH 71 // 'switch'
#define TK_CODE_TYPEDEF 72 // 'typedef'
#define TK_CODE_UNION 73 // 'union'
#define TK_CODE_UNSIGNED 74 // 'unsigned'
#define TK_CODE_VOID 75 // 'void'
#define TK_CODE_VOLATILE 76 // 'volatile'
#define TK_CODE_WHILE 77 // 'while'

//String const
#define  TK_CODE_STRING 78

//IDENTIFICATORS
#define  TK_CODE_IDENTIFICATOR 79


struct CToken {
    int code;
    int span_line;
    int span_position;
    short category;
    char* source;
    short binary;
}typedef CToken;


