/*
	Program: Find the maximum in an unsorted array with recursion
*/

#include <iostream>

using namespace std;

int findMax (int, int, int array []);

int main () {

	int size = 10;
	int array [10] = {10, 5, 12, -1, 0, 3, 4, 13, 5, 11};
	cout << "\nMy Array {10, 5, 12, -1, 0, 3, 4, 13, 5, 11} \n";
	
	int item = findMax (0, size-1, array);
	
	cout << item;
}

int findMax (int begin, int end, int array []){

	// Basis Case
	if (begin == end){
		return array [begin];
	}
	
	int mid = (begin + end)/2;
	
	// Recursion Step
	int a = findMax (begin, mid, array);
	int b = findMax (mid+1, end, array);
	
	// Recomposition Step
	if (a>b)
		return a;
	else 
		return b;
}
	