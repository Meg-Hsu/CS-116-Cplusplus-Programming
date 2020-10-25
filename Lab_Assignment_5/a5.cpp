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
#include "complex.h"
using namespace std;


int main(){
    InternetUser user1, user2("dns", "75.75.75.75"), user3("a", "a");
    Communicator c1;

    cout << "Derived Class Constructor Testing ----------------------------------------\n";

    cout << c1.toString() << endl;
    cout << "\n--------------------\n";

    Communicator c2("meg hsu", "1.2.3.4", EncryptionSupport::getMedSizedRandomPrime(), EncryptionSupport::getMedSizedRandomPrime());
    cout << c2.toString() << endl;

    cout << "\nDerived and Base Class Mutator Testing ----------------------------------------\n";

    Communicator c3("john doe", "5.6.7.8", EncryptionSupport::getMedSizedRandomPrime(), EncryptionSupport::getMedSizedRandomPrime());
    cout << c3.toString() << endl;

    c3.setprimes(17, 3);
    cout << c3.toString() << endl;
    cout << "\n--------------------\n";


    Communicator c4("jane doe", "9.10.11.12", EncryptionSupport::getMedSizedRandomPrime(), EncryptionSupport::getMedSizedRandomPrime());
    cout << c4.toString() << endl;

    c4.setprimes(317, 491);
    cout << c4.toString() << endl;

    cout << "\nDerived Class Accessor Testing ----------------------------------------";

    Communicator c5("mickey mouse", "13.14.15.16", EncryptionSupport::getMedSizedRandomPrime(), EncryptionSupport::getMedSizedRandomPrime());
        cout << c5.toString() << endl;
        IntPair a;
        a = c5.getpublicKey();
        cout << "\n(" << a.firstInt << ", " << a.secondInt << ")\n";

    return 0;
}

//Derived Class Constructor Testing ----------------------------------------
//
//Name: (undefined)
//IP Addr: 0.0.0.0
//
//(p, q)  n, phi, e, d: (0, 0)   0, 0,   0, 0
//public key(0, 0)
//private key(0, 0)
//
//--------------------
//
//Name: meg hsu
//IP Addr: 1.2.3.4
//
//(p, q)  n, phi, e, d: (587, 859)   504233, 502788,   419, 444062
//public key(419, 504233)
//private key(444062, 504233)
//
//Derived and Base Class Mutator Testing ----------------------------------------
//
//Name: john doe
//IP Addr: 5.6.7.8
//
//(p, q)  n, phi, e, d: (929, 733)   680957, 679296,   53, 51393
//public key(53, 680957)
//private key(51393, 680957)
//
//Name: john doe
//IP Addr: 5.6.7.8
//
//(p, q)  n, phi, e, d: (17, 3)   51, 32,   31, 28
//public key(31, 51)
//private key(28, 51)
//
//--------------------
//
//Name: jane doe
//IP Addr: 9.10.11.12
//
//(p, q)  n, phi, e, d: (709, 727)   515443, 514008,   19, 325543
//public key(19, 515443)
//private key(325543, 515443)
//
//Name: jane doe
//IP Addr: 9.10.11.12
//
//(p, q)  n, phi, e, d: (317, 491)   155647, 154840,   409, 79536
//public key(409, 155647)
//private key(79536, 155647)
//
//Derived Class Accessor Testing ----------------------------------------
//Name: mickey mouse
//IP Addr: 13.14.15.16
//
//(p, q)  n, phi, e, d: (563, 1009)   568067, 566496,   283, 204745
//public key(283, 568067)
//private key(204745, 568067)
//
//(283, 568067)

