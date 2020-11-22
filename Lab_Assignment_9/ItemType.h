//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//24 November 2020

#ifndef ITEMTYPE_H_
#define ITEMTYPE_H_

#include <string>
using namespace std;

const int MAX_ITEMS = 25;
enum RelationType {
	LESS, GREATER, EQUAL
};

class ItemType {
private:
	int value;
public:
	ItemType();
	RelationType ComparedTo(ItemType) const;
	string Print() const;
	void Initialize(int number);
};

#endif /* ITEMTYPE_H_ */
