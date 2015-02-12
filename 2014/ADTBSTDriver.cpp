#include "ADTBST.h"

using namespace std;

void TestCase1 (ADTBST& obj);
void TestCase2 (ADTBST& obj2);

int main ()
{
	int itemToAdd;
	char ch;

	ADTBST BST;

	do
	{
		cout << "Enter an element to add to the Tree: ";
		cin >> itemToAdd;
		BST.InsertItem (itemToAdd);
		cout << "\nWould you like to add more elements? (y/n): ";
		cin >> ch;
	}
	while (ch == 'y');

	TestCase1 (BST);

	TestCase2 (BST);

	return 0;
}

// Types of Tree Traversals
void TestCase1 (ADTBST& bst )
{
	cout << "\n~Executing Testcase 1~\n";
	char traverse;
	do 
	{
		cout << "Choose a Traversal Type for the tree T \na: Preorder, b: Inorder, c: Postorder\n";
		cin >> traverse;
		
		switch (traverse)
		{
			case 'a':
				cout << "\nYou chose Preorder. Following are the results.\n";
				bst.PrintTree (PREORDER);
				break;
			case 'b': 
				cout << "\nYou chose Inorder. Following are the results.\n";
				bst.PrintTree (INORDER);
				break;
			case 'c':
				cout << "\nYou chose Postorder. Following are the results.\n";
				bst.PrintTree (POSTORDER);
				break;
			default:
				cout << "\nWrong Input. '" <<traverse<<"' Please try again!\n";
				break;
		}

		cout << "\nWould you like to try more traversals?\n";
		cin >> traverse;
	}
	while (traverse =='y');
}

void TestCase2 (ADTBST& bst)
{
	int numToSearch;

	cout << "\n~Executing Testcase 2~\n";
	cout << "Enter the element you want to search for: ";
	cin >> numToSearch;

	bst.SearchItem (numToSearch);
}