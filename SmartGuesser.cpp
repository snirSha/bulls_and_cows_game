#include <iostream>
#include <algorithm>
#include "SmartGuesser.hpp"
using namespace std;

void bullpgia::SmartGuesser::learn(string reply) {
    if(Comb.size()<length){
        bull = reply[0]-48;
        pgia = reply[2]-48;
        for(int i = 0;i<bull;i++){
            Comb.push_back(numG);
        }
        for(int i = 0;i<pgia;i++){
            Comb.push_back(numG);
        }

    }else if(Comb.size() == length){
        Last.clear();
        for(int i=0;i<length;i++){
            Last.push_back(Comb[i]);
        }
    }
    if(numG<'9')
        numG++;
}

void bullpgia::SmartGuesser::startNewGame(uint Length) {
    length=Length;
    Comb.clear();
    Comb.reserve(length);
    pgia=0;
    bull = 0;
    Last.clear();
    numG='0';

    cout<<"Staring new game: "<<endl;
}

string bullpgia::SmartGuesser::guess() {
    if(Comb.size()<length){
        Last.clear();
        for(int i=0 ;i<length;i++){

            Last.push_back(numG);
        }
    }else{
        random_shuffle(Last.begin(), Last.end());
    }
    return Last;
}
