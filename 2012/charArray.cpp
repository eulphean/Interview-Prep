/*
	Program to enter a set of characters in a character array and traverse through it.
	Important Note: Character Array and Character Pointer (char *string) are different
	char myArray[5] doesn't have an end of line (\0) character in it
	char *string has an end of line character in it
*/ 

#include <iostream>

using namespace std;

void traverseFunction (char *ptr, int index);
 
int main (){

	char myArray [15];
	
	for (int i = 0; i <15; i++){
		cout << "\nEnter a character for the array ("<<i<<")\n";
		cin >> myArray  [i];		
	}
	
	/*
	  Pointer to the first element of myArray
	  I can start a traversal of the elements from this 
	  point
	*/
	char *charPtr = &myArray[0];
	
	traverseFunction (charPtr, 15);	
	return 0;
}

void traverseFunction (char *arrayPtr, int index){

	int i = 0;
	while (i <index){
		cout << "\nCharacter (" << i << ")" << arrayPtr[i] << "\n";	
		i++;
	}
}