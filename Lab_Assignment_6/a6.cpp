//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//27 October 2020

#include <iostream>
#include "mhcomplex.h"
using namespace std;

int main() {
	Complex a(1, 2), b(3, 4), c;
	double x = 2, y = -1.7;

	cout << "Constructor Tests:\n";
	cout << "Default Constructor: " << Complex() << endl;
	cout << "One Value: " << Complex(1) << endl;
	cout << "Two Values: " << Complex(2,3) << endl;
	cout << "\n----------------------------------------\n";

	cout << "\nAddition / Subtraction Operator Tests:\n";

	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl << endl;

	cout << a << " + " << 8 << " = " << a + 8 << endl;
	cout << b << " - " << 3 << " = " << a - 3 << endl;

	cout << "\n----------------------------------------\n";

	cout << "\nMultiplication / Division Operator Tests:\n";

	cout << a << " * " << b << " = " << a * b << endl;
	try {
		cout << a << " / " << b << " = " << a / b << endl << endl;
	} catch (Complex::DivByZeroException &e) {
		cout << e.what() << endl;
	}

	cout << a << " * " << 2 << " = " << a * 2 << endl;
	try {
			cout << a << " / " << 5 << " = " << a / 5 << endl << endl;
		} catch (Complex::DivByZeroException &e) {
			cout << e.what() << endl;
		}

	cout << "\n----------------------------------------\n";

	cout << "\nDivision by Zero Operator Tests:\n";
	try {
		cout << a << " / " << 0.0 << " = " << a / 0.0 << endl;
	} catch (Complex::DivByZeroException &e) {
		cout << e.what() << endl;
	}

	try {
			cout << b << " / " << 0.0 << " = " << b / 0.0 << endl;
		} catch (Complex::DivByZeroException &e) {
			cout << e.what() << endl;
		}

	cout << "\n----------------------------------------\n";

	Complex d(3, 4), e(6, 8), f;
	cout << "\nModulus Tests:\n";
	cout << "The modulus of " << d << " is " << d.modulus() << ".\n";
	cout << "The modulus of " << e << " is " << e.modulus() << ".\n";

	cout << "\n----------------------------------------\n";

	cout << "\nAssignment (=) Tests: \n"
			"d = " << d << "\n"
			"e = " << e << "\n";
	d = e;
	cout << "d = e --> d = " << d << "\n";

	Complex g(3, 4), h(5, 6), i;
	cout << "\ng = " << g << "\n"
			"h = " << h << "\n";
	g = h;
	cout << "g = h --> g = " << g << "\n";

	cout << "\n----------------------------------------\n";

	Complex j(3, 4), k(5, 6), l;
	cout << "\nComparison (<) Tests: \n"
			"Modululs of j = " << g.modulus() << "\n"
			"Modulus of k = " << h.modulus() << "\n";
	cout << "j < k " << (j < k ? "true" : "false") << endl;

	Complex m(9, 10), n(7, 8), o;
	cout << "\nModululs of m = " << m.modulus() << "\n"
			"Modulus of n = " << n.modulus() << "\n";
	cout << "m < n " << (m < n ? "true" : "false") << endl;

	cout << "\n----------------------------------------\n";

//	Complex j(3, 4), k(5, 6), l;
	cout << "\nEquality (==) Tests:\n"
			"m = " << m << "\n"
			"n = " << n << "\n";
	cout << "m == n " << (m == n ? "true" : "false") << endl;

	Complex p(3, 4), q(3, 4), r;
	cout << "\np = " << p << "\n"
			"q = " << q << "\n";
	cout << "p == q " << (p == q ? "true" : "false") << endl;

	return 0;
}

//Test Code:

//Constructor Tests:
//Default Constructor: (0, 0)
//One Value: (1, 0)
//Two Values: (2, 3)
//
//----------------------------------------
//
//Addition / Subtraction Operator Tests:
//(1, 2) + (3, 4) = (4, 6)
//(1, 2) - (3, 4) = (-2, -2)
//
//(1, 2) + 8 = (9, 2)
//(3, 4) - 3 = (-2, 2)
//
//----------------------------------------
//
//Multiplication / Division Operator Tests:
//(1, 2) * (3, 4) = (-5, 10)
//(1, 2) / (3, 4) = (0.44, 0.08)
//
//(1, 2) * 2 = (2, 4)
//(1, 2) / 5 = (0.2, 0.4)
//
//
//----------------------------------------
//
//Division by Zero Operator Tests:
//(1, 2) / 0 = Can't divide by zero
//(3, 4) / 0 = Can't divide by zero
//
//----------------------------------------
//
//Modulus Tests:
//The modulus of (3, 4) is 5.
//The modulus of (6, 8) is 10.
//
//----------------------------------------
//
//Assignment (=) Tests:
//d = (3, 4)
//e = (6, 8)
//d = e --> d = (6, 8)
//
//g = (3, 4)
//h = (5, 6)
//g = h --> g = (5, 6)
//
//----------------------------------------
//
//Comparison (<) Tests:
//Modululs of j = 7.81025
//Modulus of k = 7.81025
//j < k true
//
//Modululs of m = 13.4536
//Modulus of n = 10.6301
//m < n false
//
//----------------------------------------
//
//Equality (==) Tests:
//m = (9, 10)
//n = (7, 8)
//m == n false
//
//p = (3, 4)
//q = (3, 4)
//p == q true



