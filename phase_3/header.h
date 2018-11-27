// -*- c++ -*- 
// heading.H
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <sstream>
#include <cassert>
#include <stdio.h>
using namespace std;

#include "mini_l.tab.h"


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


// struct quad {
//     int op;
//     node *src1;
//     node *src2;
//     node *dest;
// };


extern string newTemp();
extern int addTable(string);
extern int exist(string);
extern void print();
extern void func();
extern void genCode(string );


