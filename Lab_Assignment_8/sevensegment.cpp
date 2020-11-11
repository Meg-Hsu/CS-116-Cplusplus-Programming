//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//10 November 2020

#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include "boolean.h"
#include "logic.h"
#include "sevensegment.h"
using namespace std;

const string SevenSegmentImage::DRAW_CHAR = "*";
const string SevenSegmentImage::BLANK_CHAR = " ";

SevenSegmentImage::SevenSegmentImage(int width,
		int height) :
		_width(width), _height(height) {
	data = NULL;
	if (!setSize(width, height))
		setSize(MIN_WIDTH, MIN_HEIGHT);
}

SevenSegmentImage::~SevenSegmentImage() {
	deallocateArray();
}

void SevenSegmentImage::clearImage() {

	for (int row = 0; row < _height; row++)
		memset(data[row], 0, sizeof(bool) * _width);
}

bool SevenSegmentImage::turnOnCellsForSegment
(char segment) {
	bool result = true;
	switch (segment) {
	case 'a':
		drawHorizontal(topRow);
		break;
	case 'b':
		drawVertical(rightCol, topRow, midRow);
		break;
	case 'c':
		drawVertical(rightCol, midRow, bottomRow);
		break;
	case 'd':
		drawHorizontal(bottomRow);
		break;
	case 'e':
		drawVertical(leftCol, midRow, bottomRow);
		break;
	case 'f':
		drawVertical(leftCol, topRow, midRow);
		break;
	case 'g':
		drawHorizontal(midRow);
		break;
	default:
		result = false;
	}
	return result;
}

bool SevenSegmentImage::setSize(int width,
		int height) {
	if (!validateSize(width, height)) {
		return false;
	}
	deallocateArray();

	_width = width;
	_height = height;

	topRow = 0;
	midRow = height / 2;
	bottomRow = height - 1;
	leftCol = 0;
	rightCol = width - 1;
	allocateCleanArray();
	return true;
}

void SevenSegmentImage::display() {
	for (int row = 0; row < _height; row++) {
		for (int col = 0; col < _width; col++) {
			cout << (data[row][col] ?
					DRAW_CHAR : BLANK_CHAR);
		}
		cout << "\n";
	}
}

SevenSegmentImage::SevenSegmentImage
(const SevenSegmentImage &tdi) {
	data = NULL;
	setSize(tdi.rightCol, tdi.bottomRow);
	for (int row = 0; row < tdi.bottomRow; row++)
		for (int col = 0; col < tdi.rightCol; col++)
			data[row][col] = tdi.data[row][col];
}

const SevenSegmentImage&
SevenSegmentImage::operator=(const SevenSegmentImage &rhs) {
	if (this != &rhs) {
		this->setSize(rhs.rightCol, rhs.bottomRow);
		for (int row = 0; row < rhs.bottomRow; row++)
			for (int col = 0; col < rhs.rightCol; col++)
				this->data[row][col] = rhs.data[row][col];
	}
	return *this;
}

bool SevenSegmentImage::validateSize(int width, int height) {
	return width >= MIN_WIDTH && width <= MAX_WIDTH
			&& height >= MIN_HEIGHT
			&& height <= MAX_HEIGHT;
}

void SevenSegmentImage::allocateCleanArray() {
	if (data != NULL)
		deallocateArray();

	data = new bool*[bottomRow + 1];
	for (int row = 0; row <= bottomRow; row++)
		data[row] = new bool[rightCol + 1];

	for (int row = 0; row <= bottomRow; row++)
		memset(data[row], 0, sizeof(bool) * rightCol);
}

void SevenSegmentImage::deallocateArray() {
	if (data == NULL)
		return;

	for (int row = 0; row < _height; row++)
		delete[] data[row];
	delete[] data;
	data = NULL;
}

void SevenSegmentImage::drawHorizontal(int row) {
	for (int col = 0; col <= rightCol; col++)
		data[row][col] = true;
}

void SevenSegmentImage::drawVertical(int col, int startRow, int stopRow) {
	for (int row = startRow; row <= stopRow; row++)
		data[row][col] = true;
}

SevenSegmentDisplay::SevenSegmentDisplay(int width, int height) {
	if (!setSize(width, height))
		setSize(SevenSegmentImage::MIN_WIDTH,
				SevenSegmentImage::MIN_HEIGHT);
}

bool SevenSegmentDisplay::setSize(int width, int height) {
	return theImage.setSize(width, height);
}

void SevenSegmentDisplay::loadConsoleImage() {
	theImage.clearImage();
	for (int seg = 'a'; seg <= 'g'; seg++)
		if (theDisplay.getValOfSeg(seg - 'a'))
			theImage.turnOnCellsForSegment(seg);
}

void SevenSegmentDisplay::consoleDisplay() {
	theImage.display();
}

void SevenSegmentDisplay::eval(int input) {
	theDisplay.eval(input);
}

