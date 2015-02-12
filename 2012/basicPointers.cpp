/*
	Program to dynamically add a set of numbers
*/

#include <iostream>

using namespace std;

int main () {
	
	int sum = 0;
	char choice;
	int *number = NULL;
	
	do {
		
		number = new int;
		
		cout << "\nEnter a number\n";
		cin >> (*number);
		sum = sum + (*number);		
		cout << "\nDo you wish to add more numbers? (y/n)";
		cin >> choice;
		
		delete number;
	
	}while (choice == 'y');
	
	cout << "\n The Sum is \n" << sum;
}
