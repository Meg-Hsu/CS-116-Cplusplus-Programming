//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//22 September 2020


#include <iostream>
#include <string>
#include <algorithm>
#include "strpkg.h"
using namespace std;

int main() {

	intro();
	char ch;
	//lowerch and upperch sets limits on how many characters is accepted in validchar
	int lowerch = 0;
	int upperch = 1;
	ch = validchar(lowerch, upperch);

	string phrase;
	//lowerph and upperph sets limits on how many characters is accepted in validphrase
	int lowerph = 4;
	int upperph = 500;
	phrase = validphrase(lowerph, upperph);

	int numchar;
	//countKey first to count number of instances of character before they're removed
	numchar = countKey(phrase, ch);

	phrase = maskCharacter (phrase, ch);
	cout << "\n\n\nThe phrase with '" << ch << "' masked is: " << phrase << "\n";

	phrase = removeCharacter(phrase, ch);
	cout << "\nThe phrase with '" << ch << "' removed is: " << phrase << "\n";

	cout << "\nThe number of times '" << ch << "' was used in the string entered: " << numchar << "\n";

}


//Example Code 1
//
//This program takes the input of a single character as well as a string and does the following:
//- replaces all instance of the character selected in the string with an asterisk (*)
//- removes all instances of the character selected in the string
//- counts the number of times the selected character appears in the string (case sensitive)
//
//Please enter the character (1) you would like to replace/delete in a string: aaaa
//The name entered is not 1 character. Please try again.
//
//Please enter the character (1) you would like to replace/delete in a string: a
//
//Please enter the string you would like to use in this program (between 4 and 500 characters): asd
//The name entered is not between 4 and 500 characters. Please try again.
//
//Please enter the string you would like to use in this program (between 4 and 500 characters): asdf lkasdhjf s;ldkfjlasdf
//
//
//
//The phrase with 'a' masked is: *sdf lk*sdhjf s;ldkfjl*sdf
//
//The phrase with 'a' removed is: sdf lksdhjf s;ldkfjlsdf
//
//The number of times 'a' was used in the string entered: 3



//Example Code 2

//This program takes the input of a single character as well as a string and does the following:
//- replaces all instance of the character selected in the string with an asterisk (*)
//- removes all instances of the character selected in the string
//- counts the number of times the selected character appears in the string (case sensitive)
//
//Please enter the character (1) you would like to replace/delete in a string: o
//
//Please enter the string you would like to use in this program (between 4 and 500 characters): my body is NOT a temple it’s a STORAGE UNIT for my REGRETS
//
//
//
//The phrase with 'o' masked is: my b*dy is NOT a temple it’s a STORAGE UNIT f*r my REGRETS
//
//The phrase with 'o' removed is: my bdy is NOT a temple it’s a STORAGE UNIT fr my REGRETS
//
//The number of times 'o' was used in the string entered: 2



//Example Code 3

//This program takes the input of a single character as well as a string and does the following:
//- replaces all instance of the character selected in the string with an asterisk (*)
//- removes all instances of the character selected in the string
//- counts the number of times the selected character appears in the string (case sensitive)
//
//Please enter the character (1) you would like to replace/delete in a string: i
//
//Please enter the string you would like to use in this program (between 4 and 500 characters): imagine your card declines at therapy and they bring your dad in
//
//
//
//The phrase with 'i' masked is: *mag*ne your card decl*nes at therapy and they br*ng your dad *n
//
//The phrase with 'i' removed is: magne your card declnes at therapy and they brng your dad n
//
//The number of times 'i' was used in the string entered: 5
//
