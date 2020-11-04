//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//3 November 2020

#ifndef BOOLEAN_H_
#define BOOLEAN_H_

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class BooleanFunc

{
private:
	int tableSize;
	bool *truthTable;
	bool evalReturnIfError;
	bool state;

public:

	BooleanFunc& operator=(const BooleanFunc &other);
	BooleanFunc(int tableSize = DEFAULT_TABLE_SIZE,
			bool evalReturnIfError = false);
	BooleanFunc(const BooleanFunc &bf);
	~BooleanFunc();

	//mutators
	bool setTruthTableUsingTrue(int inputsThatProduceTrue[],
			int arraySize);
	bool setTruthTableUsingFalse(int inputsThatProduceFalse[],
			int arraySize);

	bool eval(int input);
	bool getState();

	//static public members
	const static int MAX_TABLE_FOR_CLASS;
	const static int DEFAULT_TABLE_SIZE;
};

#endif /* BOOLEAN_H_ */
