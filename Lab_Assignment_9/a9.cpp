//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//24 November 2020

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

#include "unsorted.h"
#include "ItemType.h"
#include "unistd.h"
using namespace std;

string ListToString(UnsortedType&);
string SplitList(UnsortedType&, ItemType);

int main() {

	ifstream inFile;
	string command;

	int number;
	ItemType item;
	UnsortedType list;
	bool found;
	int numCommands;

	inFile.open(
			"/Users/meghsu/Desktop/Ohlone/CS-116/Lab_Assignment_9/listData.txt",
			std::ifstream::in); //insert file path to run
	if (!inFile) {
		cout << "File cannot be opened. Please try again" << endl;
		exit(1);
	}

	ofstream outFile("mha9out.txt");

	//uncomment the two lines below for output file path

	//char dir[120];
	//cout << getcwd(dir, 120) << endl;

	outFile << "Name: Meg Hsu\n"
			"Class: CS-116-03: C++ Programming\n"
			"Professor Lamble\n"
			"24 November 2020\n\n";

	inFile >> command;
	numCommands = 0;
	while (command != "Quit") {
		numCommands++;
		outFile << "Command " << numCommands << ": " << command << " ";

		if (command == "PutItem") {
			inFile >> number;
			item.Initialize(number);
			list.PutItem(item);
			outFile << "- ";
			outFile << item.Print();
			outFile << " was added to the list" << endl;
		} else if (command == "GetItem") {
			inFile >> number;
			item.Initialize(number);
			item = list.GetItem(item, found);
			outFile << "- ";
			outFile << item.Print();
			if (found)
				outFile << " is in the list" << endl;
			else
				outFile << " is not in the list" << endl;
		} else if (command == "DeleteItem") {
			inFile >> number;
			item.Initialize(number);
			list.DeleteItem(item);
			outFile << "- ";
			outFile << item.Print();
			outFile << " was deleted from list" << endl;
		} else if (command == "GetLength") {
			outFile << "- The length of the list = " << list.GetLength() << endl;
		} else if (command == "IsFull") {
			if (list.IsFull()) {
				outFile << "- The list is full" << endl;
			} else {
				outFile << "- The list is not full" << endl;
			}
		} else if (command == "MakeEmpty") {
			list.MakeEmpty();
			outFile << "- The list is empty" << endl;
		} else if (command == "PrintList") {
			outFile << "- See below:";
			outFile << "\n\nList values" << endl;
			outFile << ListToString(list);
		} else if (command == "SplitList") {
			inFile >> number;
			item.Initialize(number);
			SplitList(list, item);
		} else
			outFile << "- " << command << " is not a valid command" << endl;

		inFile >> command;
	}
	;

	outFile << "All commands completed." << endl;
	inFile.close();
	outFile.close();
	cout << "Commands have been written to mha9out.txt, closing output file.";
	return 0;
}

string ListToString(UnsortedType &list) { //listtostring
	int length;
	ItemType item;
	string value;

	list.ResetList();
	length = list.GetLength();
	for (int counter = 1; counter <= length; counter++) {
		item = list.GetNextItem();
		value += item.Print();
		value += '\n';
	}
	value = value + "Length of list = " + to_string(length) + "\n\n";
	return value;
}

string SplitList(UnsortedType &list, ItemType item) {
	UnsortedType list1, list2;
	list.SplitList(item, list1, list2);
	string value;

	value += "The list has been split into two.\n\n";
	value += "List 1:\n";
	value += ListToString(list1);
	value += "List 2:\n";
	value += ListToString(list2);
	return value;
}

//Name: Meg Hsu
//Class: CS-116-03: C++ Programming
//Professor Lamble
//24 November 2020
//
//Command 1: GetLength - The length of the list = 0
//Command 2: PutItem - 5 was added to the list
//Command 3: PutItem - 7 was added to the list
//Command 4: PutItem - 6 was added to the list
//Command 5: PutItem - 9 was added to the list
//Command 6: PrintList - See below:
//
//List values
//9
//6
//7
//5
//Length of list = 4
//
//Command 7: PutItem - 1 was added to the list
//Command 8: PrintList - See below:
//
//List values
//1
//9
//6
//7
//5
//Length of list = 5
//
//Command 9: GetItem - 4 is not in the list
//Command 10: GetItem - 5 is in the list
//Command 11: GetItem - 9 is in the list
//Command 12: GetItem - 10 is not in the list
//Command 13: IsFull - The list is not full
//Command 14: DeleteItem - 5 was deleted from list
//Command 15: IsFull - The list is not full
//Command 16: DeleteItem - 1 was deleted from list
//Command 17: DeleteItem - 6 was deleted from list
//Command 18: DeleteItem - 9 was deleted from list
//Command 19: PrintList - See below:
//
//List values
//7
//Length of list = 1
//
//Command 20: MakeEmpty - The list is empty
//Command 21: PrintList - See below:
//
//List values
//Length of list = 0
//
//Command 22: Error - Error is not a valid command
//All commands completed.

