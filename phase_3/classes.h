#include "header.h"


class CodeBlock {
    private:
        list<string *> curr_code;
        string * returnVal;
        list<string *> labelWaitingRoom;
        list<int> labelLines;
        list<string *> varWaitingRoom;
    public:
        CodeBlock() {
            returnVal = new string("");
        }
        CodeBlock(CodeBlock &obj) {
            returnVal = new string(obj.getVal());
            curr_code = obj.getCode();
            labelWaitingRoom = obj.labelWaitingRoom;
            labelLines = obj.labelLines;
            varWaitingRoom = obj.varWaitingRoom;
        }
        CodeBlock(string init) {
            returnVal = new string(init);
        }
        ~CodeBlock() {

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
                }
                genCode(k.str());   
            }
        }
        bool isNull() {
            if (curr_code.empty() && *returnVal == "" && labelWaitingRoom.empty() && varWaitingRoom.empty()) {
                return true;
            }
            return false;
        }
        CodeBlock & operator = (CodeBlock const &obj) {
            returnVal = new string(*obj.returnVal);
            curr_code = obj.curr_code;
            labelWaitingRoom = obj.labelWaitingRoom;
            varWaitingRoom = obj.varWaitingRoom;
            labelLines = obj.labelLines;
            return *this;
        }
        CodeBlock & operator + (CodeBlock const &obj) {
            if (!obj.curr_code.empty()) {
                curr_code.insert(curr_code.end(), obj.curr_code.begin(), obj.curr_code.end());  
            }
            if (!obj.labelWaitingRoom.empty()) {
                labelWaitingRoom.insert(labelWaitingRoom.end(), obj.labelWaitingRoom.begin(), obj.labelWaitingRoom.end());
            }
            if (!obj.labelLines.empty()) {
                labelLines.insert(labelLines.end(), obj.labelLines.begin(), obj.labelLines.end());
            }
            if (!obj.varWaitingRoom.empty()) {
                varWaitingRoom.insert(varWaitingRoom.end(), obj.varWaitingRoom.begin(), obj.varWaitingRoom.end());
            }
            return *this;
        }
        CodeBlock & operator += (CodeBlock const &obj) {
            *this = *this + obj;
            return *this;
        }
        void danglingLabels() {
            if (!labelWaitingRoom.empty()) {
                while (!labelWaitingRoom.empty()) {
                    int temp = labelLines.front();
                    cerr << "Error Line " << temp << ": continue statement not within a loop" << endl;
                    labelWaitingRoom.pop_front();
                    labelLines.pop_front();
                }
            }
        }
        void push_back_label(string arg) {
            labelLines.push_back(currLine);
            string *copy = new string(arg);
            labelWaitingRoom.push_back(copy);
        }
        void pop_back_label_all() {
            while (!labelWaitingRoom.empty()) {
                string * temp = labelWaitingRoom.back();
                curr_code.push_back(new string(": " + *temp));
                labelWaitingRoom.pop_back();
                labelLines.pop_back();
            }
        }
        void push_var(string arg) {
            varWaitingRoom.push_back(new string(arg));
        }
        void pop_var(string prepend) {
            while (!varWaitingRoom.empty()) {
                string foo = *varWaitingRoom.back();
                if (!exist(foo)) {
                    curr_code.push_back(new string(".[]" + prepend + " " + foo));
                } else {
                    curr_code.push_back(new string("." + prepend + " " + foo));
                }
                varWaitingRoom.pop_back();
            }
        }
        
};