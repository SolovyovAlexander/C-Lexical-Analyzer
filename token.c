struct CToken {
    int code;
    int span_line;
    int span_position;
    short category;
    char* source;
    short binary;
} typedef CToken;