/*
	Driver program for MyString.cpp and MyString.h class and it's implementation
*/
#include <iostream>
#include <cstring>
#include "MyString.h"

#define DEBUG

using namespace std;

void printString (char * s);
void TestCase1();
void TestCase_CopyConstructor(MyString c);
void TestCase2();
void TestCase3();
void TestCase4();

int main ()
{

	TestCase1();

	TestCase2();


	TestCase3();
	
	TestCase4();

	cin.get();
	return 0;
}

void printString (char * string)
{
	/*
		The String entered is stored as a sequence of bytes in the memory.
		It can be accessed from the indices of the array
	*/
	int i = 0;
	
	while (string[i] != '\0'){
	
		if (string [i] == ' ')
			cout << "\nDetected a Space\n";
			
		cout << "Character (" << i << ")" << string [i] << "\n";
		i++;
	}
}

void TestCase1 ()
{

	cout << "Executing Test Case 1\n";
	int stringLength;
	cout << "Enter the length of String = ";
	cin >> stringLength;
	char * sString = new char [stringLength];
	cout << "Enter the value of the String = ";

	/*
		cin.ignore() to ignore to \n printed from the previous statement. Always a good idea to ignore 
		and clear the stream before reading something new.
	*/
	cin.ignore();
	cin.getline(sString, 10);
	printString (sString);

	MyString mString (stringLength);

	mString.SetString (sString);

	TestCase1 ();

	cout << "\nCreating cString\n";
	MyString cString = mString;
	cout << cString;

	cout << "\nCreating dString\n";
	MyString dString (mString);
	cout << dString;

	delete [] sString;
}

void TestCase2 ()
{
	cout << "\nExecuting Test Case 2" << "\n";
	char * sString = new char [10];
	strcpy (sString, "TestString");

	MyString aString (sString);
	TestCase_CopyConstructor (aString);

	delete [] sString;
}

/*
	Test case to verify the workings of the copy constructor
	when the class object is sent by value
*/
void TestCase_CopyConstructor (MyString cString)
{
	cout << cString;
}

void TestCase3()
{
	cout << "Executing Test Case 3";
	char * aString = new char [5];
	strcpy (aString, "Test");
	MyString aMyString (aString);

	char * bString = new char [5];
	strcpy (bString, "String");
	MyString bMyString (bString);

	/*
		This will first call operator+ and then the 
		copy constructor written for MyString class
	*/
	MyString cMyString (aMyString + bMyString);

	cout << cMyString;

	delete [] aString;
	delete [] bString;
}

void TestCase4()
{
	cout << "Executing Test Case 4\n";
	char * aString = new char [5];
	strcpy (aString, "Test");
	MyString aMyString (aString);

	char * bString = new char [5];
	strcpy (bString, "String");
	MyString bMyString (bString);

	cout << "Assigning String A to B\n";
	bMyString = aMyString;

	cout << bMyString;

	delete [] aString;
	delete [] bString;
}