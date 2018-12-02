#include "header.h"

//for all variables
#define VAR_PREFIX "__temp__"
int VAR_COUNT = 0;

#define LABEL_PREFIX "__label__"
int LABEL_COUNT = 0;

//forward decl
struct fn;

//global symbol table
list<std::string> SYMBOLTABLE;
list<std::string> CODE;
list<fn> FUNCTIONS;
stack<string> GOTO;

//yy stuff declarations
extern int yylex(void);
extern int yyparse();

//file related stuff
extern FILE* yyin;


struct fn {
    list<std::string> code;
    list<std::string> symbolTable;
};


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
    for (list<string>::iterator it = SYMBOLTABLE.begin(); it != SYMBOLTABLE.end(); ++it){
        if (toCheck.compare(*it) == 0) return 1;
    }
    return 0;
}

int addTable(string toAdd) {
    if (!exist(toAdd)) {
        SYMBOLTABLE.push_front(toAdd);
        return 1;
    }
    return 0;
}

void print() {
    for (list<fn>::iterator it = FUNCTIONS.begin(); it != FUNCTIONS.end(); ++it){
        for (list<string>::iterator itt = it->code.begin(); itt != it->code.end(); ++itt) {
            cout << *itt << endl;
        }
    }
}

void func() {
    //push current stuff into the new fn
    fn temp;

    temp.code = CODE;
    temp.symbolTable = SYMBOLTABLE;
    FUNCTIONS.push_back(temp);

    //clear current
    CODE  = list<string>();
    SYMBOLTABLE = list<string>();
}

void genCode(string code) {
    CODE.push_back(code);
} 

string newTemp() {
    stringstream temp;
    temp << VAR_PREFIX;
    temp << VAR_COUNT;
    VAR_COUNT++;
    addTable(temp.str());
    // genCode(". " + temp.str());
    return temp.str();
}

void undeclared(string foo) {
    if (!exist(foo)) {
        cerr << "ERROR! \'" + foo + "\' is undeclared" << endl;
    }
}

string newLabel() {
    stringstream temp;
    temp << LABEL_PREFIX;
    temp << LABEL_COUNT;
    LABEL_COUNT++;
    addTable(temp.str());
    return temp.str();
}

string pop_goto() {
    if (!GOTO.empty()) {
        string temp = GOTO.top();
        GOTO.pop();
        return temp;
    }
    return "";
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
