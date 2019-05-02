#include "Chooser.hpp"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;
namespace bullpgia{

    string bullpgia::Chooser::choose(uint length){
    string numberChosen;

    //initializing random number
    int item[10] = {0,1,2,3,4,5,6,7,8,9},r;
        srand(time(NULL));
        for(int x=length; x>0; x--){
            r = rand()%x;
            cout << item[r] << "\t";
            while(r<x-1){
                item[r] = item[r+1];
                r++;
            }
        }

        for(int i=0; i<length; i++)
            numberChosen += item[i];


    return numberChosen;
}
}
