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
	ssi.turnOnCellsForSegment('b');
	ssi.display();
	ssi.turnOnCellsForSegment('c');
	ssi.display();
	ssi.turnOnCellsForSegment('d');
	ssi.display();

	ssi.clearImage();
	ssi.turnOnCellsForSegment('e');
	ssi.display();
	ssi.turnOnCellsForSegment('f');
	ssi.display();
	ssi.turnOnCellsForSegment('g');
	ssi.display();

	ssi.clearImage();
	ssi.turnOnCellsForSegment('x');
	ssi.display();
	ssi.turnOnCellsForSegment( '3' );
	   ssi.display();

	   //-------------------------------------------
	   //part two test code

//	   SevenSegmentDisplay my7SegForCon( 15, 13 );
//
//	   my7SegForCon.setSize( 5, 5 );
//	   for ( int j = 0; j < 16; j++ )
//	   {
//	      my7SegForCon.eval( j );
//	      my7SegForCon.loadConsoleImage();
//	      my7SegForCon.consoleDisplay();
//	   }


}
