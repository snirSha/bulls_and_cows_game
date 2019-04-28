#pragma once

#include "Guesser.hpp"
#include <iostream>

using namespace std;
namespace bullpgia{

    class SmartGuesser : public bullpgia::Guesser{

    private:
        string clientGuess;
        string bestGuess = " ";

    public:
        uint length;
        uint bull;
        uint pgia;
        int arr[10] = {0,0,0,0,0,0,0,0,0,0};

        int* invalidChoicesArray(string& str);

        void setBestGuess(string newGuess){
            this->bestGuess = newGuess;
        }

        string getBestGuess(){
            return this->bestGuess;
        }

        SmartGuesser(){}

        SmartGuesser(const string& smart){
            this->clientGuess = smart;
        }

        ~SmartGuesser(){}

        void learn(string reply)override ;

        void startNewGame(uint Length)override ;

        string guess()override ;

    };

}
