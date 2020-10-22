//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//29 September 2020

#include <iostream>
#include <string>
using namespace std;

#ifndef TripleString_H_
#define TripleString_H_

class TripleString {
private:
	string string1;
	string string2;
	string string3;

	static bool validString(string str);

public:

//Static Constants
	static const int MIN_LEN;
	static const int MAX_LEN;
	static const string DEFAULT_STRING;

//Constructors
	TripleString(string string1, string string2,
			string string3);
	TripleString();

//Accessors
	string getString1();
	string getString2();
	string getString3();
	string toString();

//Mutators
	bool setString1(string str1);
	bool setString2(string str2);
	bool setString3(string str3);
};

int getBet();
TripleString pull();
void display(TripleString thePull, int winnings);
string randString();
int getPayMultiplier (TripleString thePull);


#endif /* TripleString_H_ */
