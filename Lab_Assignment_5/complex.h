/*
 * complex.h
 *
 *  Created on: Oct 20, 2020
 *      Author: meghsu
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

/*------------------------------------------------------------------------
 Two classes used by lab 5 RSA assignment. Do not modify these defintions.
 Place the prototypes and definitions into your final submission,
 with each element appearing in the correct place among the other protoypes,
 defintions, and main().
 ----------------------------------------------------------------------- */

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
	InternetUser() :
			name(DEFAULT_NAME), ip(DEFAULT_IP) {
	}
	InternetUser(string theName, string theIp) {
		if (isValid(theName, MIN_NAME_LENGTH, MAX_NAME_LENGTH)) {
			name = theName;
		} else {
			name = BAD_NAME;
		}

		if (isValid(theIp, MIN_IP_LENGTH, MAX_IP_LENGTH)) {
			ip = theIp;
		} else {
			ip = BAD_IP;
		}
	}
	string toString() {
		return "\nName: " + name + "\nIP Addr: " + ip + "\n";
	}

	string getName() {
		return name;
	}
	string getIp() {
		return ip;
	}

	bool isValid(string name, long minimum, long maximum);

	bool setName(string thename) {
		if (isValid(thename, MIN_NAME_LENGTH, MAX_NAME_LENGTH)) {
			name = thename;
			return true;
		} else {
			return false;
		}
	}
	bool setIp(string theip) {
		if (isValid(theip, MIN_IP_LENGTH, MAX_IP_LENGTH)) {
			ip = theip;
			return true;
		} else {
			return false;
		}
	}

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

bool InternetUser::isValid(string name, long minimum, long maximum) {
	return name.length() >= minimum && name.length() <= maximum;
}

const string InternetUser::DEFAULT_NAME = "(undefined)";
const string InternetUser::DEFAULT_IP = "0.0.0.0";
const string InternetUser::BAD_NAME = "bad";
const string InternetUser::BAD_IP = "0.0.0.0";

class Communicator: public InternetUser {
public:
	bool setprimes(long, long);

	Communicator() :
			firstPrime(ERROR_FLAG_NUM), secondPrime(ERROR_FLAG_NUM), e(
					ERROR_FLAG_NUM), phi(ERROR_FLAG_NUM), n(ERROR_FLAG_NUM), d(
					ERROR_FLAG_NUM) {
	}

	Communicator(long firstPrime, long secondPrime) {
		setprimes(firstPrime, secondPrime);
	}

	Communicator(string name, string ip) :
			firstPrime(ERROR_FLAG_NUM), secondPrime(ERROR_FLAG_NUM), e(
					ERROR_FLAG_NUM), phi(ERROR_FLAG_NUM), n(ERROR_FLAG_NUM), d(
					ERROR_FLAG_NUM) {

		InternetUser(name, ip);
	}

	Communicator(string name, string ip, long firstPrime, long secondPrime) :
			Communicator(firstPrime, secondPrime) {
		InternetUser::setName(name);
		InternetUser::setIp(ip);
	}
	;

	string toString();

	IntPair getpublicKey() {
		return publicKey;
	}


private:
	IntPair publicKey;
	IntPair privateKey;

	long firstPrime;
	long secondPrime;
	long n, phi, e, d;

	bool computeBothEncrKeys();

	static const int MAX_TRIES = 10; // TODO verify this is correct
};

string Communicator::toString() {
	return InternetUser::toString() + "\n" + "(p, q)  n, phi, e, d: ("
			+ to_string(firstPrime) + ", " + to_string(secondPrime) + ")   "
			+ to_string(n) + ", " + to_string(phi) + ",   " + to_string(e)
			+ ", " + to_string(d) + "\n" + "public key("
			+ to_string(publicKey.firstInt) + ", "
			+ to_string(publicKey.secondInt) + ")\n" + "private key("
			+ to_string(privateKey.firstInt) + ", "
			+ to_string(privateKey.secondInt) + ")";

}

bool Communicator::computeBothEncrKeys() {
	long p = firstPrime;
	long q = secondPrime;
	n = p * q;
	phi = (p - 1) * (q - 1);
	int numOfTries = 0;
	bool gotGoodPrime = false;

	while (numOfTries < MAX_TRIES && !gotGoodPrime) {
		numOfTries++;
		e = EncryptionSupport::getSmallRandomPrime();
		if (e >= phi)
			continue;
		if (phi % e == 0)
			continue;
		gotGoodPrime = true;
	}

	if (!gotGoodPrime)
		return false;

	d = EncryptionSupport::inverseOfAModM(e, n);

	publicKey.firstInt = e;
	publicKey.secondInt = n;

	privateKey.firstInt = d;
	privateKey.secondInt = n;

	//accessor - private public
	//mutate - first second prime (one mutator)

	return true;
}

bool Communicator::setprimes(long firstPrime, long secondPrime) {
		bool result = true;
		if (EncryptionSupport::isPrime(firstPrime)) {
			this->firstPrime = firstPrime;
		} else {
			firstPrime = ERROR_FLAG_NUM;
			result = false;
		}
		if (EncryptionSupport::isPrime(secondPrime)) {
			this->secondPrime = secondPrime;
		} else {
			secondPrime = ERROR_FLAG_NUM;
			result = false;
		}

		if (!computeBothEncrKeys()) {
			firstPrime = ERROR_FLAG_NUM;
			secondPrime = ERROR_FLAG_NUM;
			e = ERROR_FLAG_NUM;
			phi = ERROR_FLAG_NUM;
			n = ERROR_FLAG_NUM;
			d = ERROR_FLAG_NUM;
		} else {
			result = false;
		}
		return result;
	}
#endif /* COMPLEX_H_ */
