/*
	Program to write a String backward using recursion
*/

#include <iostream>

using namespace std;

void printBackward (char * string, int i);

int main () {
	
	char *string = "Amay";
	
	printBackward (string, 0);
	
	return 0;
}

void printBackward (char *string, int i){
	
	// Base Case
	if (string[i] == '\0'){
		return;
	}
	
	/* 
		Recursive Step
		- Do not change the 
	*/
	printBackward (string, i+1);
	
	cout << string [i] << "\n";	
}
		
	
	
	