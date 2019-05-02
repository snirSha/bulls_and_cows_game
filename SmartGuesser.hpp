#pragma once

#include <vector>
#include "Guesser.hpp"
#include <iostream>

using namespace std;
namespace bullpgia{

    class SmartGuesser : public bullpgia::Guesser{

    private:
       

    public:

        vector<char> Comb;
        int numG;
        int bull;
        int pgia;
        string Last;
        uint length;

        SmartGuesser(){}

        ~SmartGuesser(){}

        void learn(string reply)override ;

        void startNewGame(uint Length)override ;

        string guess()override ;

    };

}
