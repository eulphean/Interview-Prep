#include "ADTBST.h"

using namespace std;

int main ()
{
	int itemToAdd;
	char ch;

	TreeNode ADTBST;

	do
	{
		cout << "Enter an element to add to the Tree: ";
		cin >> itemToAdd;
		ADTBST.InsertItem (itemToAdd);
		coud << "\nWould you like to add more elements? (y/n): ";
		cin >> ch;
	}
	while (ch == 'y');

	ADTBST.PrintTree ();


	return 0;
}
