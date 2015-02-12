/*
	Program to solve the cats and dogs problem in Spotify
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Kept {

	int idx;
	char trait;
};

struct Thrown {

	int idx;
	char trait;
};
struct Combination {

	Kept kept;
	Thrown thrown;
	int voters;
	Combination *next;
};

void insertItem (Combination *& head, Combination *& tail, char, int, char, int);
void deleteList (Combination *& head, Combination *& tail);
bool checkIteminList (Combination *& head, char, int, char, int);
void printList (Combination *);
int processList (Combination *);

int main (int argc, char * argv[]) {

	Combination *head = NULL;
	Combination *tail = NULL;
	
	char * filename = argv [1];
	if (filename == NULL) { cerr << "ERROR"; exit (0); }
	int testcase, cats, dogs, voters;
	char trait1, trait2; int idx1, idx2;
	bool insertflag = true; 
	int totalVoters;
	
	fstream fio;
	fio.open (filename, ios::in);
	// Reading the first line as the number of test cases
	fio >> testcase; 
	
	for (int i = 0; i < testcase; i++){
		fio >> cats; fio >> dogs; fio >> voters;
		for (int b = 0; b < voters; b++){
			
			fio >> trait1; fio >> idx1;
			fio >> trait2; fio >> idx2;
			//cout << "Kept: " << trait1 << idx1 << " Thrown: "<< trait2 << idx2 << "\n";
			if (head!=NULL) insertflag = checkIteminList (head, trait1, idx1, trait2, idx2);
			if (insertflag == true) insertItem (head, tail, trait1, idx1, trait2, idx2);
		}
		
		totalVoters = processList (head);
		
		cout << totalVoters;
		if (i!=testcase-1) cout << "\n";
		
		//cout << "Maximum Satisfied Voters " << totalVoters << "\n";
		
		//printList (head);
		deleteList (head, tail);
	}
	fio.close();
	
	return 0;
}

void insertItem (Combination *& head, Combination *& tail, char trait1, int idx1, char trait2, int idx2){

	Combination * newptr = new Combination;
	newptr -> kept.trait = trait1;
	newptr -> kept.idx = idx1;
	newptr -> thrown.trait = trait2;
	newptr -> thrown.idx = idx2;
	newptr -> voters = 1;
	newptr -> next = NULL;
	
	if (head == NULL){
		head = newptr; 
		tail = head;
	}
	else {
		tail -> next = newptr;
		tail = newptr;
	}	
	
}

void deleteList (Combination *& head, Combination *& tail){
	
	while (head != NULL){
		Combination * ptr = head;
		head = head->next;
		delete ptr;
		ptr = NULL;
	}
	tail = NULL;
}

void printList (Combination * head){

	while (head!=NULL){
		cout << "Kept: " << head->kept.trait << head->kept.idx;
		cout << " Thrown: " << head->thrown.trait << head->thrown.idx;
		cout << " Voters: " << head->voters;
		cout << "\n";
		head = head -> next;	
	}
}

bool checkIteminList (Combination *&Head, char trait1, int idx1, char trait2, int idx2){

	Combination  * head = Head;
	while (head!=NULL){
		if (head->kept.trait == trait1 && head->kept.idx == idx1 && head->thrown.trait == trait2 && head->thrown.idx == idx2){
			head->voters+=1;
			return false;
		}
		head = head -> next;
	}
	return true;
}

/*
	Algorithm to find the maximum satisfied voters in the competition
*/
int processList (Combination * head){

	int max = head->voters;
	for (Combination * ptr1 = head; ptr1!=NULL; ptr1= ptr1->next){
		for (Combination * ptr2 = ptr1->next; ptr2!=NULL; ptr2 = ptr2->next){
		
			if (!((ptr2->thrown.trait == ptr1->kept.trait && ptr2->thrown.idx == ptr1->kept.idx)||
				(ptr2->kept.trait == ptr1->thrown.trait && ptr2->kept.idx == ptr1->thrown.idx))){
					ptr1->voters +=ptr2->voters;
			}
		}
		if (ptr1->voters > max) max = ptr1->voters;
	}
	return max;
}
	

