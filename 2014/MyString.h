/*
	Header File declaration of a MyString class that's a container class for a dynamic cstring
*/

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

using namespace std;

class MyString
{
	// private variables
	char * m_StringPtr;
	int m_Length;

	public:

	// default constructors
	MyString ();
	MyString (int strLength);
	MyString (char * sString);

	// Getters
	int GetLength ();
	char * GetString ();

	// Setters
	void SetString (char * sString);
	void SetLength (int sLength);

	/* 
		Copy Constructor is used to copy data from an "ALREADY EXISTING" object to an
		object that "DOESTN'T Exist." Situations copy constructor is called. 

		1: Pass by value
		2: Return by value (not now, it'created inplace)
		3: Intialization of an Object. MyString cString (mString) or MyString cString = mString;
		where mString already exists.
	*/
	MyString (const MyString& cString);

	/*
		Overloading the arithmatic operator to concatenate two strings.
		Notice that the result sent is passed by value. This will
		also call the Copy Constructor on the Temp object sent back.
	*/
	friend MyString operator+(const MyString& c1, const MyString& c2);

	/*
		Overloading the output operator to print the output by just
		typing cout << cString;
	*/
	friend ostream& operator<<(ostream& out, const MyString& cString);

	/*
		Assignment Operator is called whenever value is assigned from an object 
		to another object that "Already Exists."
		
		Pseudocode
		MyString obj1 ("Amay");
		MyString obj2 ("IsKind")
		obj2 = obj1
		cout <<obj2 =>  Amay
	*/
	MyString& operator=(const MyString& c1);

	// destructor
	~MyString();
};


#endif

