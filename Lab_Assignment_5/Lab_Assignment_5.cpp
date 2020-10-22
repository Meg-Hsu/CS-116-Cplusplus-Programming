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
