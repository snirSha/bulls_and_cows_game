
#include "calculate.hpp"
using namespace std;

namespace bullpgia{
string calculateBullAndPgia(const string &choice, const string &guess) {
        uint bull=0;
    uint pgia=0;

    for(int i =0; i<choice.length();i++){
        for(int j=0; j<guess.length(); j++){
            if(i==j && choice[i]==guess[j]){
                ++bull;
            }else if(i!=j && choice[i]==guess[j]){
                ++pgia;
            }
        }
    }

    return to_string(bull)+","+to_string(pgia);
    }
}
