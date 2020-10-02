//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//29 September 2020

#include <iostream>
#include <string>
#include "triplestring.h"
using namespace std;

int main() {
	//instantiation
	cout << "TripleStrings after instantiation:\n";

	TripleString object1, object2;
	TripleString object3("Today", "is", "Tuesday");
	TripleString object4("a", "b", "");

	cout << object1.toString() << "\n";
	cout << object2.toString() << "\n";
	cout << object3.toString() << "\n";
	cout << object4.toString() << "\n";

	//mutation
	cout << "\nTripleStrings after mutations:\n";

	// no change
	object1.setString1("");

	// single parts changed
	object2.setString2("insert joke here");
	object3.setString2("isn't");
	object4.setString3("c");

	cout << object1.toString() << "\n";
	cout << object2.toString() << "\n";
	cout << object3.toString() << "\n";
	cout << object4.toString() << "\n";

	//explicit mutator tests
	cout << "\nMutator tests:\n";

	//valid string
	if (object1.setString1("This is a valid string!")) {
		cout << "Indeed, this is a valid string!\n";
	} else {
		cout << "Oh no, this doesn't meet the length requirements.\n";
	}

	//invalid string
	if (object2.setString2(
			"This is not valid string--"
			"abcdefghijklmnopqursuvwxyz")) {
		cout << "nice!\n";
	} else {
		cout
				<< "Please try again, this doesn't"
				" meet the length requirements.\n";
	}

	//accessor calls
	cout << "\nAccessor tests:\n";
	cout << object1.getString1() << "\n";
	cout << object4.getString1() << "\n";

	return 0;
}

//Code Test Run

//TripleStrings after instantiation:
//(undefined) , (undefined) , (undefined)
//(undefined) , (undefined) , (undefined)
//Today , is , Tuesday
//a , b , (undefined)
//
//TripleStrings after mutations:
//(undefined) , (undefined) , (undefined)
//(undefined) , insert joke here , (undefined)
//Today , isn't , Tuesday
//a , b , c
//
//Mutator tests:
//Indeed, this is a valid string!
//Please try again, this doesn't meet the length requirements.
//
//Accessor tests:
//This is a valid string!
//a
