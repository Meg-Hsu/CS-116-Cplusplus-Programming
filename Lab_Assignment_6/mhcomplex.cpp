//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//27 October 2020

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include "mhcomplex.h"
using namespace std;

	//constructors
	Complex::Complex(double thereal, double theimag) :
			real(thereal), imag(theimag) {
	}

	//accessors
	double Complex::getreal() {
		return real;
	}
	double Complex::getimag() {
		return imag;
	}

	//mutators
	bool Complex::setreal(double thereal) {
		thereal = real;
		return true;
	}

	bool Complex::setimag(double theimag) {
		theimag = imag;
		return true;
	}

	double Complex::modulus() {
		double length;
		length = sqrt(pow(real, 2) + pow(imag, 2));
		return length;
	}

	Complex Complex::reciprocal() {
		double d = real * real + imag * imag;
		if (d < 0.00000001) {
			throw DivByZeroException();
		}
		return Complex(real / d, -imag / d);
	}

	string Complex::toString() {
		std::ostringstream ss;
		ss << "(" << to_string(real) << ", " << to_string(imag) << ")";
		return ss.str();
	}

// DivByZeroException
Complex::DivByZeroException::DivByZeroException() {
	err_msg = "Can't divide by zero";
}


Complex::DivByZeroException::~DivByZeroException() throw () {
}


const char* Complex::DivByZeroException::what() const throw () {
	return err_msg.c_str();
}

//operators
Complex operator+(Complex a, Complex b) {
	return Complex(a.real + b.real, a.imag + b.imag);
}

Complex operator-(Complex a, Complex b) {
	return Complex(a.real - b.real, a.imag - b.imag);
}

Complex operator*(Complex a, Complex b) {
	return Complex((a.real * b.real) - (a.imag * b.imag),
			(a.real * b.imag) + (b.real * a.imag));
}

Complex operator/(Complex a, Complex b) {
	return a * b.reciprocal();
}

Complex& Complex::operator=(const Complex& other){
	real = other.real;
	imag = other.imag;
	return *this;
}

ostream& operator<<(ostream &o, Complex c) {
	o << "(" << c.real << ", " << c.imag << ")";
	return o;
}

bool operator<(Complex a, Complex b) {

	if (a.modulus() < b.modulus()) {
		return true;
	} else {
		return false;
	}
}

bool operator==(Complex a, Complex b) {
	if (fabs(a.real - b.real) < 0.00000001
			&& fabs(a.imag - b.imag) < 0.00000001) {
		return true;
	} else {
		return false;
	}
}
