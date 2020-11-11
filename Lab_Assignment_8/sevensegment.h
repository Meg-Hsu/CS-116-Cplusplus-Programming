//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//10 November 2020

#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include "boolean.h"
#include "logic.h"
using namespace std;

class SevenSegmentImage {
public:
	static const int MIN_HEIGHT = 5;
	static const int MIN_WIDTH = 5;
	static const int MAX_HEIGHT = 65;
	static const int MAX_WIDTH = 41;
	static const string DRAW_CHAR;
	static const string BLANK_CHAR;

private:
	bool **data;
	int topRow, midRow, bottomRow, leftCol, rightCol;

public:

	SevenSegmentImage(int width = MIN_WIDTH,
			int height = MIN_HEIGHT);

	~SevenSegmentImage();

	void clearImage();
	bool turnOnCellsForSegment(char segment);
	bool setSize(int width, int height);
	void display();

	SevenSegmentImage(const SevenSegmentImage &tdi);
	const SevenSegmentImage& operator=
			(const SevenSegmentImage &rhs);

private:
	int _width, _height;
	static bool validateSize(int width, int height);

	void allocateCleanArray();
	void deallocateArray();
	void drawHorizontal(int row);
	void drawVertical(int col, int startRow,
			int stopRow);

};

class SevenSegmentDisplay {
private:
	SevenSegmentImage theImage;
	SevenSegmentLogic theDisplay;

public:
	SevenSegmentDisplay(int width, int height);

	bool setSize(int width, int height);
	void loadConsoleImage();
	void consoleDisplay();
	void eval(int input);
};

#endif
