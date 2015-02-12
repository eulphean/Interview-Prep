/*
	This is a program to get 5 numbers from the user and store it in a 5 digit integer array.  Then add that array and
	print the sum.
*/


#include <iostream>

using namespace std;

int calculatemysum (int Array [], int index);

int main () {

	int myArray [5];
	int sum = 0;
	
	sum = calculatemysum (myArray, 5);

	cout <<"\n The sum of all the digits is " << sum;
}

int calculatemysum (int myArray [], int myindex){

 	int sum = 0;
	for (int i = 0; i<myindex; i++) {
			cout << "\nEnter a digit \n";
			cin >> myArray[i];	
	}
		
	for (int j = 0; j<myindex; j++) {
			
			sum = sum+myArray[j];
	}
	return sum;
}