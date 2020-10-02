//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//29 September 2020

#include "triplestring.h"
#include <iostream>
#include <string>
using namespace std;

const int TripleString::MIN_LEN = 1;
const int TripleString::MAX_LEN = 50;
const string TripleString::DEFAULT_STRING= "(undefined)";

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
	return getString1() + " , " + getString2() +
			" , " + getString3();

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
