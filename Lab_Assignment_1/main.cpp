//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//15 September 2020

//Program Output:

//This program collects the following information:
//- Last name (between 2 and 15 characters)
//- Student ID (6 numbers, can't lead with 0)
//- A positive numerical value to be tripled through various (value and reference) means
//
//Please enter your last name (between 2 and 15 characters): a
//The name entered is not between 2 and 15 characters. Please try again.
//Please enter your last name (between 2 and 15 characters): aaaaaaaaaaaaaaaa
//The name entered is not between 2 and 15 characters. Please try again.
//Please enter your last name (between 2 and 15 characters): Hsu
//
//Please enter your student ID (at least 6 characters): 12345
//The ID entered is less than 6 numbers. Please try again.
//Please enter your student ID (at least 6 characters): 497864
//
//Please enter a positive numerical value you would like to have tripled by value: -1
//-1 isn't a valid input, please try again.
//
//Please enter a positive numerical value you would like to have tripled by value: 3
//
//Please enter a positive numerical value you would like to have tripled by reference: -5
//-5 isn't a valid input, please try again.
//
//Please enter a positive numerical value you would like to have tripled by reference: 3
//
//
//The original number to be tripled by value is 3.
//The original number to be tripled by reference is 3.
//
//The number tripled by value is 9.
//The number tripled by reference is 9.
//
//The value of the number in main after tripled by value is 3.
//The value of the number in main after tripled by value is 9.
//
//Would you like to run this program again? (y/n) n


#include <iostream>
#include <string>
#include "triple.h"
using namespace std;


int main() {
	//There's a do while loop in main so that the runagain() function can be used.
	do {
		intro();
		wstring name;
		name = validlname();
		int id;
		id = validid();

		int originalvalue;
		int originalreference;
		originalvalue = validnumbertriple(" by value");
		originalreference = validnumbertriple(" by reference");

		cout << "\n\nThe original number to be tripled by value is " << originalvalue << ".\n";
		cout << "The original number to be tripled by reference is "<< originalreference << ".\n\n";

		cout << "The number tripled by value is " << tripleByValue(originalvalue) << ".\n";
		tripleByReference(originalreference);

		cout << "The value of the number in main after tripled by value is " << originalvalue << ".\n";
		cout << "The value of the number in main after tripled by value is " << originalreference << ".\n";

	} while (runagain() == true);
	return 0;
}

