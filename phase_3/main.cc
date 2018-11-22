#include <stdio.h>
#include "header.h"

//for all variables
#define VAR_PREFIX __temp__
int VAR_COUNT = 0;
stringstream k;


extern int yylex(void);
void yyparse();
extern FILE* yyin;
int callCount = 0;

int main(int argc, char **argv) {
   if (argc > 1) {
      yyin = fopen(argv[1], "r");
      if (yyin == NULL){
         printf("syntax: %s filename\n", argv[0]);
      }//end if
   }//end if
   yyparse(); // Calls yylex() for tokens.
   return 0;
}

void test(char *foo) {
    //cout << foo << endl;
    //cout << string(foo) << endl;
    free(foo);
}

void funcName(char *name) {
    k << "func " + string(name) + "\n";
    free(name);
    //cout << "func " << k.str() << endl;
}

/*
   var related functions below
*/
void scalarVar(char *arg) {
   k << ". " + string(arg) + "\n";
   free(arg);
   // cout << k.str() << endl;
}

void arrayVar(char *name, char *size) { 
   k << ". [ ]" << name << ", "<< size << "\n";
   free(name);
   // free(size);
   callCount++;
   cout << callCount << endl;
}

void print() {
   cout << k.str() << endl;
}