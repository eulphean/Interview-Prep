/*	
	Multidimensional arrays using a double pointer
	Program: Make two matrices indexed by double pointers and write 
	the logic to multiply them.
	
	Pointer Basics:
	int *pointer; // declaration
	int a = 5;
	pointer = &a; // initialization
	cout << (*pointer);
	
	pointer = new int; // declaration for the heap as well
	*pointer = 10;
	delete pointer;
	cout << "\n" << (*pointer);
	
	Double Pointer:
	int * ptr1;
	int a = 5;
	ptr1 = &a;
	int **ptr2; - Declares a double pointer
	ptr2 = & ptr1;
	cout << (**ptr2);
*/

#include <iostream>

void initializeMatrix (int ** pointer, int element);

void deleteMatrix (int ** pointer);

void printMatrix (int ** pointer);

/*
	I wanted to return a pointer with this but the 
	value of that pointer will be as it will be in the local scope.
*/
void addMatrix (int ** pointer, int **, int **); 

void multiplyMatrix (int **, int **, int **);

using namespace std;

int main (){

	int **matrix1 = new int * [3];
	int **matrix2 = new int * [3];
	int **resultMatrix = new int * [3];
	
	initializeMatrix (matrix1, 2);
	initializeMatrix (matrix2, 2);
	initializeMatrix (resultMatrix, 2);
	
	addMatrix (matrix1, matrix2, resultMatrix);
		
	printMatrix (resultMatrix);
	deleteMatrix (matrix1);
	deleteMatrix (matrix2);
	deleteMatrix (resultMatrix);
} 

void initializeMatrix (int **matrix1, int element){

	for (int i = 0; i < 3; i++){
		matrix1[i] = new int [3];	
	}
	
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			matrix1[i][j] = element;
		}
	}
}

void printMatrix (int ** matrix1){

	cout << "\nPrinting Matrix\n";
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << matrix1 [i][j];
		}
		cout << "\n";
	}
}

void deleteMatrix (int ** matrix1){
	
	for (int i = 0; i < 3; i++){
		delete [] matrix1[i];	
	}
	delete [] matrix1;
}

void addMatrix (int ** matrix1, int ** matrix2, int ** result){
	
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
}



