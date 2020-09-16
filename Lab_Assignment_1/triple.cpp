#include "triple.h"
#include <iostream>
#include <string>
using namespace std;

//This function uses wsting because it uses .size() to count the number of characters in the string so that the last name can be within the 2-15 character parameter.
wstring validlname() {
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

//This function makes sure that the ID entered in is at least six numbers long.
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

//This function takes user input and makes sure that the number entered in is a positive number before sending it back to main
int validnumbertriple(string method) {
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

//This function changes the actual value of the number when entered in and sends that back to main
int tripleByValue(int num) {
	return num * 3;
}

//This function does the calculation on a reference parameter, which is why output is called through this function and not in main like the rest of the information used in the program.
void tripleByReference(int &num) {
	num = num * 3;
	cout << "The number tripled by reference is " << num << ".\n\n";
}

//This function just outputs a menu which serves as an overview of the program.
void intro() {
	cout
			<< "This program collects the following information:\n"
					"- Last name (between 2 and 15 characters)\n"
					"- Student ID (6 numbers, can't lead with 0)\n"
					"- A positive numerical value to be tripled through various (value and reference) means\n";
}

//This function is used in the program to prompt the user if they would like to use the program again.
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
