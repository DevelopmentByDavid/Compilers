
// #include "header.h"
#include <stdio.h>
#include <iostream>
#include <string>

extern int yylex(void);
extern FILE* yyin;

int main(int argc, char **argv) {
    // yyin = fopen
    yylex();
    return 0;
}