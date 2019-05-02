
#include "calculate.hpp"
using namespace std;

namespace bullpgia{
string calculateBullAndPgia(const string &choice, const string &guess) {
        string temp = choice;
        string temp2 = guess;
        unsigned int bull = 0;
        unsigned int pgia = 0;
        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == temp2[i]) {
                bull++;
                temp[i] = 'a';
                temp2[i] = 'z';
            }
        }
        for (int i = 0; i < temp.length(); i++) {
            for (int j = 0; j < temp2.length(); j++) {
                if (i != j && temp[i] == temp2[j]) {
                    pgia++;
                    temp[i] = 'a';
                    temp2[j] = 'z';
                }
            }
        }
        return to_string(bull) + "," + to_string(pgia);
    }

}
