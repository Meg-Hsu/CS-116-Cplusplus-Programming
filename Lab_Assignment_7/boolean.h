/*
 * boolean.h
 *
 *  Created on: Nov 1, 2020
 *      Author: meghsu
 */

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

	BooleanFunc& operator=(const BooleanFunc& other) {
		tableSize = other.tableSize;
		if (truthTable != NULL) {
			delete[] truthTable;
		}
		truthTable = new bool[tableSize];
		for (int i = 0; i < tableSize; ++i) {
			truthTable[i] = other.truthTable[i];
		}
		return *this;
	}
	//constructors / deconstructor
	BooleanFunc(int tableSize = DEFAULT_TABLE_SIZE, bool evalReturnIfError =
			false) : truthTable(NULL), state(false), evalReturnIfError(evalReturnIfError) {
		//check for valid input
		if (tableSize < MAX_TABLE_FOR_CLASS && tableSize > 0) {
			this->tableSize = tableSize;
		} else {
			this->tableSize = DEFAULT_TABLE_SIZE;
		}

		truthTable = new bool[tableSize];
	}

	BooleanFunc(const BooleanFunc &bf) {
		tableSize = bf.tableSize;
		evalReturnIfError = bf.evalReturnIfError;
		state = bf.state;

		truthTable = new bool[tableSize];

		for (int i = 0; i < tableSize; i++)
			truthTable[i] = bf.truthTable[i];

	}

	~BooleanFunc() {
		if (truthTable != NULL) {
			delete[] truthTable;
			truthTable = NULL;
		}
	}

	//mutators
	bool setTruthTableUsingTrue(int inputsThatProduceTrue[], int arraySize) {

		for (int i = 0; i < tableSize; ++i) {
			truthTable[i] = false;
		}

		for (int i = 0; i < arraySize; ++i) {
			if (inputsThatProduceTrue[i] < tableSize && inputsThatProduceTrue[i] >= 0) {
				truthTable[inputsThatProduceTrue[i]] = true;
			}
		}

		return arraySize <= tableSize;
	}

	bool setTruthTableUsingFalse(int inputsThatProduceFalse[], int arraySize) {

		for (int i = 0; i < tableSize; ++i) {
			truthTable[i] = true;
		}

		for (int i = 0; i < arraySize; ++i) {
			if (inputsThatProduceFalse[i] < tableSize && inputsThatProduceFalse[i] >= 0) {
				truthTable[inputsThatProduceFalse[i]] = false;
			}
		}

		return arraySize <= tableSize;

	}

	bool eval(int input) {
		if (input >= tableSize || input < 0) {
			state = evalReturnIfError;
		} else {
			state = truthTable[input];
		}
		return state;
	}

	bool getState() {
		return state;
	}

	//static public members
	const static int MAX_TABLE_FOR_CLASS;
	const static int DEFAULT_TABLE_SIZE;
};

#endif /* BOOLEAN_H_ */