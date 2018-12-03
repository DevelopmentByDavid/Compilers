#include "header.h"


class CodeBlock {
    private:
        list<string *> curr_code;
        string * returnVal;
        list<string *> labelWaitingRoom;
        list<string *> varWaitingRoom;
    public:
        CodeBlock() {
            returnVal = new string("");
        }
        CodeBlock(CodeBlock &obj) {
            // cerr << obj.getVal() << endl;
            returnVal = new string(obj.getVal());
            curr_code = obj.getCode();
            labelWaitingRoom = obj.getLabels();
            varWaitingRoom = obj.varWaitingRoom;
        }
        CodeBlock(string init) {
            returnVal = new string(init);
        }
        ~CodeBlock() {
            // delete returnVal;
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
            // delete returnVal;
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
        }
        bool isNull() {
            if (curr_code.empty() && *returnVal == "" && labelWaitingRoom.empty() && varWaitingRoom.empty()) {
                return true;
            }
            return false;
        }
        CodeBlock & operator = (CodeBlock const &obj) {
            // CodeBlock ret;
            // cout << "shipping" << endl;
            returnVal = new string(*obj.returnVal);
            // cout << *obj.returnVal << " asdf" << endl;
            curr_code = obj.curr_code;
            // cout << obj.curr_code.empty() << endl;
            // ret.shipCode();
            labelWaitingRoom = obj.labelWaitingRoom;
            varWaitingRoom = obj.varWaitingRoom;
            // cout << "end ship" << endl;
            return *this;
        }
        CodeBlock & operator + (CodeBlock const &obj) {
            if (!obj.curr_code.empty()) {
                curr_code.insert(curr_code.end(), obj.curr_code.begin(), obj.curr_code.end());  
            }
            if (!obj.labelWaitingRoom.empty()) {
                labelWaitingRoom.insert(labelWaitingRoom.end(), obj.labelWaitingRoom.begin(), obj.labelWaitingRoom.end());
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
        void manualDelete() {
            for (list<string *>::iterator it = curr_code.begin(); it != curr_code.end(); ++it){
                delete *it;
            }
        }
        void push_back_label(string arg) {
            string *copy = new string(arg);
            labelWaitingRoom.push_back(copy);
        }
        void push_front_label(string arg) {
            string *copy = new string(arg);
            labelWaitingRoom.push_front(copy);
        }
        void pop_back_label_all() {
            while (!labelWaitingRoom.empty()) {
                string * temp = labelWaitingRoom.back();
                curr_code.push_back(new string(": " + *temp));
                labelWaitingRoom.pop_back();
            }
        }
        string getLabel() {
            if (!labelWaitingRoom.empty()) {
                return *labelWaitingRoom.back();
            }
            return "";
        }
        bool isLabel() {
            return labelWaitingRoom.empty();
        }
        list<string *> getLabels() {
            return labelWaitingRoom;
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