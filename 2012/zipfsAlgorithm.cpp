/*
	Program to illustrate Zipf's algorithm for song selection
*/

/*
	Checks to add to the program 
	(1) 1 = m = 50000, 1 = n = m
	(2) n lines are there post the first line
	(3)  0 = fi = 1012
	(4) ‘a’-‘z’, ‘0’-‘9’, and underscore (‘_’) - atmost 30 characters long
	
*/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

struct Song {

	// Song name
	char *string;
	// Actual total plays of the song
	int f; 
	// Index of the track
	int idx;
	Song * next;
};

void insertItem (Song *&, Song *&, char ar [], int, int);
void printList (Song *);
void deleteList (Song *&, Song *&);
void processList (Song *&);
void deleteSongNode ( Song *&, Song *&, Song *& head);
bool checkLine (char Ar []);

int main (int argc, char * argv[]) {	
	char * filename = argv[1]; char line [35];
	int m, n, a, idx=0;
	
	/*
		Head and tail pointer to maintain a list of songs
		Always declare these pointers, or else the code will go awry.
	*/
	Song *head = NULL;
	Song *tail = NULL;
	
	if (filename == NULL){
		cerr << "ERROR";
		exit(0);
	}
	
	fstream fio;
	fio.open (filename, ios::in);
	
	fio >> m; fio >> n;
	
	/*
		Check 1
	*/
	if (m<1 || m>50000){
		cerr << "ERROR";
		exit (0);
	}
	if (n<1 || n>m){
		cerr << "ERROR";
		exit (0);
	}
	
	
	// Reading the file
	while (!fio.eof()){
		++idx;
		fio >> a;
		if (a<0 || a>pow(10,12))
			exit (0);
		fio >> line;
		/*
			Check 4
		*/
		bool flag = checkLine (line);
		if (flag==true)
			insertItem (head, tail, line, a, idx);
		else {
			cerr << "ERROR";
			exit (0);
		}
	}
	
	/*
		Check 2
	*/
	if (idx > m || idx < m){
		cerr << "ERROR";
		exit (0);
	}
	
	fio.close();
	
	//printList (head);
	for (int b = 0; b < n; ++b){
		processList (head);
		if (b!=(n-1))
			cout << "\n";
	}
	
	deleteList (head, tail);
	return 0;
}

bool checkLine (char Ar[]){
	int i = 0;
	while (Ar[i]!='\0'){
		int a = Ar[i];
		if (!((a>=97 && a<=122)||(a>=48 && a<=57)|| (a==95))) return false;
		if (i>29) return false;
		i++;
	}
	return true;
}

void insertItem (Song *& head, Song *& tail, char string[], int f, int idx){

	// Insertion at the end (Using a tail pointer)
	Song * newPtr = new Song;
	newPtr -> string = new char [31];
	for (int i = 0; i < 31; i++){
		newPtr -> string[i] = string [i];
	}
	newPtr -> f = f;
	newPtr -> idx = idx;
	newPtr -> next = NULL;
	
	if (head == NULL){
		head = newPtr; 
		tail = head;
	}
	else {
		tail -> next = newPtr;
		tail = newPtr;
	}	
}

void printList (Song * head){

	Song * ptr = head;
	cout << "\n";
	while (ptr!=NULL){
	
		cout << "F = " << ptr->f;
		cout << ", Song Name = " << ptr->string;
		cout << "\n";
		ptr = ptr->next;
	}
}

void deleteList (Song *& head, Song *& tail){
	
	while (head != NULL){
	
		Song * ptr = head;
		head = head->next;
		delete [] ptr-> string;
		delete ptr;
		ptr = NULL;
	}
	tail = NULL;
}

/*
	Processes the List of songs and finds the one with the maxium Qi and deletes that node from this list
*/
void processList (Song *& head){

	Song * maxPtr = NULL;
	Song * maxPtrPrev = NULL; 
	Song * curHead = head;
	Song * prevPtr = NULL;
	
	double max = -1;
	
	for (int i = 1; curHead!=NULL; curHead = curHead->next, i++){
				
		double q = (curHead -> f)*(curHead -> idx);
		if (q > max){
			max = q;
			maxPtr = curHead;
			maxPtrPrev = prevPtr; 
		}
		prevPtr = curHead;
	}
	
	cout << maxPtr->string;
	deleteSongNode (maxPtr, maxPtrPrev, head);	
}
	
void deleteSongNode (Song *& curPtr, Song *& prevPtr, Song *& head){
	// Node to be deleted is the head node
	if (prevPtr==NULL){
		Song * ptr = curPtr;
		curPtr = curPtr->next;
		delete [] ptr->string;
		delete ptr;	
		head = curPtr;
	}
	else{
		prevPtr -> next = curPtr->next;
		delete [] curPtr->string;
		delete curPtr;	
	}
}
