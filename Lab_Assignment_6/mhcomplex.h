/*
 * mhcomplex.h
 *
 *  Created on: Oct 24, 2020
 *      Author: meghsu
 */

#ifndef MHCOMPLEX_H_
#define MHCOMPLEX_H_

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
using namespace std;

class Complex {

private:
	double real;
	double imag;

public:
	//constructor
	Complex(double thereal = 0, double theimag = 0) :
			real(thereal), imag(theimag) {
	}

	//accessors
	double getreal() {
		return real;
	}
	double getimag() {
		return imag;
	}

	//mutators
	bool setreal(double thereal) {
		thereal = real;
		return true;
	}

	bool setimag(double theimag) {
		theimag = imag;
		return true;
	}

	double modulus() {
		double length;
		length = sqrt(pow(real, 2) + pow(imag, 2));
		return length;
	}

	Complex reciprocal() {
		double d = real * real + imag * imag;
		if (d < 0.00000001) {
			throw DivByZeroException();
		}
		return Complex(real / d, -imag / d);
	}

	string toString() {
		std::ostringstream ss;
		ss << "(" << to_string(real) << ", " << to_string(imag) << ")";
		return ss.str();
	}

	class DivByZeroException: virtual public std::exception {
	public:
		DivByZeroException() {
			err_msg = "Can't divide by zero";
		}
		virtual ~DivByZeroException() throw () {
		}
		virtual const char* what() const throw () {
			return err_msg.c_str();
		}
	private:
		string err_msg;
	};

	friend Complex operator+(Complex a, Complex b);
	friend Complex operator-(Complex a, Complex b);
	friend Complex operator*(Complex a, Complex b);
	friend Complex operator/(Complex a, Complex b);
	Complex& operator=(const Complex& other);
	friend bool operator==(Complex a, Complex b);
	friend bool operator<(Complex a, Complex b);

	friend ostream& operator<<(ostream &o, Complex c);
};

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

#endif /* MHCOMPLEX_H_ */
