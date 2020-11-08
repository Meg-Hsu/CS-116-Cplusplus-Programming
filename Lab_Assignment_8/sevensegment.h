/*
 * sevensegment.h
 *
 *  Created on: Nov 8, 2020
 *      Author: meghsu
 */

#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include <iostream>
#include <string>
#include <cmath>
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

	//constructor
	SevenSegmentImage(int width = MIN_WIDTH, int height = MIN_HEIGHT) {
		data = NULL;
		if (!setSize(width, height))
			setSize(MIN_WIDTH, MIN_HEIGHT);
	}

	//destructor
	~SevenSegmentImage() {
		deallocateArray();
	}

	void clearImage() {
		for (int row = 0; row < bottomRow; row++)
			for (int col = 0; col < rightCol; col++)
				data[row][col] = false;
	}

	bool turnOnCellsForSegment(char segment) {
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
			return false;
		}
		return true;
	}

	bool setSize(int width, int height) {
		if (!validateSize(width, height))
			return false;
		deallocateArray();
		topRow = 1;
		midRow = (height + 1) / 2;
		bottomRow = height;
		leftCol = 1;
		rightCol = width;
		allocateCleanArray();
		return true;
	}

	void display() {
		for (int row = 0; row < bottomRow; row++) {
			cout << "\n";
			for (int col = 0; col < rightCol; col++)
				cout << (data[row][col] ? DRAW_CHAR : BLANK_CHAR);
		}
	}

	// deep copy stuff
	SevenSegmentImage(const SevenSegmentImage &tdi) {
		data = NULL;
		setSize(tdi.rightCol, tdi.bottomRow);
		for (int row = 0; row < tdi.bottomRow; row++)
			for (int col = 0; col < tdi.rightCol; col++)
				data[row][col] = tdi.data[row][col];
	}

	const SevenSegmentImage& operator=(const SevenSegmentImage &rhs) {
		if (this != &rhs) {
			this->setSize(rhs.rightCol, rhs.bottomRow);
			for (int row = 0; row < rhs.bottomRow; row++)
				for (int col = 0; col < rhs.rightCol; col++)
					this->data[row][col] = rhs.data[row][col];
		}
		return *this;
	}

private:
	static bool validateSize(int width, int height){
	    if(width < MIN_WIDTH || width > MAX_WIDTH ||
	        height < MIN_HEIGHT || height > MAX_HEIGHT || height % 2 == 0)
	        return false;
	    return true;
	}

	void allocateCleanArray(){
	    if (data != NULL)
	        deallocateArray();

	    data = new bool*[bottomRow];
	    for (int row = 0; row < bottomRow; row++)
	       data[row] = new bool[rightCol];

	    for (int row = 0; row < bottomRow; row++)
	        for (int col = 0; col < rightCol; col++)
	            data[row][col] = false;
	}

	void deallocateArray(){
	    if (data == NULL)
	        return;

	    for (int row = 0; row < bottomRow; row++)
	        delete[] data[row];
	    delete[] data;
	    data = NULL;
	}

	// helpers - not required, but used by instructor
	void drawHorizontal(int row){
	    for(int col = 0; col < rightCol; col++)
	        data[row - 1][col] = true;
	}

	void drawVertical(int col, int startRow, int stopRow){
	    for(int row = startRow; row <= stopRow; row++)
	        data[row - 1][col - 1] = true;
	}

};

const string SevenSegmentImage::DRAW_CHAR = "*";
const string SevenSegmentImage::BLANK_CHAR = " ";



class SevenSegmentDisplay
{
private:
   SevenSegmentImage theImage;
   SevenSegmentLogic theDisplay;

public:
   SevenSegmentDisplay(
      int width = SevenSegmentImage::MIN_WIDTH,
      int height = SevenSegmentImage::MIN_HEIGHT
      );
   bool setSize( int width, int height );
   void loadConsoleImage();
   void consoleDisplay();
   void eval( int input );
};


#endif /* SEVENSEGMENT_H_ */
