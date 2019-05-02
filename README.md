# bulls and cows/mastermind game in cpp

## Authors:

Snir Shaharabani

Amir Hoshen

Peleg Zborovsky

## About the game:

The rules of the game in our course are:

* We can use sizes from 1 to 10.
* The numbers are from 0 to 9 with repetitions.
* The number 0 can be the first number.
* We use "bulls" to tell the guesser that one of the numbers he chose is right and in the right place, but we don't tell him which one.
* We use "Pgias" ("cows") to tell the guesser that one of the numbers he chose is right but not in the right place, and we don't tell him which one.
* The guesser can countinue guessing until the 101'th turn or until he wins. 

## About the project:

### the project consist of 4 major classes:

* Chooser: A function that use random number with repetitions to build a string in length that the game's rules permits (the chooser string).

* Guesser: A class that let the user guess numbers in size that the game has set. The user will get the numbers of bulls and cows and make gusses until the 100'th turn or until he wins.

* Calculate: A class that calculate the number of the bulls and cows in every new guess.

* SmartGuesser: A program that uses the same 10 guesses (depends on the size that the game has set), for example: if the game set the size to 4, the program will guess 0000,1111,2222,.....,9999 until it gets 4 bulls.
              If the program gets in the guess "1111" 2 bulls, it learns that there are two 1's in the sequence, 
              and keep counting the bulls until it reaches 4.
              After it gets 4 numbers that are in the sequence, the program randomly arrange the digits that it received until it wins. 

Note: The SmartGuesser program is not very smart. In our cpp course we were asked to make a smart program that can beat the game in 100 and less guesses (size=4).

## Sources:

https://en.wikipedia.org/wiki/Mastermind_(board_game)

http://slovesnov.users.sourceforge.net/index.php?bullscows
