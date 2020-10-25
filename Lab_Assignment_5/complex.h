//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//20 October 2020

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <sstream>
#include <ctime>
#include <stdlib.h>
#include "rsa_enc_support_classes.h"
using namespace std;

class InternetUser {
public:
	InternetUser();
	InternetUser(string theName, string theIp);
	string toString();

	bool isValid(string name, long minimum, long maximum);

	bool setName(string thename);
	bool setIp(string theip);

	static const long ERROR_FLAG_NUM = 0;

protected:
	string name;
	string ip;

	static const long MIN_NAME_LENGTH = 2;
	static const long MAX_NAME_LENGTH = 50;
	static const long MIN_IP_LENGTH = 7;
	static const long MAX_IP_LENGTH = 15;
	static const string DEFAULT_NAME;
	static const string DEFAULT_IP;
	static const string BAD_NAME;
	static const string BAD_IP;

//	static bool isValid(string name, long minimum, long maximum);

};

class Communicator: public InternetUser {
public:
	bool setprimes(long, long);

	Communicator();

	Communicator(long firstPrime, long secondPrime);
	Communicator(string name, string ip);

	Communicator(string name, string ip, long firstPrime, long secondPrime);

	string toString();

	IntPair getpublicKey();


private:
	IntPair publicKey;
	IntPair privateKey;

	long firstPrime;
	long secondPrime;
	long n, phi, e, d;

	bool computeBothEncrKeys();
	static const int MAX_TRIES = 10;
};

#endif /* COMPLEX_H_ */
