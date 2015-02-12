/*
	Bloomberg Question (2012 Interview) Program to find spaces in a sentences and move all the spaces 
	
	hello world amay kataria -> helloworldamaykataria 	.
	
	Disintegrate the problem into small parts. I started with the following
	 h 
	h
	a m
	am 
*/


#include <iostream>

using namespace std;

void printString (char * string);

int main (){
	
	char *string = new char [25];
	cout << "\nEnter a String to be stored inside the character array\n";
	cin.getline (string, 25); 
	
	bool shift = false;
	int i = 0;
	int j = 0;
	
	while (string[j]!='\0'){
	
		if (string[j] == ' '){
			shift = true;
			j++;
		}
		
		if (shift == true){
			string [i] = string [j];	
			string[j] = ' ';
		}
		
		j++;
		i++;
	}
	
	printString (string);
	
return 0;
}

void printString (char * string){

	int i = 0;
	while (string[i]!='\0'){
		cout << string[i];
		i++;
	}
}