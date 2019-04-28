#include "SmartGuesser.hpp"
#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int* bullpgia::SmartGuesser::invalidChoicesArray(string& str){

    for(int i=0; i<str.length();i++){
        this->arr[(str[i]-48)] = -1;
    }
    for(int i=0; i<10; i++){
        cout<<"-1 for bad numbers and 0 for numbers left to guess with"<<endl;
        cout<< arr[i] << "\t";
    }

    return arr;
}

void bullpgia::SmartGuesser::learn(string reply) {

    this->bull = reply[0];
    this->pgia = reply[2];
    if(this->bull==0 && this->pgia==0){
        invalidChoicesArray(this->clientGuess);
    }
    cout<<"last game was:reply[2] "+to_string(bull)+","+to_string(pgia) <<endl;
}

void bullpgia::SmartGuesser::startNewGame(uint Length) {
    this->length=Length;
    cout<<"Starting new game: "<<endl;
}

string bullpgia::SmartGuesser::guess() {


    return "";
}
