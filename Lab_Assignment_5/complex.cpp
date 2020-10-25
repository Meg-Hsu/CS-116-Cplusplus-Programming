//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//20 October 2020

#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <sstream>
#include <ctime>
#include <stdlib.h>
#include "complex.h"
#include "rsa_enc_support_classes.h"
using namespace std;



InternetUser::InternetUser() :
		name(DEFAULT_NAME), ip(DEFAULT_IP) {}
InternetUser::InternetUser(string theName, string theIp) {
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
	string InternetUser::toString() {
		return "\nName: " + name + "\nIP Addr: " + ip + "\n";
	}

	string InternetUser::getName() {
		return name;
	}
	string InternetUser::getIp() {
		return ip;
	}

	bool InternetUser::setName(string thename) {
		if (isValid(thename, MIN_NAME_LENGTH, MAX_NAME_LENGTH)) {
			name = thename;
			return true;
		} else {
			return false;
		}
	}
	bool InternetUser::setIp(string theip) {
		if (isValid(theip, MIN_IP_LENGTH, MAX_IP_LENGTH)) {
			ip = theip;
			return true;
		} else {
			return false;
		}
	}

bool InternetUser::isValid(string name, long minimum, long maximum) {
	return name.length() >= minimum && name.length() <= maximum;
}

const string InternetUser::DEFAULT_NAME = "(undefined)";
const string InternetUser::DEFAULT_IP = "0.0.0.0";
const string InternetUser::BAD_NAME = "bad";
const string InternetUser::BAD_IP = "0.0.0.0";



Communicator::Communicator() :
			firstPrime(ERROR_FLAG_NUM), secondPrime(ERROR_FLAG_NUM), e(
					ERROR_FLAG_NUM), phi(ERROR_FLAG_NUM), n(ERROR_FLAG_NUM), d(
					ERROR_FLAG_NUM) {
	}

Communicator::Communicator(long firstPrime, long secondPrime) {
		setprimes(firstPrime, secondPrime);
	}

Communicator::Communicator(string name, string ip) :
			firstPrime(ERROR_FLAG_NUM), secondPrime(ERROR_FLAG_NUM), e(
					ERROR_FLAG_NUM), phi(ERROR_FLAG_NUM), n(ERROR_FLAG_NUM), d(
					ERROR_FLAG_NUM) {

		InternetUser(name, ip);
	}

Communicator::Communicator(string name, string ip, long firstPrime, long secondPrime) :
			Communicator(firstPrime, secondPrime) {
		InternetUser::setName(name);
		InternetUser::setIp(ip);
	}

	IntPair Communicator::getpublicKey() {
		return publicKey;
	}

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
