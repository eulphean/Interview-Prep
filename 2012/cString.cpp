/*
	Program to make a character string and display its characters. 
	These are C Strings different than C++ strings that are basically String myString
	It allows you to enter a character string and modify any specific character of that string
*/
#include <iostream>
#include <cstring>

using namespace std;

void modifyString (char * pointer, int index, char ch);
void printString (char * pointer);

int main (){
	
	/*
		20 contiguous characters in an array are allocated in memory
	*/
	char *string = new char [20]; 
	char ch;
	
	cout << "\nEnter a String to be stored inside the character array\n";
	
	/*
		To get the entire line in or else only the first string comes in 
		and the space is detected as the end of line character
	*/
	cin.getline (string, 20); 	
	
	/*
		Printing the string
	*/
	printString (string);
	
	cout << "\nDo you want to modify a character?\n";
	cin >> ch;
	
	while (ch == 'y'){
		int index; 
		char newchar;
		cout << "\nIndex\n";
		cin >> index;
		cout << "\nNew Character\n";
		cin >> newchar; 
		modifyString (string, index, newchar);
		printString (string);	
		cout << "\nDo you want to modify a character?\n";
		cin >> ch;
	}
	delete [] string;
}

void printString (char *string){
	
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

void modifyString (char *string, int indx, char ch){
	
	string[indx] = ch;
	
}