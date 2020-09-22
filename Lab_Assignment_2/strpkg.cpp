//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//22 September 2020

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//takes in a string, makes sure it's only one character. tuens it into a char and returns that
char validchar(int lower, int upper) {
	while (true) {
		string ch;
		double size;
		cout
				<< "\nPlease enter the character (1) you would like to replace/delete in a string: ";
		cin >> ch;
		//cin.ignore to clear buffer for getline in the validphrase function
		cin.ignore(numeric_limits<streamsize>::max());
		size = ch.size();
		if (size < lower || size > upper) {
			cout << "The name entered is not " << upper
					<< " character"
					". Please try again.\n";
		} else {
			char chr = ch[0];
			return chr;
		}
	}
}

//takes in a string within the limits specified, returns that string
string validphrase(int lower, int upper) {
	while (true) {
		string phrase;
		double size;
		cout
				<< "\nPlease enter the string you would like to use in this program (between "
				<< lower << " and " << upper << " characters): ";
		//getline so that user can input string with spaces
		getline(cin, phrase);
		size = phrase.size();
		if (size < lower || size > upper) {
			cout << "The name entered is not between " << lower << " and "
					<< upper << " characters. Please try again.\n";
		} else {
			return phrase;
		}
	}
}

//replaces all instances of the character specified with an asterisk
string maskCharacter(string theString, char keyCharacter) {
	replace(theString.begin(), theString.end(), keyCharacter, '*');
	return theString;
}

//removes all instances of the character specified
string removeCharacter(string theString, char keyCharacter) {
	  string::iterator pend = remove(theString.begin(), theString.end(), '*');
	  theString.erase(pend, theString.end());

	return theString;
}

//counts the number of times the specified character is used in the string entered
int countKey(string theString, char keyCharacter) {
	int count = 0;
	for (int i = 0; i < theString.size(); i++)
		if (theString[i] == keyCharacter)
			count++;
	return count;
}

//prints menu/summary of program
void intro() {
	cout
			<< "This program takes the input of a single character as well as a string and does the following:\n"
					"- replaces all instance of the character selected in the string with an asterisk (*)\n"
					"- removes all instances of the character selected in the string\n"
					"- counts the number of times the selected character appears in the string (case sensitive)\n";
}
