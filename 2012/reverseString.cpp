/*
	Microsoft Interview Question
	Zynga Interview Question
	
	Reverse a string around a space using cStrings
	hello world - olleh dlrow
*/

#include <iostream>

using namespace std;

void reverseString (char *ptr, int, int);

void printString (char *ptr);


int main() {
	char *string = new char [25];
	cout << "\nEnter a String to be stored inside the character array\n";
	cin.getline (string, 25); 	
	
	int i = 0;
	int begin = i;
	while (string[i]!='\0'){
	
		if (string[i] == ' '){
			reverseString (string, begin, i-1); 
			begin = i + 1;
		}
		i++;
	}
	reverseString (string, begin, i-1);
	printString (string);
}

void reverseString (char *string, int start, int end){

	// Mid-point is the key in reversing something
	// Probably change this to start and end also
	int mid = (start + end)/2;
	for (int i = 0; i <= (mid-start); i++){
		char temp = string[start + i];
		string [start + i] = string [end - i];
		string [end-i] = temp;	
	}
}

void printString (char *ptr){
	
	cout << "\n";
	int i = 0;
	while (ptr[i]!='\0'){
		cout << ptr[i];
		i++;
	}
}