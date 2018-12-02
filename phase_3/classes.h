#include "header.h"

class container {
    private:
        list<string> curr_code;
        string temp;
    public:
        container() {}
        ~container() {}
        void push_back(string arg) {
            curr_code.push_back(arg);
        }
        void push_front(string arg) {
            curr_code.push_front(arg);
        }
        string getTemp() {
            return temp;
        }
        void setTemp(string arg) {
            temp = arg;
        }
        void shipCode() {
            stringstream k;
            for (list<string>::iterator it = curr_code.begin(); it != curr_code.end(); ++it){
                    k << *it << endl;
            }           
            genCode(k.str());
        }
};