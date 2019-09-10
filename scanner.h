#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "string.h"


CToken* get_next_token(FILE *fp);


struct for_check_func{
    int token_code;
    int length;
} typedef fcf;
