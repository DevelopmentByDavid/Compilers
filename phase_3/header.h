//necessary so includes are not included multiple times
#pragma once

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <sstream>
#include <cassert>
#include <stdio.h>
#include <stack>

using namespace std;

//forward decl
class CodeBlock;

// The following line suppresses an unused-function warning.
#define YY_NO_UNPUT

//generates new temp variable
extern string newTemp();
//adds the string to the symbol table
extern int addTable(string);
//check if the variable already exists in the table
extern int exist(string);
//prints all code generated
extern void print();
//pulls ownership of symboltable/code to a single function struct and resets globals
extern void func(string name);
//generates code to push into global CODE list
extern void genCode(string );
//checks if a variable being is undeclared
extern void undeclared(string);
//generates a new label
extern string newLabel();
//adds all existing function names to the symbol table after a wipe; called in func
extern void funcify();
//verifies that a main function was/is declared
extern void verify();
//records a particular variable as an array
extern void addArr(string);
//checks if the variable is an array; outputs if it is not and has an index
extern void checkArr(string);
//checks if a variable is an array; outputs if it is and is missing index
extern void inverseCheckArr(string);
//needed for error messages; maintained in mini_l.l
extern int currLine;

//THIS MUST BE INCLUDED LAST FOR STUFF TO WORK
//IT'S ANNOYING BUT NECESSARY
//know this from a SO answer that I didn't save the link to
//google something like include order for parser generators or something
#include "mini_l.tab.h"