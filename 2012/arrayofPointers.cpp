/*
	Program to differentiate between array of pointers and a pointer pointing to an array
*/

#include <iostream>

using namespace std;

int main () {

	/*
		Pointer pointing to an array declared in the heap. Each element stores a single character
		****THIS IS NOT AN ARRAY OF POINTERS****
	*/
	char * array = new char [10];
	for (int i = 0; i < 10; i++){
		array[i] = 'A';		
		cout << array[i];
	}
	delete [] array;
	
	cout << "\n";
	/*
		ARRAY OF POINTERS in the STACK. Every character pointer points to a cString.
		Technically, space should be allocated first rather than doing this. 
	*/
	char *arrayofpointers [10];
	for (int i = 0; i < 10; i++){
		arrayofpointers[i] = "Amay";		
		cout << arrayofpointers[i] << "\n";
	}
	/*
		Dynamic initialization of **ARRAY OF POINTERS in the HEAP**
		arrayofpointers (variable in stack) --> 10 character pointers in the heap
		Exactly what is required for multidimensional arrays. 
		Since it's a pointer to a pointer, it's declared as a double pointer.
		
		Or 
		
		char *ptrarr [10];
		for (int i = 0; i <10; i++){
			ptrarr [i] = new char [10];
		}
		This ptrarr[10] remains in the stack. So, if this goes out of scope without 
		deletion, it will be heavy memory leak. 
	*/
	char **arrayofpointersinheap = new char * [10];
	/*
		There is a custom deletion for this
	*/
	for (int i = 0; i < 10; i++){
		delete arrayofpointersinheap[i];	
	}
	/*
		Follow matrixMultiply for further application
	*/
}