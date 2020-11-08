//lab 8

//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//3 November 2020

#include <iostream>
#include <string>
#include <cmath>
#include "boolean.h"
#include "logic.h"
using namespace std;

MultiSegmentLogic::MultiSegmentLogic(int numSegs) {
	segs = NULL;
	setNumSegs(numSegs);
}

MultiSegmentLogic::MultiSegmentLogic(const MultiSegmentLogic &msl) {
	setNumSegs(msl.numSegs);
	for (int i = 0; i < numSegs; i++)
		segs[i] = msl.segs[i];
}

MultiSegmentLogic::~MultiSegmentLogic() {
	if (segs != NULL) {
		delete[] segs;
	}
}

bool MultiSegmentLogic::setNumSegs(int numSegs) {
	if (segs != NULL) {
		delete[] segs;
		segs = NULL;
	}

	if (numSegs <= 0) {
		this->numSegs = 0;
		return false;
	} else {
		this->numSegs = numSegs;
		segs = new BooleanFunc[numSegs];
		return true;
	}
}

bool MultiSegmentLogic::setSegment(int segNum,
		BooleanFunc &funcForThisSeg) {
	if (segNum < 0 || segNum >= numSegs)
		return false;
	segs[segNum] = funcForThisSeg;
	return true;
}

void MultiSegmentLogic::eval(int input) {
	for (int i = 0; i < numSegs; i++)
		segs[i].eval(input);
}

SevenSegmentLogic::SevenSegmentLogic() :
		MultiSegmentLogic { 7 } {
	initializeBooleanFunc();
}

bool SevenSegmentLogic::getValOfSeg(int seg) {
	if (seg < 0 || seg >= 16)
		return false;
	return segs[seg].getState();
}

void SevenSegmentLogic::view() {
	for (int i = 0; i < 16; ++i) {
		eval(i);
		cout << " " << (segs[0].getState() ? "_" : " ") << endl
				<< (segs[5].getState() ? "|" : " ")
				<< (segs[6].getState() ? "_" : " ")
				<< (segs[1].getState() ? "|" : " ") << endl
				<< (segs[4].getState() ? "|" : " ")
				<< (segs[3].getState() ? "_" : " ")
				<< (segs[2].getState() ? "|" : " ") << endl << endl;
	}
}


//0 1 2 3 4 5 6 7 8 9 A b C d E F -- b and d are lowercase
//because they would look like 8 and 0 respectively

void SevenSegmentLogic::initializeBooleanFunc() {
	// Segment a
	BooleanFunc one = BooleanFunc(16, true);
	int a[4] = { 1, 4, 11, 13 };
	one.setTruthTableUsingFalse(a, 4);
	setSegment(0, one);

	BooleanFunc two = BooleanFunc(16, true);
	int b[] = { 5, 6, 11, 12, 14, 15 };
	two.setTruthTableUsingFalse(b, 6);
//		setSegment(0, two);
	setSegment(1, two);

	BooleanFunc fn = BooleanFunc(16, true);
	int c[4] = { 2, 12, 14, 15 };
	fn.setTruthTableUsingFalse(c, 4);
	setSegment(2, fn);

	int d[6] = { 1, 4, 7, 9, 10, 15 };
	fn.setTruthTableUsingFalse(d, 6);
	setSegment(3, fn);

	int e[6] = { 1, 3, 4, 5, 7, 9 };
	fn.setTruthTableUsingFalse(e, 6);
	setSegment(4, fn);

	int f[5] = { 1, 2, 3, 7, 13 };
	fn.setTruthTableUsingFalse(f, 5);
	setSegment(5, fn);

	int g[] = { 0, 1, 7, 12 };
	fn.setTruthTableUsingFalse(g, 4);
	setSegment(6, fn);

}

