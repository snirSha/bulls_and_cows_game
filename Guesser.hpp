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
        //static int guessNumber;
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
            //setBullCounter(std::stoi(this->clientGuess.substr(0 , position)));
            //setPgiaCounter(std::stoi(this->clientGuess.substr(position+1, this->clientGuess.length()-1)));
            cout<<"learning"<<endl;
        }

        virtual void startNewGame(uint length){
            cout<<"New game has started"<<endl;
            setBullCounter(0);
            setPgiaCounter(0);
            this->length=length;
            //this->guessNumber = 0;
        }

        virtual string guess(){
            //this->guessNumber++;
            string newGuess="";
            cin>>newGuess;
            return newGuess;
        }

    };
}
