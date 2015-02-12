/*
	Implementation file for 
*/
#include "ADTBST.h"

void ADTBST::InsertItem (int item)
{

	InsertItemBST (item, m_Root);
}

void ADTBST::InsertItemBST(int item, TreeNode * root)
{
	// Base Case
	if (root == NULL)
	{		
		root = new ADTBST;
		root -> leftPtr = NULL;
		root -> rightPtr = NULL;
		root -> item = item;

		cout << "\nSuccessfully added the element " << item << " to the tree."
		return;
	}

	// Recursive
	if (item > root->item)
	{
		InsertItemBST(item, root -> rightPtr);
	}
	else
	{
		InsertItemBST(item, root -> leftPtr);
	}
}

/*
	 Deallocation of a tree is by Postorder traversal.
	 We want to make sure all the nodes get deleted first 
	 and then the root node gets deleted
*/ 
void ADTBST::DeAllocateBST(TreeNode * root)
{
	// Basis condition
	if (root == NULL)
	{
		return;
	}

	// Recursive condition
	DeAllocateBST(root -> leftPtr);

	DeAllocateBST(root -> rightPtr);

	// Delete node
	cout << "\nDeleting current node with item: " << root -> item;
	root -> leftPtr = NULL;
	root -> rightPtr = NULL;
	delete root;
	root = null;x
}

void ADTBST::PrintTree ()
{
	InorderTraversal (m_Root);
}

void ADTBST::InorderTraversal (TreeNode * root)
{
	// Basis Condtion
	if (root == NULL)
	{
		return;
	}

	InorderTraversal (root -> leftPtr);
	cout << "\nCurrent tree node has the item: " << root -> item;
	InorderTraversal (root -> rightPtr);
}

ADTBST::~TreeNode()
{
	DeAllocateBST (m_Root);
}






