#include <iostream>
#include "boolean.h"
#include "logic.h"

using namespace std;

int main() {

//	BooleanFunc segA, segB( 13 ), segC( 100, true );
//
//	   int evenFunc[] = { 0, 2, 4, 6, 8, 10, 12, 14 }, inputX;
//	   short sizeEvenFunc = sizeof(evenFunc) / sizeof(evenFunc[0]);
//
//	   int greater9Func[] = { 10, 11, 12, 13, 14, 15 };
//	   short sizeGreater9Func = sizeof(greater9Func) / sizeof(greater9Func[0]);
//
//	   int greater3Func[] = { 0, 1, 2, 3 };
//	   short sizeGreater3Func = sizeof(greater3Func) / sizeof(greater3Func[0]);
//
//	   segA.setTruthTableUsingTrue( evenFunc, sizeEvenFunc );
//	   segB.setTruthTableUsingTrue( greater9Func, sizeGreater9Func );
//	   segC.setTruthTableUsingFalse( greater3Func, sizeGreater3Func );
//
//	   // testing class BooleanFunc
//	   cout << "before eval()\n";
//	   cout
//	      << "\n  A(x) = "
//	      << segA.getState()
//	      << "\n  B(x) = "
//	      << segB.getState()
//	      << "\n  C(x) = "
//	      << segC.getState()
//	      << endl << endl;
//	   cout << "looping with eval()\n";
//	   for ( inputX = 0; inputX < 10; inputX++ )
//	   {
//	      segA.eval( inputX );
//	      segB.eval( inputX );
//	      segC.eval( inputX );
//	      cout
//	         << "Input: " << inputX
//	         << "\n  A(x) = "
//	         << segA.getState()
//	         << "\n  B(x) = "
//	         << segB.getState()
//	         << "\n  C(x) = "
//	         << segC.getState()
//	         << endl << endl;
//	   }
//	   segA.eval( inputX );

//------------------------------------------------------------------------------------------------------------


	   int inputX, k;
	   SevenSegmentLogic my7Seg;
//	   SevenSegmentLogic myCopy( my7Seg );

	   my7Seg.view();

//	   for ( inputX = 0; inputX < 16; inputX++ )
//	   {
//	      myCopy.eval( inputX );
//	      cout << "\n| ";
//	      for ( k = 0; k < 7; k++ )
//	         cout << myCopy.getValOfSeg( k ) << " | ";
//	      cout << endl;
//	   }

	return 0;
}
