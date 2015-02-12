/*
	Program to setup a basic linked list of 2 items (int and a character) and do some basic operations on it..
	
	Stack - LIFO
	Queue - FIFO
*/
#include <iostream>

using namespace std;

struct Node {

	int number;
	Node *next;
};

void insertItem (Node *& head, int num);
void printList (Node * head);
void deleteList (Node *& head);

int main () {

	// head pointer of the list
	Node *head = NULL;
	int num;
	char ch;
	
	do {
	
		cout << "Inserting an item into the list \n";
		cout << "Enter the number to be added: ";
		cin >> num;
		insertItem (head, num);
		cout << "\nDo you want to add more nodes? ";
		cin >> ch;
	} while (ch == 'y');
	
	cout << "\nPrinting List";
	printList (head);
	
	cout << "\nDeleting List\n";
	deleteList (head);
	
	return 0;
	
}

void insertItem (Node *& head, int num){
	
	Node * newPtr = new Node;
	newPtr->number = num;
	newPtr->next = NULL;
	
	/*
		Insertion at the beginning
		Takes care of the insertion in an empty list as well
	*/
	newPtr -> next = head;
	head = newPtr;
}

void printList (Node *head){
	
	if (head == NULL)
		return;
	
	cout << "\n" << head -> number;
	printList (head -> next);
}

void deleteList (Node *& head){
	
	if (head == NULL)
		return;
	
	deleteList (head->next);
	delete head;
}
