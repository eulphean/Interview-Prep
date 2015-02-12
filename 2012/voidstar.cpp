/*
	Short example of void* pointer
*/

#include <iostream>

using namespace std;

void* voidstarInt (void * ptr);
void voidstarChar (void * ptr);

int main () {

	void * myPointer;
	int a = 10; char b = 'A';
	myPointer = &a; 
	void * temp = voidstarInt (myPointer);
	cout << *(int *)temp;
	myPointer = &b; 
	voidstarChar (myPointer);
}

void* voidstarInt (void *ptr){

	return ptr;
}
void voidstarChar (void *ptr){

	char *myPtr = (char *) ptr; 
	cout << *myPtr;
}