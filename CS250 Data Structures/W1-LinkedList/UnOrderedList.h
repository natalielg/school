/*
	Natalie Leon Guerrero
	CS 260 Data Structures
	Assignment 1 - Linked Lists and Template Implementation
	Due:	8/3/2017
	File:	UnOrderedList.h
*/

#pragma once

#include <stdlib.h>

template <typename dataType>
struct node {
	dataType data;
	node<dataType>* next;
};

template <typename dataType>
class UnOrderedList {
public:
	UnOrderedList();
	// deallocates memory using removeAll()
	~UnOrderedList();
	// insert data at the front of list 
	bool prepend(dataType dataToInsert);
	// insert data at the end of list
	bool append(dataType dataToInsert);
	// removes the given data from the list. returns true if successful and false if otherwise
	bool remove(dataType dataToRemove);
	// looks for a duplicate. returns position in list (1=first), or 0 if there are no duplicates
	int find(dataType dataToFind) const;
	// returns the number of data in the list
	int count() const;
	// prints stack to the screen
	void print() const;
	// removes all data in the list
	void removeAll();

private:
	node<dataType> * head;
};



template <typename dataType>
UnOrderedList<dataType>::UnOrderedList() {
	head = NULL;
}

template <typename dataType>
UnOrderedList<dataType>::~UnOrderedList() {
	removeAll();
}

template <typename dataType>
bool UnOrderedList<dataType>::prepend(dataType dataToInsert) {
	// check for duplicates
	if (find(dataToInsert) != 0)
		return false;

	// build new node
	node<dataType> *newNode = new node<dataType>;
	newNode->data = dataToInsert;
	newNode->next = NULL;

	// inserts data into empty list
	if (head == NULL) {
		head = newNode;
		return true;
	}

	// insert data at the beginning of the list
	newNode->next = head;
	head = newNode;

	// returns true since data was entered into the list
	return true;
}

template <typename dataType>
bool UnOrderedList<dataType>::append(dataType dataToInsert) {
	// check for duplicates
	if (find(dataToInsert) != 0)
		return false;

	// build new node
	node<dataType> *newNode = new node<dataType>;
	newNode->data = dataToInsert;
	newNode->next = NULL;

	// inserts data into empty list
	if (head == NULL) {
		head = newNode;
		return true;
	}

	// inserts data at the end of the list
	node<dataType> *current = head;

	while (current->next != NULL)
		current = current->next;

	current->next = newNode;

	// returns true since data was entered into the list
	return true;
}

template <typename dataType>
bool UnOrderedList<dataType>::remove(dataType dataToRemove) {
	// finds position of the data in the stack
	int position = find(dataToRemove);

	// returns false if the data is in the stack
	if (position == 0) {
		return false;
	}
	// if the data is in the first node, this removes the first node
	else if (position == 1) {
		node<dataType> *temp = head->next;
		free(head);
		head = temp;

		return true;
	}
	// checks the rest of the list for the data and removes 
	else {
		node<dataType> *current = head;

		for (int i = 0; i < (position - 2); i++)
			current = current->next;

		node<dataType> *temp = current->next;
		current->next = temp->next;

		// deallocates memory
		free(temp);

		return true;
	}
}

template <typename dataType>
int UnOrderedList<dataType>::find(dataType dataToFind) const {
	// created a trail node to go through the list and a position initialized to 0
	node<dataType> *current = head;
	int position = 0;

	// searches the list for a match to dataToFind. position is incremented each time.
	while (current != NULL) {
		position++;

		if (current->data == dataToFind)
			return position;

		current = current->next;
	}

	// returns 0 if no duplicate is found
	return 0;
}

template <typename dataType>
int UnOrderedList<dataType>::count() const {
	// returns 0 if the list is empty
	if (head == NULL)
		return 0;

	// created a trail node to count the list and a count initialized to 0
	node<dataType> *current = head;
	int count = 0;

	// counts the list and returns the number
	while (current != NULL) {
		count++;
		current = current->next;
	}

	return count;
}

template <typename dataType>
void UnOrderedList<dataType>::print() const {
	// created a trail node to print the list
	node<dataType> *current = head;

	// prints the list
	while (current != NULL) {
		std::cout << current->data << ' ';
		current = current->next;
	}

	// new line after the list
	std::cout << std::endl;
}

template <typename dataType>
void UnOrderedList<dataType>::removeAll() {
	// removes all ints from the list

	node<dataType> *current = head;
	node<dataType> *next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	// head points back to NULL as it is empty
	head = NULL;
}
