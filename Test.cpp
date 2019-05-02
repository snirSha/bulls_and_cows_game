
/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;
		
		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 100 turns!
		}
		
		//MY TESTS///////////////////////////////////////////////////////////////////////////////////////////////////
		testcase.setname("Mt Test-Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1231","1113"), "1,2")      //1 bull,2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1112","2111"), "2,2")      //2 bull,2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("7900","9070"), "1,3")      //1 bull,3 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1231","1113"), "1,2")      //1 bull,2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("8000","1888"), "0,1")      //0 bull,1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("9999","7890"), "1,0")      //1 bull,0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2019","1111"), "1,0")      //1 bull,0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2020","2200"), "2,2")      //2 bull,2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("6661","1116"), "0,2")      //0 bull,2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("9920","2922"), "2,0")      //2 bull,0 pgia	
		;

		ConstantChooser c1114{"1114"}, c12121{"12121"}, c9090{"9090"}, c123456789{"123456789"}, c0000{"0000"}, c999{"999"};
		ConstantGuesser g1235{"1235"}, g54321{"54321"}, g999{"999"}, g123456789{"123456789"}, g1234567890{"1234567890"};

		testcase.setname("My test-Play with dummy choosers and guessers")		
		.CHECK_EQUAL(play(c1114, g1235, 4, 100), 101)             // guesser loses by running out of turns.
		.CHECK_EQUAL(play(c12121, g54321, 4, 100), 0)             // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c9090, g999, 4, 100), 101)              // guesser loses technically by making an illegal guess (too short).
		.CHECK_EQUAL(play(c9090, g1235, 4, 100), 101)             // guesser loses by running out of turns.		
		.CHECK_EQUAL(play(c123456789, g123456789, 9, 100), 1)     // guesser wins in one turn.
		.CHECK_EQUAL(play(c123456789, g1234567890, 9, 100), 101)  // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c123456789, g1234567890, 10, 100), 0)   // chooser loses technically by choosing an illegal number (too short).
		.CHECK_EQUAL(play(c0000, g1235, 4, 100), 101)             // guesser loses by running out of turns. (we can start with zero).
		.CHECK_EQUAL(play(c12121, g54321, 5, 100), 101)           // guesser loses by running out of turns.
		.CHECK_EQUAL(play(c999, g999, 3, 100), 1)                 // guesser wins in one turn.
		;
 		  		 

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
