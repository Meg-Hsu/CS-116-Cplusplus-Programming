#include "triple.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

wstring validlname() {
//input is a string, has to be from 2-15 characters
//verify that the input is all letters and not numbers/combo of other things*
	while (true) {
		wstring lname;
		double size;
		wcout
				<< "\nPlease enter your last name (between 2 and 15 characters): ";
		wcin >> lname;
		size = lname.size();
		if (size < 2 || size > 15) {
			cout
					<< "The name entered is not between 2 and 15 characters. Please try again.";
		} else {
			return lname;
		}
	}
}

int validid() {
	while (true) {
		int id;
		double size;
		cout
				<< "\nPlease enter your student ID (at least 6 characters): ";
		cin >> id;
		size = id > 0 ? (int) log10((double) id) + 1 : 1;



		if (size < 6) {
			cout << "The ID entered is less than 6 numbers. Please try again.";
		} else {

			return id;
		}
	}
}

int validnumbertriple(string method) {
//takes the number entered into the program and checks if its positive. then multiplies by 3
	while (true) {
		int input;
		cout
				<< "\nPlease enter a positive numerical value you would like to have tripled" << method << ": ";
		cin >> input;
		if (input < 0) {
			cout << input << " isn't a valid input, please try again.\n";
		} else {
			return input;
		}
	}
}

int tripleByValue(int num) {
	//passes a copy of count by value, triples the copy and returns the new value
	return num * 3;
}

void tripleByReference(int &num) {
	//passes count by reference via a reference parameter and triples the original value of count through its alias (i.e., the reference parameter).
	num = num * 3;
	cout << "The number tripled by reference is " << num << ".\n\n";
}

void intro() {
	cout
			<< "This program collects the following information:\n"
					"- Last name (between 2 and 15 characters)\n"
					"- Student ID (6 numbers, can't lead with 0)\n"
					"- A positive numerical value to be tripled through various (value and reference) means\n";
}

bool runagain() {
	cout << "\nWould you like to run this program again? (y/n) ";
	bool ans;
	string yesorno;
	cin >> yesorno;
	if (yesorno == "Y" or yesorno == "y") {
		ans = true;
	}
	if (yesorno == "N" or yesorno == "n") {
		ans = false;
	}
	return ans;
}
