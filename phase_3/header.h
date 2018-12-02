// -*- c++ -*- 
// heading.H

#pragma once //ALSO SOMEWHAT NECESSARY; MAKES LIFE EASIER
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



// The following line suppresses an unused-function warning.
#define YY_NO_UNPUT

//macros for all operands
#define _ASSIGN  1
#define _OR      2
#define _AND     3
#define _NOT     4
#define _NEQ     5
#define _EQ      6
#define _GTE     7
#define _LTE     8
#define _LT      9
#define _SUB     10
#define _ADD    11
#define _MOD    12
#define _DIV    13
#define _MULT   14
#define _GT    15

struct arr_struct {
    string src;
    string dest;
    string index;
};

extern string newTemp();
extern int addTable(string);
extern int exist(string);
extern void print();
extern void func(string);
extern void genCode(string );
extern void undeclared(string);
extern string arrHandler(string);
extern string newLabel();
extern void push_goto(string);
extern string pop_goto();
extern string soft_pop();

//THIS MUST BE INCLUDED LAST FOR STUFF TO WORK
//IT'S ANNOYING BUT NECESSARY
#include "mini_l.tab.h"


