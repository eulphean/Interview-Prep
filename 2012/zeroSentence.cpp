/*
	Bloomberg Question (Internet)
	
	Program to put all the zeroes at the end of the array:
	[1,3,0,8,12,0,4,0,7] ---> [1,3,8,12,4,7,0,0,0]
	
	0, 1 -> 1, 0
	
*/

#include <iostream>

using namespace std;

void printArray (int array []);

int main () {

	bool shift = false;

	int array [] = {1,1,0,2,10,9,0,5,0,4,3,1};
	
	int i, j;
	
	for (i = 0, j = 0; i < 12, j < 12; i++, j++){
		
		if (array[j] == 0){
			j++; 
			shift = true;
		}
		
		if (shift == true){
			array [i] = array[j];
			array[j] = 0;
		}	
	}
	
	printArray (array);
}

void printArray (int array []){

	for (int i = 0; i < 12; i++){
		cout << array[i] << ",";
	}
}