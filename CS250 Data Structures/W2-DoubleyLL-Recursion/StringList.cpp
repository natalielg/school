/************************************************
* Natalie Leon Guerrero
* CS 260 Data Structures
* Assignment 2 - Doubly Linked List
* Due:	10/12/17
* File:	SringList.cpp
************************************************/

#include "StringList.h"

using namespace std;

StringList::StringList() {
	// initializes pointer to NULL and sets count to 0
	head = tail = NULL;
	count = 0;
}

StringList::~StringList() {
	// removes all nodes and sets counter back to 0
	removeAll();
}

// inserts given string in alphabetical order
void StringList::insert(string data) {
	// built a node to traverse through linked list
	node *current;
	// node to trail behind the current node as it traverses through the list
	node *trailBehind;
	// build new node
	node *newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	// if list is empty
	if (head == NULL) {
		head = newNode;
		tail = newNode;

		// adds 1 to count and exits function
		count++;
		return;
	}

	current = head;

	// grabs the first letter from newNode and the word in the first node's string
	char *firstLetterNewNode;
	char *firstLetterString;
	firstLetterNewNode = &newNode->data.at(0);
	firstLetterString = &current->data.at(0);

	// sets bool to false, this is for later if the newNode is supposed to be 
	// at the end or somewhere in the middle of the linked list
	bool found = false;

	// if the newNode is supposed to be in the front of the list
	// if the first letter of the new node is before the first letter of the first
	// node
	// using to upper function so lower case letters wont go after Z
	if (toupper(*firstLetterNewNode) < toupper(*firstLetterString)) {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	// if the newNode is supposed to be somewhere in the middle of the linked list
	// and not at the end. firstLetterString is the first letter of current
	else {
		while (current->next != NULL && found == false) {
			trailBehind = current;
			current = current->next;
			firstLetterString = &current->data.at(0);

			// adds new node somewhere in the middle of the linked list in 
			// alphabetical order
			// using to upper function so lower case letters wont go after Z
			if (toupper(*firstLetterNewNode) < toupper(*firstLetterString)) {
				trailBehind->next = newNode;
				newNode->prev = trailBehind;
				newNode->next = current;
				current->prev = newNode;

				// if the new node was inserted, found will be true
				found = true;
			}
		}

		// if the new node was not inserted in the linked list, it should be
		// alphabetically at the end
		if (found == false) {
			current->next = newNode;
			newNode->prev = current;
			tail = newNode;
		}
	}

	// because a node was added, count is incremented by 1
	count++;
}

// removes all occurances of given string. returns number of items removed
int StringList::remove(string data) {
	if (head == NULL)
		return 0;

	// initialize itemsRemoved to 0. It will be incremented as items are removed
	int itemsRemoved = 0;

	// if there is still data to be deleted, they will be removed
	while (find(data) > 0) {
		// if items are removed, itemsRemoved is incremented and count of the 
		// list is decremented
		if (removeOne(data) == true) {
			itemsRemoved++;
			count--;
		}
	}

	return itemsRemoved;
}

// returns count of items in the list
int StringList::totalItem() const {
	return count;
}

// removes all items from the list
void StringList::removeAll() {
	if (head == NULL)
		return;

	// temp node is created to free memory as it traverses through the list
	node *temp;

	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
	}

	// head and tail should be NULL, and count goes back to 0;
	tail = NULL;
	count = 0;
}

// prints list of strings in order
void StringList::printForward() const {
	// if head == NULL then the list is empty and nothing is printed
	if (head != NULL) {
		// node is created to traverse through list
		node *current;

		current = head;

		// prints nodes forwards
		while (current->next != NULL) {
			cout << current->data << ", ";

			current = current->next;
		}

		cout << current->data << endl;
	}
}

// prints list of string in reverse order
void StringList::printReverse() const {
	// will not do anything if the list is empty
	if (head != NULL) {
		// node is created to traverse through list
		node *current;

		current = tail;

		// prints nodes backwards
		while (current->prev != NULL) {
			cout << current->data << ", ";

			current = current->prev;
		}

		cout << current->data << endl;
	}
}

// counts and returns how many times the given string occurs in the list
int StringList::find(string data) {
	if (head == NULL)
		return 0;

	int found = 0;

	// calls recursive private function
	find(data, found, head);

	return found;
}

// counts and returns how many times the given letter (case sensitive) occurs
// in the string
int StringList::findLetter(char data) {
	// if the list is empty, there is nothing to search
	if (head == NULL)
		return 0;

	int found = 0;

	// calls recursive private function
	findLetter(data, found, head);

	return found;
}
void StringList::find(string data, int &found, node *nodePtr) {
	// if nodePtr is at the end of the list, exits out of recursion
	if (nodePtr == NULL)
		return;

	// if the string matched, found counter is incremented and sent back
	if (nodePtr->data == data)
		found++;

	// recursion function
	find(data, found, nodePtr->next);
}

void StringList::findLetter(char data, int &found, node *nodePtr) {
	// if nodePtr is at the end of the list, exits out of recursion
	if (nodePtr == NULL)
		return;

	// will treat the string as an array to access char's on their own
	string currString;
	char c;

	// for loop to run through each string as an array and look at each character 
	for (int i = 0; i < nodePtr->data.length(); i++) {
		currString = nodePtr->data;
		c = currString[i];

		// if the letters match, found count is incremented
		if (c == data)
			found++;
	}

	// recursion
	findLetter(data, found, nodePtr->next);
}

bool StringList::removeOne(string data) {
	// removes first node
	if (head->data == data) {
		node* temp = head;
		head = head->next;

		// if head != NULL then the list is not empty and prev node needs to point to NULL
		if (head != NULL)
			head->prev = NULL;
		// if head = NULL, then list is empty and tail = NULL
		else
			tail = NULL;

		// memory is deallocated
		delete temp;
		return true;
	}
	// other - middle or end nodes to be removed
	else {
		node *current = head->next;
		node *trail = head;

		// while loop to loop through linked list
		while (current != NULL) {
			// if data is found, it will be removed
			if (current->data == data) {
				node *temp = current;
				current = current->next;

				// removes the last node
				if (current == NULL) {
					trail->next = NULL;
					tail = trail;
				}
				// removes any node between the first and last node
				else {
					trail->next = current;
					current->prev = trail;
				}

				// memory is deallocated
				delete temp;
				return true;
			}

			// loop through while, onto the next nodes to test
			trail = current;
			current = current->next;
		}

		// if nothing was removed, will return false
		return false;
	}
}
