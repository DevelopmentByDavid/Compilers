#include "header.h"


class CodeBlock {
    private:
        list<string *> curr_code;
        string * returnVal;
    public:
        CodeBlock() {
            returnVal = new string("");
        }
        CodeBlock(CodeBlock &obj) {
            // cerr << obj.getVal() << endl;
            returnVal = new string(obj.getVal());
            curr_code = obj.getCode();
        }
        ~CodeBlock() {
            delete returnVal;
        }
        void push_back(string arg) {
            string *copy = new string(arg);
            curr_code.push_back(copy);
        }
        void push_front(string arg) {
            string *copy = new string(arg);
            curr_code.push_front(copy);
        }
        string getVal() {
            return *returnVal;
        }
        void setVal(string arg) {
            delete returnVal;
            returnVal = new string(arg);
        }
        list<string *> getCode() {
            return curr_code;
        }
        void shipCode() {
            if (!curr_code.empty()) {
                stringstream k;
                for (list<string*>::iterator it = curr_code.begin(); it != curr_code.end(); ++it){
                    k << **it << endl;
                    // cerr << "ship" << **it << endl;
                }
                genCode(k.str());   
            }
            // if (*returnVal != "" && returnVal->length() > 1) {
            //     genCode(*returnVal);
            // } 
        }
        bool isNull() {
            if (curr_code.empty() && *returnVal == "") {
                return true;
            }
            return false;
        }
        CodeBlock operator = (CodeBlock &obj) {
            CodeBlock ret;
            if (!obj.isNull()) {
                ret.returnVal = new string(obj.getVal());
                ret.curr_code = obj.getCode();
            }
            return ret;
        }
        void manualDelete() {
            for (list<string *>::iterator it = curr_code.begin(); it != curr_code.end(); ++it){
                delete *it;
            }
        }
};