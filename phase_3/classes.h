#include "header.h"

class node {
    protected:
        stringstream code;
    public:
        node() {}
        ~node() {}
        virtual void print() {cout << code.str();}
};

class fnNode: public node {
    private:
        list<string> fnSymbolTable;
    public:
        void copyTable(list<string> symbolTable) {
            fnSymbolTable = symbolTable;
            symbolTable = list<string>();
        }
        fnNode(string name) {
            code << "func " + name;
        }
        ~fnNode() {} 
};

class sVarNode: public node {
    public:
        sVarNode(string foo) {
            addTable(foo);
        }
};