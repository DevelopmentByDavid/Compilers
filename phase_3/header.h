// -*- c++ -*- 
// heading.H
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <sstream>
#include <cassert>
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

// class node {
//     protected:
//         stringstream val;
//     public:
//         node() {}
//         ~node() {}
//         virtual string getVal() {return val.str();}
// };

// class fnNode: public node {
//     public:
//         fnNode(char *name) {
//             val << string(name);
//         }
//         ~fnNode() {} 
// };

// struct quad {
//     int op;
//     node *src1;
//     node *src2;
//     node *dest;
// };


// extern void test(char *);
extern void funcName(char *);
// extern void scalarVar(char *);
extern void print();
extern void print(string *);
// extern void arrayVar(char *, char *);
// extern int inTable(string);
// extern void addTable(string);
extern string newTemp();
extern string *addTable(string *);
extern int exist(string);


// define each macro

inline string itoa( int x ) {  // converts an integer to a string.
  ostringstream s;
  s << x;
  return s.str();
}