#include <iostream>
#include "mhcomplex.h"

using namespace std;

int main() {
	Complex a(1, 2), b(3, 4), c;
	double x = 2, y = -1.7;

	cout << "Addition / Subtraction Operator Tests:\n";

	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;

	cout << "\nMultiplication / Division Operator Tests:\n";

	cout << a << " * " << b << " = " << a * b << endl;
	try {
		cout << a << " / " << b << " = " << a / b << endl;
	} catch (Complex::DivByZeroException &e) {
		cout << e.what() << endl;
	}

	cout << "\nDivision by Zero Operator Test:\n";
	try {
		cout << a << " / " << 0.0 << " = " << a / 0.0 << endl;
	} catch (Complex::DivByZeroException &e) {
		cout << e.what() << endl;
	}

	Complex d(3, 4), e(5, 6), f;
	cout << "\nModulus Test:\n";
	cout << "The modulus of " << d << " is " << d.modulus() << ".\n";

	cout << "\nAssignment (=): \n"
			"d = " << d << "\n"
			"e = " << e << "\n";
	d = e;
	cout << "d = e --> d = " << d << "\n";

	Complex g(3, 4), h(5, 6), i;
	cout << "\nComparison (<): \n"
			"Modululs of g = " << g.modulus() << "\n"
			"Modulus of h = " << h.modulus() << "\n";
	cout << "g < h " << (g < h ? "true" : "false") << endl;

	Complex j(3, 4), k(5, 6), l;
	cout << "\nEquality (==):\n"
			"j = " << j << "\n"
			"k = " << k << "\n";
	cout << "j == k " << (j == k ? "true" : "false") << endl;

	Complex m(3, 4), n(3, 4), o;
	cout << "\nm = " << m << "\n"
			"n = " << n << "\n";
	cout << "m == n " << (m == n ? "true" : "false") << endl;


//== equality
	return 0;
}

//TODO
