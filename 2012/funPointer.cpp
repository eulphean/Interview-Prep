/*
	Program to show the basic working of function pointers
*/

#include <iostream>

using namespace std; 

int myFunction (int a);
int main () {

	int (*ptr_function) (int);
	ptr_function = &myFunction;
	int val = ptr_function (int);
	cout << val; 
	return 0;
}

int myFunction (int a){
	return a;
}