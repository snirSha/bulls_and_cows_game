
#pragma once

#include "Guesser.hpp"
#include <iostream>


using namespace std;

namespace bullpgia{

    class SmartGuesser : public bullpgia::Guesser{

    private:

        string clientGuess;

    public:

        uint length;

        SmartGuesser(){}

        SmartGuesser(const string& smart){
            this->clientGuess = smart;
        }

        ~SmartGuesser(){}

        void learn(string reply) override;

        void startNewGame(uint length)override;

        string guess() override ;
    };
}
