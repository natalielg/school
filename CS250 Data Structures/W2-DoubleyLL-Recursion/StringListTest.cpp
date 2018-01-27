/************************************************
* Natalie Leon Guerrero
* CS 260 Data Structures
* Assignment 2 - Doubly Linked List
* Due:
* File:	StringListTest.cpp
************************************************/

#include "StringList.h"

#include <iostream>

using namespace std;

int main() {

	StringList list;

	list.insert("Bob");
	list.insert("David");
	list.insert("Alice");
	list.insert("Edward");
	list.insert("Claire");

	list.printForward();
	list.printReverse();

	list.insert("Bob");
	list.insert("Edward");
	list.insert("Claire"); 
	list.insert("Claire");

	list.printForward();

	cout << endl;
	cout << "Alice occurs " << list.find("Alice") << " times." << endl;
	cout << "Bob occurs " << list.find("Bob") << " times." << endl;
	cout << "Claire occurs " << list.find("Claire") << " times." << endl;
	cout << "Edward occurs " << list.find("Edward") << " times." << endl;

	cout << endl;
	cout << "'e' occurs " << list.findLetter('e') << " times." << endl;

	list.printForward();

	list.remove("David");
	list.remove("Alice");
	list.remove("Edward");

	cout << endl;
	list.printForward();
	list.printReverse();

	list.removeAll();
	list.printForward();
	list.printReverse();

	cout << endl << endl;

	return 0;
}
