//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//22 September 2020

#ifndef STRPKG_H_
#define STRPKG_H_

#include <iostream>
#include <string>
using namespace std;

char validchar(int lower, int upper);
string validphrase(int lower, int upper);
string maskCharacter (string theString, char keyCharacter);
string removeCharacter(string theString, char keyCharacter);
int countKey(string theString, char keyCharacter);
void intro();

#endif /* STRPKG_H_ */
