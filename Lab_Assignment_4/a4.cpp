//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//6 October 2020

#include <iostream>
#include <string>
#include "casino.h"
using namespace std;

int main() {
	srand(time(NULL));
	int quit, amountbet, winnings;
	quit = 0;
	TripleString thePull;

	while (true) {
		amountbet = getBet();
		if (amountbet == quit)
			break;
		thePull = pull();
		winnings = amountbet * getPayMultiplier(thePull);
		display(thePull, winnings);
	}
	return 0;
}

//test runs

//How much would you like to bet ($1 - 50) or 0 to quit? -1
//How much would you like to bet ($1 - 50) or 0 to quit? 100
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//cherries, BAR, cherries
//congratulations, you win: 25
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//cherries, BAR, cherries
//congratulations, you win: 25
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//cherries, 7, BAR
//congratulations, you win: 25
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//BAR, cherries, cherries
//sorry, you lose.
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//cherries, cherries, BAR
//congratulations, you win: 75
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//BAR, BAR, cherries
//sorry, you lose.
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//cherries, cherries, cherries
//congratulations, you win: 150
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//cherries, BAR, BAR
//congratulations, you win: 25
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//cherries, BAR, BAR
//congratulations, you win: 25
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//(space), cherries, BAR
//sorry, you lose.
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//cherries, cherries, BAR
//congratulations, you win: 75
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//cherries, cherries, cherries
//congratulations, you win: 150
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//cherries, BAR, 7
//congratulations, you win: 25
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//cherries, cherries, BAR
//congratulations, you win: 75
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//BAR, BAR, BAR
//congratulations, you win: 250
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//7, cherries, cherries
//sorry, you lose.
//
//How much would you like to bet ($1 - 50) or 0 to quit? 5
//whirrrrrr .... and your pull is ...
//cherries, 7, BAR
//congratulations, you win: 25
//
//How much would you like to bet ($1 - 50) or 0 to quit? 0

