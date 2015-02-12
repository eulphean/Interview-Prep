/*
	Repeating the basic Array with an integer array pointer
*/

#include <iostream>

using namespace std;

void enternumfunc (int ptrArr[], int counter);

int main(){
	
	int *ptrArray;
	ptrArray = new int[5];
	/*
		Array pointer (Different from a pointer to an array)
		[int *][int *][int *][int *][int *]
		ptrArray [0] ---> derefenced integer in the memory block	
	*/
	char ch; 
	int counter = 0;
	
	do{
		cout <<"\nEnter a number (" << counter <<")\n";
		enternumfunc (ptrArray, counter);
		counter ++;
		cout <<"\nDo you want to add more numbers?\n (y/n)";
		cin >> ch;
		
	}while (ch == 'y' && counter < 5);
	
	// Traverse through that array
	for (int i = 0; i <5; i++){
		cout << "\nArray Element ["<<i<<"] -"<<ptrArray[i]<<"\n";
	}
	
	delete [] ptrArray;
	return 0;
}

void enternumfunc (int ptrArr[], int counter){

	cin >> ptrArr [counter];
}

