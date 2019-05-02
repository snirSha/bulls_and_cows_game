#include "DummyChoosers.hpp"
#include <stdlib.h>
#include <ctime>

std::string RandomChooser::choose(uint length) {
	srand(time(NULL));
	std::string r="";
	for (uint i=0; i<length; ++i) {
		char c = '0' + (rand()%10);
		r += c;
	}
	return r;
}
