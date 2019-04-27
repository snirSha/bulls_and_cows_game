
#pragma once
#include "Chooser.hpp"
#include <string>

using namespace std;
namespace bullpgia{

	string bullpgia::Chooser choose(uint length){
		string numberChosen;
		std::cin>>numberChosen;	
		return numberChosen;
	}
}
