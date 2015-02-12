/*
	Program to practice basicRecursion programs with arrays and factorials
	(1) Factorial - Find the factorial of "n"
	(2) Fibonacci Sequence - Find the fibonacci number "n"
*/

#include <iostream>

using namespace std;

int factorial (int );
int fibonacci (int );

int main () {
		
	int choice;
	int num;
	int result;
	cout << "\nChoose the Recursive Operation\n";
	cout << "1: Factorial(n)\n";
	cout << "2: Fibonacci(n)\n";
	cin >> choice;
	
	cout << "\nEnter the number\n";
	cin >> num;
	
	switch (choice){
		
		case 1: 
			result = factorial (num);
			cout << "\nThe Factorial of " << num << " is " << result;
			break;
		
		case 2: 
			result = fibonacci (num);
			cout << "\nThe " << num << " Fibonacci Number is " << result;
			break;
			
		default:
			break;	
	}
}

int factorial (int n){

	int val; 
	
	//Basis Case:
	if (n==1){
		val = 1;
	}
	//Recursive Step
	else{
		val = factorial (n-1);
	}
	// Recomposition Step
	int result = n * val;
	return result;
}

int fibonacci (int n){

	int result;
	int x = 0;
	int y = 0;
	
	//Base Case
	if (n <= 0){
		result = 0;
	}
	else if (n == 1){
		result = 1;
	}
	// Recursive Step
	else {
		x = fibonacci (n-1);
		y = fibonacci (n-2);
	// Recomposition Step
		result = x + y;
	}
	return result;
}
