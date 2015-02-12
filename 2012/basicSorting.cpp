/*
	Implementation of Sorting procedures
	1: Selection Sort
	2: Bubble Sort
	3: Insertion Sort (think of it like sorting a card hand in your hand) - Picking up a card and putting at the 
	right place
*/

#include <iostream>

using namespace std;

void selectionSort (int array[]);
void bubbleSort (int array[]);
void insertionSort (int array[]);
void printArray (int array[]);

int main (){

	int choice;
	
	int array [10] = {10, 5, 12, -1, 0, 3, 4, 13, 5, 11};
	cout << "\nArray to be sorted {10, 5, 12, -1, 0, 3, 4, 13, 5, 11} \n";
	
	cout << "\nInsert your choice of sorting algorithm\n\n";
	cout << "1: Selection Sort, O(n^2)1`\n";
	cout << "2: Bubble Sort, O(n^2)\n";
	cout << "3: Insertion Sort, O(n^2)\n"
	
	cin >> choice;
	
	switch (choice){
	
	case 1:
		selectionSort (array);
		break;
	
	case 2: 
		bubbleSort (array);
		break;
		
	case 3: 
		insertionSort (array);
		break;
	
	default:
		break;
	}
	
	printArray (array);
}

void swap (int array [], int i, int j){

	int temp = array[i];
	array[i] = array [j];
	array[j] = temp;
}

void selectionSort (int array[]){
	
	for (int i = 0; i < 10; i++){
		for (int j = i+1; j < 10; j++){
			if (array[j] < array[i]){
				swap (array, i, j);
			}
		}
	}
}

void bubbleSort (int array[]){
	
	int size = 10; //Number of elements
	bool sorted = true;
	for (int i = size; i > 0; i--){
		for (int j = 0; j <i-1; j++){
			if (array[j] > array[j+1]){
				swap (array, j, j+1);
				sorted = false;
			}
		}
		/*
			If no adjacent exchange wasn't made, the array is sorted. Every element
			is in the right increasing order
		*/
		if (sorted == true)
			break;
		sorted = true; 
	}
}

void insertionSort (int array[]){
	
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
