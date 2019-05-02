#pragma once

#include <iostream>
#include "calculate.hpp"
#include <string>
using namespace std;

namespace bullpgia{

    class Guesser{

    private:
        int bullCounter;
        int pgiaCounter;
        string clientGuess;


    public:

        uint length;

        Guesser(){
            this->clientGuess = "";
        }

        Guesser(const string& guess){
            if(guess.length()>0 && guess.length()<=10){
                this->clientGuess = guess;
            }
        }
        int getBullCounter(){
            return bullCounter;
        }
        int getPgiaCounter(){
            return pgiaCounter;
        }
        void setBullCounter(int bulls){
            this->bullCounter=bulls;
        }
        void setPgiaCounter(int pgias){
            this->pgiaCounter=pgias;
        }

        virtual ~Guesser(){}

        virtual void learn(string reply){
            int position = this->clientGuess.find(",");
        }

        virtual void startNewGame(uint length){
            //cout<<"New game has started"<<endl;
            setBullCounter(0);
            setPgiaCounter(0);
            this->length=length;

        }

        virtual string guess(){
            string newGuess="";
            cin>>newGuess;
            return newGuess;
        }

    };
}
