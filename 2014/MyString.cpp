/*
	Implementation File declaration of a MyString class that's a container class for a dynamic cstring
*/
#include <iostream>
#include "MyString.h"
#include <cstring>

using namespace std;

// default constructor
MyString::MyString()
{
	(*this).m_Length = 0;
	(*this).m_StringPtr = 0;
}

// default constructor
// Sets length and allocates space for the string
MyString::MyString(int strLength) : m_Length(strLength)
{
	m_StringPtr = new char [strLength];
	cout << "Creating a MyString of length = " << m_Length << "\n";
}

// default contructor
// Set length and allocates space for the string
MyString::MyString(char * sString)
{
	SetLength(strlen(sString));
	m_StringPtr = new char [m_Length];
	strncpy (m_StringPtr, sString, m_Length);
	cout << "New MyString created contains " << m_StringPtr << "\n";
}

// SetString() to set content of a string
void MyString::SetString (char * sString)
{
	int sizeString = strlen (sString);
	if (sizeString <= m_Length)
	{
		strncpy (m_StringPtr, sString, m_Length);
		cout <<"Set the string to "<< m_StringPtr << "\n";
	}
	else
	{
		cerr << "Size of MyString is " << m_Length <<" \n And Size of input string is " << sizeString << "\n";
	}
}


// GetString() to get the content of a string
char * MyString::GetString ()
{
	if ((*this).m_StringPtr)
	{
		return (*this).m_StringPtr;
	}
}

void MyString::SetLength(int sLength)
{
	cout << "Setting the String Length to " << sLength <<"\n";
	m_Length = sLength;
}

int MyString::GetLength()
{
	return m_Length;
}

// Destructor to delete the string
MyString::~MyString()
{
	if ((*this).m_StringPtr || m_Length !=0)
	{
		cout << "Deleting the string " << m_StringPtr << "\n";
		delete [] m_StringPtr;
	}
}

/* 
	Copy Constructor is used to copy data from an "ALREADY EXISTING" object to an
	object that "DOESTN'T Exist." Situations copy constructor is called. 

	1: Pass by value
	2: Return by value (not now, it'created inplace)
	3: Intialization of an Object. MyString cString (mString) or MyString cString = mString;
	where mString already exists.
*/
MyString::MyString (const MyString& cString)
{
	cout << "Calling the Copy Constructor\n";
	if (cString.m_StringPtr)
	{
		m_StringPtr = new char [cString.m_Length];
		this -> SetLength(cString.m_Length);
		this -> SetString(cString.m_StringPtr);		
	}
	else
	{
		this -> SetLength(0);
		this -> SetString(0);
	}
}

/*
	Overloading the output operator to print the output by just
	typing cout << cString;
*/
ostream& operator<<(ostream& out, const MyString& cString)
{
	out << "Printing the current MyString ";
	for (int i =0; i< cString.m_Length; ++i)
	{
		out << cString.m_StringPtr[i];
	}
	out<<"\n";
	return out;
}

/*
	Overloading the arithmatic operator to concatenate two strings.
	Notice that the result sent is passed by value. This will
	also call the Copy Constructor on the Temp object sent back.
*/
MyString operator+(const MyString& c1, const MyString& c2)
{
	cout << "Calling overloaded addition operator\n";
	MyString temp (c1.m_Length + c2.m_Length);
	temp.SetString (strcat(c1.m_StringPtr, c2.m_StringPtr));
	return temp;
}

/*
	Assignment Operator is called whenever value is assigned from an object 
	to another object that "Already Exists."
	
	Pseudocode
	MyString obj1 ("Amay");
	MyString obj2 ("IsKind")
	obj2 = obj1
	cout <<obj2 =>  Amay

*/
MyString& MyString::operator=(const MyString& c1)
{
	cout << "Calling overloaded assignment operator\n";
	if (c1.m_StringPtr==this->m_StringPtr)
	{
		return (*this);
	}
	else
	{
		if (this->m_StringPtr)
		{
			delete [] m_StringPtr;
			this->m_Length = c1.m_Length;
			this->m_StringPtr = new char [this->m_Length];
			strcpy (this->m_StringPtr, c1.m_StringPtr);
		}
	}

	return *this;
}
