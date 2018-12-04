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
list<std::string> ARR;
list<fn> FUNCTIONS;

//yy stuff declarations
extern int yylex(void);
extern int yyparse();

//file related stuff
extern FILE* yyin;


struct fn {
    string name;
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
    } else {
        cerr << "Error line " << currLine << ": symbol \'" << toAdd << "\' already declared" << endl; 
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

void func(string name) {
    //push current stuff into the new fn
    fn temp;
    temp.name = name;
    temp.code = CODE;
    temp.symbolTable = SYMBOLTABLE;
    FUNCTIONS.push_back(temp);

    //clear current
    CODE  = list<string>();
    SYMBOLTABLE = list<string>();
    ARR = list<string>();
    //init
    funcify();
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
        cerr << "Error line " << currLine << ": symbol \'" << foo << "\' is not declared" << endl; 
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

void funcify() {
    for (list<fn>::iterator it = FUNCTIONS.begin(); it != FUNCTIONS.end(); ++it) {
        SYMBOLTABLE.push_back(it->name);
    }
}

void verify() {
    for (list<fn>::iterator it = FUNCTIONS.begin(); it != FUNCTIONS.end(); ++it) {
        if (it->name.compare("main") == 0) {
            return;
        }
    }
    cerr << "ERROR! No main declaration." << endl;
}

void addArr(string foo) {
    ARR.push_back(foo);
}

void checkArr(string foo) {
    for (list<string>::iterator it = ARR.begin(); it != ARR.end(); ++it) {
        if (it->compare(foo) == 0) return;
    }
    cerr << "Error Line " << currLine << ": variable is not an array" << endl;
}

void inverseCheckArr(string foo) {
    for (list<string>::iterator it = ARR.begin(); it != ARR.end(); ++it) {
        if (it->compare(foo) == 0) {
            cerr << "Error Line " << currLine << ": must specify index with array type variables" << endl;
        }
    }
}
