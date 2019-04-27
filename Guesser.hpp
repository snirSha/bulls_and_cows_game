
#pragma once
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
	static int guessNumber;
        uint length;

        Guesser(){
            this->clientGuess = "";
        }

        Guesser(const string& guess){
            if(guess.length()>0 && guess.length()<=10){
                this->clientGuess = guess;
            }
        }

        virtual ~Guesser(){}

        virtual void learn(string reply){}

        virtual void startNewGame(uint length){}

        virtual string guess()=0;

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
    };

}
