/*
	Program to apply a **BINARY SEARCH** to find an element in an array
	Pre-condition: Array must be sorted
*/ 

#include <iostream>

using namespace std;

void SortMyArray (int array []);
void printArray (int array []);
int binarySearch (int begin, int end, int &item, int myArray []);

int main (){
	
	int item;
	int size = 10;
	int array [10] = {10, 5, 12, -1, 0, 3, 4, 13, 5, 11};
	cout << "\nMy Array {10, 5, 12, -1, 0, 3, 4, 13, 5, 11} \n";
	
	cout << "\n *** Sorting *** \n";
	SortMyArray (array);
	 
	printArray (array);
	
	cout << "\nEnter the element to be searched \n";
	cin >> item;	
	
	int index = binarySearch (0, size-1, item, array);
	cout << "\nIndex at which " << item << " is, is " << index;
}

void SortMyArray (int array[]){
	
	/*
		- Partition the sorted (1st Element) and unsorted (1...n) region
		- Apply bubble sort in the region from sorted to unsorted or do shifting adjacent items on the 
		sorted side
	*/
	
	int n = 10;
	
	for (int unsorted = 1; unsorted < n; ++unsorted){
		int item = array [unsorted];
		
		for (int location = unsorted; location > 0; --location){
			if (array[location-1] > array[location]){
				array[location] = array[location - 1];
				array[location - 1] = item;
			}	
		}
	} 
}
 
void printArray (int array []){
	
	cout << "\nSorted Result\n";
	
	for (int i = 0; i < 10; i++){
		cout << array [i] << ",";	
	}
}

int binarySearch (int begin, int end, int &item, int array[]){
	
	cout << "\nBinary Search Called\n";
	int mid = (begin + end)/2;
	
	int idx = 0;
	/*
		Base Case:
			(a) If item found
			(b) If item not found
	*/
	
	if (array[mid] == item)
		return mid;
	else if (begin > end){
		return -1;
	}
	
	// Recursive Step
	if (array[mid] > item)
		idx = binarySearch (begin, mid-1, item, array);
	else 
		idx = binarySearch (mid+1, end, item, array);
		
	return idx;	
}


	