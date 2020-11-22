//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//24 November 2020

#include <iostream>
#include <ostream>
#include <string>
#include "ItemType.h"
using namespace std;

ItemType::ItemType() {
	value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const {
	if (value < otherItem.value)
		return LESS;
	else if (value > otherItem.value)
		return GREATER;
	else
		return EQUAL;
}

void ItemType::Initialize(int number) {
	value = number;
}

string ItemType::Print() const {
	return to_string(value);
}
