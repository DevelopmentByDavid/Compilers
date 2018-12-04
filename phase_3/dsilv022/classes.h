#include "header.h"


class CodeBlock {
    private:
        //current code block/chunk
        list<string *> curr_code;
        //value to return/bubble up to the container rule
        string * returnVal;
        //waiting room for generated labels
        list<string *> labelWaitingRoom;
        //lines that labels are on for error messages when continue is not w/in a loop
        //parallel list to labelWaitingRoom
        list<int> labelLines;
        //waiting room for variables; needed for comma seperated writes/reads
        list<string *> varWaitingRoom;
    public:
        //overloaded constructors
        //default
        CodeBlock() {
            returnVal = new string("");
        }
        //one invoked when using $$ = new CodeBlock(<some codeblock>);
        CodeBlock(CodeBlock &obj) {
            //I can just access the curr_code and returnValue directly like I do for last 3
            //but this works so why change it ¯\_(ツ)_/¯
            returnVal = new string(obj.getVal());
            curr_code = obj.getCode();
            labelWaitingRoom = obj.labelWaitingRoom;
            labelLines = obj.labelLines;
            varWaitingRoom = obj.varWaitingRoom;
        }
        //invoked when using $$ = new CodeBlock(""); in epsilon rules
        CodeBlock(string init) {
            returnVal = new string(init);
        }
        ~CodeBlock() {
            //i never delete anything but valgrind says 0 memory leaks and
            //my ram thinks there's no memory leaks too, so that's good
        }
        //helper push_back to curr_code
        void push_back(string arg) {
            string *copy = new string(arg);
            curr_code.push_back(copy);
        }
        //helper push_front to curr_code
        void push_front(string arg) {
            string *copy = new string(arg);
            curr_code.push_front(copy);
        }
        //self-explanatory: the phantom explanation
        string getVal() {
            return *returnVal;
        }
        //self-explanatory part 2: attack of the explanations
        void setVal(string arg) {
            returnVal = new string(arg);
        }
        //self-explanatory part 3: revenge of the explanations
        list<string *> getCode() {
            return curr_code;
        }
        //fedex for my generated code
        //packages generated code into stringstream and sends it to genCode
        void shipCode() {
            if (!curr_code.empty()) {
                stringstream k;
                for (list<string*>::iterator it = curr_code.begin(); it != curr_code.end(); ++it){
                    k << **it << endl;
                }
                genCode(k.str());   
            }
        }
        //self-explanatory part 4; a new explanation
        bool isNull() {
            if (curr_code.empty()
            && *returnVal == ""
            && labelWaitingRoom.empty()
            && labelLines.empty()
            && varWaitingRoom.empty()) {
                return true;
            }
            return false;
        }
        //overloading = operator; guide found from http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html
        CodeBlock & operator = (CodeBlock const &obj) {
            returnVal = new string(*obj.returnVal);
            curr_code = obj.curr_code;
            labelWaitingRoom = obj.labelWaitingRoom;
            varWaitingRoom = obj.varWaitingRoom;
            labelLines = obj.labelLines;
            return *this;
        }
        //overloading + operator; the same guide http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html
        //essentially just adds the lists together
        //LOSES RETURNVAL OF BOTH LEFT AND RIGHT OPERAND THOUGH!!!!!!!
        //MUST SET THIS MANUALLY IN THE SEMANTIC ACTION
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
        //overloading += operator; still the same guide http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html
        //yeah this was straightforward, but I think i had to declared + and = first above for this to work; not sure
        CodeBlock & operator += (CodeBlock const &obj) {
            *this = *this + obj;
            return *this;
        }
        //checks for any "dangling" labels; this means that a continue was not within a loop
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
        //self-explanatory part 5; the explanations strike back
        void push_back_label(string arg) {
            labelLines.push_back(currLine);
            string *copy = new string(arg);
            labelWaitingRoom.push_back(copy);
        }
        //called inside loops, pops all current labels contained within "this"
        //and pushes them into curr_code
        void pop_back_label_all() {
            while (!labelWaitingRoom.empty()) {
                string * temp = labelWaitingRoom.back();
                curr_code.push_back(new string(": " + *temp));
                labelWaitingRoom.pop_back();
                labelLines.pop_back();
            }
        }
        //self-explanatory part 6; return of the explanations
        void push_var(string arg) {
            varWaitingRoom.push_back(new string(arg));
        }
        //used for read/write sequences
        //pops all vars in var waiting room and generates all associated code from the read/write
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