/*
	Natalie Leon Guerrero
	CS 260 Data Structures
	Assignment 1 - Linked Lists and Template Implementation
	Due:	8/3/2017
	File:	Student.h
*/

#pragma once

#include <stdlib.h>
#include <string>

using namespace std;

class Student {
public:
	//constructor
	Student(const string name = "Anonymous", char letterGrade = 'W');

	//operator overloads
	friend bool operator== (const Student& stu1, const Student& stu2);
	friend ostream& operator<< (ostream& stream, const Student& student);

private:
	string name;
	char letterGrade;
};



Student::Student(const string name, char letterGrade) {
	this->name = name;
	this->letterGrade = letterGrade;
}

//operator overloads (provided because they aren’t covered in detail until CS202)
bool operator== (const Student& stu1, const Student& stu2)
{
	if (stu1.name == stu2.name && stu1.letterGrade == stu2.letterGrade)
		return true;
	else
		return false;
}

ostream& operator<< (ostream& stream, const Student& student)
{
	stream << student.name;
	stream << " (" << student.letterGrade << ") ";
	return stream;
}

/*
https://stackoverflow.com/questions/2355273/overloading-operator-and-recursion

commenting both stream << lines from operator << overload will compile, 
but if not then a stack over flow happens. why?
*/


