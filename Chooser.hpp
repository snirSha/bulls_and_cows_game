#pragma once
#include "calculate.hpp"
#include <string>
using namespace std;


namespace bullpgia{

    class Chooser{

    private:
        string clientChoose;

    public:

        uint length;

        Chooser(){
            this->clientChoose="";
        }

        Chooser(const string& cho){
            if(cho.length()>0 && cho.length()<=10){
                this->clientChoose = cho;
            }
        }

        virtual string choose(uint length)=0;

        virtual ~Chooser(){}

    };
}
