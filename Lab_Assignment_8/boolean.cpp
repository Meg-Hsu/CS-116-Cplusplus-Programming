//lab 8

//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//3 November 2020

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#include "boolean.h"

const int BooleanFunc::MAX_TABLE_FOR_CLASS = 65536;
const int BooleanFunc::DEFAULT_TABLE_SIZE = 16;

BooleanFunc& BooleanFunc::operator=(const BooleanFunc &other) {
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

BooleanFunc::BooleanFunc(int tableSize,
		bool evalReturnIfError) :
		truthTable(NULL), state(false), evalReturnIfError
		(evalReturnIfError) {
	//check for valid input
	if (tableSize < MAX_TABLE_FOR_CLASS && tableSize > 0) {
		this->tableSize = tableSize;
	} else {
		this->tableSize = DEFAULT_TABLE_SIZE;
	}

	truthTable = new bool[tableSize];
}

BooleanFunc::BooleanFunc(const BooleanFunc &bf) {
	tableSize = bf.tableSize;
	evalReturnIfError = bf.evalReturnIfError;
	state = bf.state;

	truthTable = new bool[tableSize];

	for (int i = 0; i < tableSize; i++)
		truthTable[i] = bf.truthTable[i];

}

BooleanFunc::~BooleanFunc() {
	if (truthTable != NULL) {
		delete[] truthTable;
		truthTable = NULL;
	}
}

bool BooleanFunc::setTruthTableUsingTrue
(int inputsThatProduceTrue[], int arraySize) {

	for (int i = 0; i < tableSize; ++i) {
		truthTable[i] = false;
	}

	for (int i = 0; i < arraySize; ++i) {
		if (inputsThatProduceTrue[i] < tableSize
				&& inputsThatProduceTrue[i] >= 0) {
			truthTable[inputsThatProduceTrue[i]] = true;
		}
	}

	return arraySize <= tableSize;
}

bool BooleanFunc::setTruthTableUsingFalse
(int inputsThatProduceFalse[], int arraySize) {

	for (int i = 0; i < tableSize; ++i) {
		truthTable[i] = true;
	}

	for (int i = 0; i < arraySize; ++i) {
		if (inputsThatProduceFalse[i] < tableSize
				&& inputsThatProduceFalse[i] >= 0) {
			truthTable[inputsThatProduceFalse[i]] = false;
		}
	}

	return arraySize <= tableSize;

}

bool BooleanFunc::eval(int input) {
	if (input >= tableSize || input < 0) {
		state = evalReturnIfError;
	} else {
		state = truthTable[input];
	}
	return state;
}

bool BooleanFunc::getState() {
	return state;
}
