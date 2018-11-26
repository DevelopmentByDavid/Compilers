#include <stdio.h>
#include "header.h"

//for all variables
#define VAR_PREFIX "__temp__"
int VAR_COUNT = 0;
stringstream k;

//yy stuff declarations
extern int yylex(void);
extern int yyparse();

//file related stuff
extern FILE* yyin;

//global symbol table stuff
string symbolTable[250];
int symbolIndex = 0;

//begin main
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

int exist(string toCheck) {
    for (int i = 0; i < symbolIndex; i++) {
        if (symbolTable[i].compare(toCheck) == 0) {
            return 1;
        }
    }
    return 0;
}

string *addTable(string *toAdd) {
    *toAdd = ". " + *toAdd;
    // string foo = *toAdd;
    if (!exist(*toAdd)) {
        symbolTable[symbolIndex] = *toAdd;
        symbolIndex++;
    }
    // cout << string(toAdd) << endl;
    // free(toAdd);
    return toAdd;
}

string newTemp() {
    stringstream temp;
    temp << VAR_PREFIX;
    temp << VAR_COUNT;
    VAR_COUNT++;
    return temp.str();
}

// void addTable(string toAdd) {
//     symbolTable[symbolIndex] = toAdd;
//     symbolIndex++;
// }

// int inTable(string toCheck) {
//     for (int i = 0; i < symbolIndex; i++) {
//         if (symbolTable[symbolIndex] == toCheck) {
//             addTable(toCheck);
//             return 1;
//         }
//     }
//     return 0;
// }


void funcName(char *name) {
    string temp = "func " + string(name);
    symbolTable[symbolIndex] = temp;
    symbolIndex++;
    // k << "func " + string(name) + "\n";
    free(name);
    
}

// /*
//    var related functions below
// */
// void scalarVar(char *arg) {
//     string temp = string(arg);
//     if (!inTable(temp)) {
//         k << ". " + string(arg) + "\n"; 
//     }
//     free(arg);
//    // cout << k.str() << endl;
// }

// void arrayVar(char *name, char *size) {
//     string temp1, temp2;
//     temp1 = string(name);
//     temp2 = string(size);
//     if (!inTable(temp1)) {
//         k << ". [ ]" << name << ", "<< size << "\n";
//     }
//     free(name);
//     // free(size);
// }

void print() {
    for (int i = 0; i < symbolIndex; i++) {
        cout << symbolTable[i] << endl;
    }
//    cout << k.str() << endl;
}

void print(string *foo) {
    cout << *foo << endl;
}