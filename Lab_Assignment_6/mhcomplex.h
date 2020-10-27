//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//27 October 2020

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
	Complex(double thereal = 0, double theimag = 0);

	//accessors
	double getreal();
	double getimag();

	//mutators
	bool setreal(double thereal);
	bool setimag(double theimag);

	//other. functions
	double modulus();
	Complex reciprocal();
	string toString();

	//DivByZeroException
	class DivByZeroException: virtual public std::exception {
	public:
		DivByZeroException();
		virtual ~DivByZeroException() throw ();
		virtual const char* what() const throw ();
	private:
		string err_msg;
	};

	Complex& operator=(const Complex &other);

	//friend operator functions declarations
	friend Complex operator+(Complex a, Complex b);
	friend Complex operator-(Complex a, Complex b);
	friend Complex operator*(Complex a, Complex b);
	friend Complex operator/(Complex a, Complex b);
	friend bool operator==(Complex a, Complex b);
	friend bool operator<(Complex a, Complex b);
	friend ostream& operator<<(ostream &o, Complex c);
};

//operator functions declarations
Complex operator+(Complex a, Complex b);
Complex operator-(Complex a, Complex b);
Complex operator*(Complex a, Complex b);
Complex operator/(Complex a, Complex b);
ostream& operator<<(ostream &o, Complex c);
bool operator<(Complex a, Complex b);
bool operator==(Complex a, Complex b);

#endif /* MHCOMPLEX_H_ */
