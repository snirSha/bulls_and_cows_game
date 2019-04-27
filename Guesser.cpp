#pragma once
#include <iostream>
#include "Guesser.hpp"
using namespace std;
using namespace bullpgia{

     void bullpgia::Guesser learn(string reply){
        int position = this->clientGuess.find(",");
        setBullCounter(std::stoi(this->clientGuess.substr(0 , position)));
        setPgiaCounter(std::stoi(this->clientGuess.substr(position+1, this->clientGuess.length-1)));
	cout<<"learning"<<endl;
    }

     void bullpgia::Guesser startNewGame(uint length){
      cout<<"New game has started"<<endl;
	setBullCounter(0);
	setPgiaCounter(0);
	this->lenght=lenght;
	this->guessNumber=0;
     }

     string bullpgia::Guesser guess(){
	this->guessNumber++;
	string newGuess="";
	std::cin>>newGuess;
        return newGuess;
     }

}	
