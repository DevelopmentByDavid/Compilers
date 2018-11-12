// -*- c++ -*- 
// heading.H

using namespace std;

// The following line suppresses an unused-function warning.
#define YY_NO_UNPUT

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <sstream>
#include <cassert>

extern void test(char *);
extern void funcName(char *);

// define each macro

inline string itoa( int x ) {  // converts an integer to a string.
  ostringstream s;
  s << x;
  return s.str();
}