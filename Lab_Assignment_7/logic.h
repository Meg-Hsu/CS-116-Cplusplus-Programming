//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//3 November 2020

#ifndef LOGIC_H_
#define LOGIC_H_

#include <iostream>
#include <string>
#include <cmath>
#include "boolean.h"
using namespace std;

class MultiSegmentLogic {
protected:
	int numSegs;
	BooleanFunc *segs;

public:
	MultiSegmentLogic(int numSegs = 0);
	MultiSegmentLogic(const MultiSegmentLogic &msl);
	~MultiSegmentLogic();

	bool setNumSegs(int numSegs);
	bool setSegment(int segNum, BooleanFunc &funcForThisSeg);

	void eval(int input);

};

class SevenSegmentLogic: public MultiSegmentLogic {
public:
	SevenSegmentLogic();
	bool getValOfSeg(int seg);
	void view();

private:
	void initializeBooleanFunc();
};

#endif /* LOGIC_H_ */
