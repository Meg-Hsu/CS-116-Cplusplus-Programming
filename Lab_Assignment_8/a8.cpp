//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//10 November 2020

#include <iostream>
#include "boolean.h"
#include "logic.h"
#include "sevensegment.h"
using namespace std;

int main() {
	SevenSegmentImage ssi;

	ssi.setSize(7, 9);
	ssi.turnOnCellsForSegment('a');
	ssi.display();
	cout << endl;

	ssi.turnOnCellsForSegment('b');
	ssi.display();
	cout << endl;

	ssi.turnOnCellsForSegment('c');
	ssi.display();
	cout << endl;

	ssi.turnOnCellsForSegment('d');
	ssi.display();
	cout << endl;

	ssi.clearImage();
	ssi.turnOnCellsForSegment('e');
	ssi.display();
	cout << endl;

	ssi.turnOnCellsForSegment('f');
	ssi.display();
	cout << endl;

	ssi.turnOnCellsForSegment('g');
	ssi.display();
	cout << endl;

	ssi.clearImage();
	ssi.turnOnCellsForSegment('x');
	ssi.display();
	cout << endl;

	ssi.turnOnCellsForSegment('3');
	ssi.display();
	cout << endl;

	//-------------------------------------------
	//part two test code

	SevenSegmentDisplay my7SegForCon(15, 13);

	my7SegForCon.setSize(5, 5);
	for (int j = 0; j < 16; j++) {
		my7SegForCon.eval(j);
		my7SegForCon.loadConsoleImage();
		my7SegForCon.consoleDisplay();
		cout << endl;
	}

}

//*******
//
//
//
//
//
//
//
//
//
//*******
//      *
//      *
//      *
//      *
//
//
//
//
//
//*******
//      *
//      *
//      *
//      *
//      *
//      *
//      *
//      *
//
//*******
//      *
//      *
//      *
//      *
//      *
//      *
//      *
//*******
//
//
//
//
//
//*
//*
//*
//*
//*
//
//*
//*
//*
//*
//*
//*
//*
//*
//*
//
//*
//*
//*
//*
//*******
//*
//*
//*
//*
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//*****
//*   *
//*   *
//*   *
//*****
//
//    *
//    *
//    *
//    *
//    *
//
//*****
//    *
//*****
//*
//*****
//
//*****
//    *
//*****
//    *
//*****
//
//*   *
//*   *
//*****
//    *
//    *
//
//*****
//*
//*****
//    *
//*****
//
//*****
//*
//*****
//*   *
//*****
//
//*****
//    *
//    *
//    *
//    *
//
//*****
//*   *
//*****
//*   *
//*****
//
//*****
//*   *
//*****
//    *
//    *
//
//*****
//*   *
//*****
//*   *
//*   *
//
//*
//*
//*****
//*   *
//*****
//
//*****
//*
//*
//*
//*****
//
//    *
//    *
//*****
//*   *
//*****
//
//*****
//*
//*****
//*
//*****
//
//*****
//*
//*****
//*
//*

