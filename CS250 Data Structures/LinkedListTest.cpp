/*
	Natalie Leon Guerrero
	CS 260 Data Structures
	Assignment 1 - Linked Lists and Template Implementation
	Due:	8/3/2017
	File:	LinkedListTest.cpp
*/

#include <iostream>

#include "UnOrderedList.h"
#include "Student.h"

using namespace std;

int main() {
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> UnOrderedList - Part 1

	cout << "Tests on a list of integers" << endl << endl;
	UnOrderedList<int> list;

	// Adding integers from the front of the list
	// 8 was added twice but will not be added since it is a duplicate
	list.prepend(1);
	list.prepend(8);
	list.prepend(23);
	list.prepend(3);
	list.prepend(8);
	list.print();
	cout << "There are " << list.count() << " integers in this list" << endl << endl;

	// 10 was added twice from the back, but only added once since it is duplicated
	list.append(10);
	list.append(10);
	list.print();
	cout << "There are " << list.count() << " integers in this list now" << endl << endl;

	// 10 and 3 (the end integers) are removed
	list.remove(10);
	list.remove(3);
	list.print();
	cout << "there are " << list.count() << " integers in this list now" << endl << endl;

	// 8 is successfully removed, but there isn't an 11 to be removed
	list.remove(8);
	list.remove(11);
	list.print();
	cout << "There are " << list.count() << " integers in this list now" << endl << endl;

	// one more integer is added to the front to make sure code works after integers are removed
	list.prepend(100);
	list.print();
	cout << "there are " << list.count() << " integers in this list now" << endl << endl;

	// list is deleted and the printed back onto the screen (but nothing should show up)
	list.~UnOrderedList();
	list.print();



	
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEMPLATE - Part 2
	// Professor Rich's Test Code

	cout << endl << endl;
	cout << "Tests on the Template" << endl << endl;

	// test template with ints --------------------------------
	UnOrderedList<int> intList;
	intList.prepend(10);
	intList.prepend(20);
	intList.prepend(5);
	intList.append(15);
	intList.append(25);
	intList.print();

	cout << "5 is in position " << intList.find(5) << endl;
	cout << "15 is in position " << intList.find(15) << endl;
	cout << "20 is in position " << intList.find(20) << endl;
	cout << "8 is in position " << intList.find(8) << endl;

	intList.remove(15);
	intList.remove(5);
	intList.remove(25);
	intList.print();

	intList.removeAll();
	intList.print();
	intList.~UnOrderedList();
	cout << endl << endl;

	// test on list of chars --------------------------------
	UnOrderedList<char>* charList = new UnOrderedList<char>;
	charList->append('k');
	charList->append('s');
	charList->prepend('r');
	charList->prepend('o');
	charList->prepend('w');
	charList->print();

	charList->remove('r');
	charList->remove('w');
	charList->remove('s');
	charList->print();

	charList->removeAll();
	charList->print();
	delete charList;


	
	
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> STUDENT - Part 3

	cout << endl << endl;
	cout << "Tests on Students" << endl << endl;

	// creating Student datatypes 
	Student Natalie("Natalie", 'A');
	Student Alexis("Alexis", 'B');
	Student Kayla("Kayla", 'A');
	Student Edward("Ed", 'C');
	Student Ryan("Ryan", 'B');
	Student Anonymous;
	Student Anonymous2;
	
	// using overloaded << operator to print a default Student and one I created
	cout << Natalie;
	cout << Anonymous << endl << endl;

	// using overloaded == operator, 1 is true and 0 is false
	cout << "Is Natalie and Alexis the same student? " << (Natalie == Alexis) << endl;
	cout << "Is Anonymous and Anonymous2 the same student? " << (Anonymous == Anonymous2) << endl << endl;

	// creating a linked list of Student data types
	UnOrderedList<Student> studentList;
	
	// using an UnOrderedList function prepend to add Student data types into the front of the linked list
	studentList.prepend(Natalie);
	studentList.prepend(Alexis);
	studentList.prepend(Kayla);
	studentList.print();
	
	// using append function to add Students to the end of the linked list
	studentList.append(Ryan);
	studentList.append(Edward);
	studentList.print();

	// removing a Student from the list
	studentList.remove(Natalie);
	studentList.print();

	// printing the order number of certain Students, and of a Student that no longer exists in the list
	cout << endl;
	cout << "Alexis is number " << studentList.find(Alexis) << " in the list" << endl;
	cout << "Ryan is number " << studentList.find(Ryan) << " in the list" << endl;
	cout << "Natalie is number " << studentList.find(Natalie) << " in the list" << endl;

	// deallocating the list of Students
	studentList.removeAll();
	studentList.print();
	studentList.~UnOrderedList();
	
	return 0;
}


