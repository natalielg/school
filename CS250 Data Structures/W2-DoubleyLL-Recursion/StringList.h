/************************************************
* Natalie Leon Guerrero
* CS 260 Data Structures
* Assignment 2 - Doubly Linked List
* Due:	10/12/17
* File:	StringList.h
************************************************/

#pragma once

#include <iostream>
#include <string>

using namespace std;

struct node {
	string data;
	node *next;
	node *prev;
};

class StringList {
public:
	StringList();
	~StringList();

	// inserts given string in alphabetical order
	void insert(string data);
	// removes all occurances of given string. returns number of items removed
	int remove(string data);
	// returns count of items in the list
	int totalItem() const;
	// removes all items from the list
	void removeAll();
	// prints list of strings in order
	void printForward() const;
	// prints list of string in reverse order
	void printReverse() const;
	// counts and returns how many times the given string occurs in the list
	int find(string data);
	// counts and returns how many times the given letter (case sensitive) occurs
	// in the string 
	int findLetter(char data);

private:
	node* head;
	node* tail;
	int count;

	// recursion find function, sends back data for found
	void find(string data, int &found, node *nodePtr);
	// recursion findLetter fucntion, sends back data for find
	void findLetter(char data, int &found, node *nodePtr);  
	// returns true if removal of a node took place
	bool removeOne(string data);
};
