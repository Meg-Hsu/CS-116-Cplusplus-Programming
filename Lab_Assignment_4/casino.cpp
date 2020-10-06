//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//6 October 2020

#include "casino.h"
#include <iostream>
#include <string>
using namespace std;

const int TripleString::MIN_LEN = 1;
const int TripleString::MAX_LEN = 50;
const string TripleString::DEFAULT_STRING = "(undefined)";

const int MIN_BET = 0;
const int MAX_BET = 50;
const double BAR_LIMIT = RAND_MAX * .38;
const double CHERRIES_LIMIT = RAND_MAX * .78;
const double SPACE_LIMIT = RAND_MAX * .85;
const string BAR = "BAR";
const string CHERRIES = "cherries";
const string SPACE = "(space)";
const string SEVEN = "7";
const int PAYOUT0 = 0;
const int PAYOUT1 = 5;
const int PAYOUT2 = 15;
const int PAYOUT3 = 30;
const int PAYOUT4 = 50;
const int PAYOUT5 = 100;

//Constructors

TripleString::TripleString() {
	setString1(DEFAULT_STRING);
	setString2(DEFAULT_STRING);
	setString3(DEFAULT_STRING);
}

TripleString::TripleString(string str1, string str2, string str3) {
	if (!setString1(str1))
		string1 = DEFAULT_STRING;
	if (!setString2(str2))
		string2 = DEFAULT_STRING;
	if (!setString3(str3))
		string3 = DEFAULT_STRING;
}

//Accessors
string TripleString::getString1() {
	return string1;
}

string TripleString::getString2() {
	return string2;
}

string TripleString::getString3() {
	return string3;
}

string TripleString::toString() {
	return getString1() + ", " + getString2() +
		   ", " + getString3();

}

bool TripleString::validString(string str) {
	int num;
	num = str.length();
	if (num >= MIN_LEN && num <= MAX_LEN)
		return true;
	else {
		return false;
	}
}

//Mutators
bool TripleString::setString1(string str1) {
	if (validString(str1)) {
		string1 = str1;
		return true;
	} else {
		return false;
	}
}

bool TripleString::setString2(string str2) {
	if (validString(str2)) {
		string2 = str2;
		return true;
	} else {
		return false;
	}
}

bool TripleString::setString3(string str3) {
	if (validString(str3)) {
		string3 = str3;
		return true;
	} else {
		return false;
	}
}

//Global (Casino Functions)
int getBet() {
	int AmountBet;
	do {
		cout << "How much would you like to bet ($1 - 50) "
				"or 0 to quit? ";
		cin >> AmountBet;
	} while (AmountBet < MIN_BET || AmountBet > MAX_BET);
	return AmountBet;
}

//declare here for pull();
string randString();

TripleString pull() {
	TripleString output(randString(), randString(),
				 randString());
	return output;
}

string randString() {
	int random = rand();

	if (random <= BAR_LIMIT) {
		return BAR;
	} else if (random <= CHERRIES_LIMIT) {
		return CHERRIES;
	} else if (random <= SPACE_LIMIT) {
		return SPACE;
	} else {
		return SEVEN;
	}
}

int getPayMultiplier(TripleString thePull) {
	string string1 = thePull.getString1();
	string string2 = thePull.getString2();
	string string3 = thePull.getString3();

	//Set multiplier to 0 so that program only has to pick out
	//when it shouldn't be 0

	int payMultiplier = PAYOUT0;

	if (string1 == CHERRIES) {
		if (string2 == CHERRIES) {
			if (string3 == CHERRIES) {
				payMultiplier = PAYOUT3;
			} else {
				payMultiplier = PAYOUT2;
			}
		} else {
			payMultiplier = PAYOUT1;
		}
	} else if (string1 == BAR && string2 == BAR &&
			   string3 == BAR) {
		payMultiplier = PAYOUT4;
	} else if (string1 == SEVEN && string2 == SEVEN &&
			   string3 == SEVEN) {
		payMultiplier = PAYOUT5;
	}
	return payMultiplier;
}

void display(TripleString thePull, int winnings) {
	cout << "whirrrrrr .... and your pull is ...\n";
	cout << thePull.toString() << "\n";
	if (winnings > 0) {
		cout << "congratulations, you win: " << winnings << "\n\n";
	} else
		cout << "sorry, you lose.\n\n";
}
