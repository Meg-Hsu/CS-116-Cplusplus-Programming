//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//24 November 2020

#ifndef UNSORTED_H_
#define UNSORTED_H_

#include "ItemType.h"
using namespace std;

class UnsortedType {
private:
	struct NodeType {
		ItemType info;
		NodeType *next;
	};

	NodeType *listData;
	int length;
	NodeType *currentPos;

public:
	UnsortedType();
	~UnsortedType();
	void MakeEmpty();
	bool IsFull() const;
	int GetLength() const;

	ItemType GetItem(ItemType &item, bool &found);

	void PutItem(ItemType item);
	void DeleteItem(ItemType item);

	void ResetList();
	ItemType GetNextItem();
	string SplitList(ItemType item, UnsortedType &list1, UnsortedType &list2);
};

#endif /* UNSORTED_H_ */
