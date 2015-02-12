/*
	Implementation file for 
*/
#include "ADTBST.h"

void ADTBST::InsertItem (int item)
{

	InsertItemBST (item, m_Root);
}

void ADTBST::InsertItemBST(int item, TreeNode *& root)
{
	// Base Case
	if (root == NULL)
	{		
		root = new TreeNode;
		root -> leftPtr = NULL;
		root -> rightPtr = NULL;
		root -> item = item;

		cout << "\nSuccessfully added the element " << item << " to the tree.";
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
void ADTBST::DeAllocateBST(TreeNode *& root)
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
	root = NULL;
}

void ADTBST::PrintTree (TraversalType T)
{
	switch (T)
	{
		case PREORDER:
			PreorderTraversal (m_Root);
			break;
		case INORDER:
			InorderTraversal (m_Root);
			break;
		case POSTORDER:
			PostorderTraversal (m_Root);
			break;
	}
}

void ADTBST::InorderTraversal (TreeNode * root)
{
	// Base Case
	if (root == NULL)
	{
		return;
	}

	// Recursive Condition
	InorderTraversal (root -> leftPtr);
	cout << "\nCurrent tree node has the item: " << root -> item;
	InorderTraversal (root -> rightPtr);
}

void ADTBST::PostorderTraversal (TreeNode * root)
{	
	if (root == NULL)
	{
		return;
	}

	PostorderTraversal (root -> leftPtr);
	PostorderTraversal (root -> rightPtr);
	cout << "\nCurrent tree node has the item: " << root -> item << "\n";
}

// 
void ADTBST::PreorderTraversal (TreeNode * root)
{
	if (root == NULL)
	{
		return;
	}

	cout << "\nCurrent tree node has the item: " << root->item << "\n";
	PreorderTraversal (root -> leftPtr);
	PreorderTraversal (root -> rightPtr);
}

void ADTBST::SearchItemInTree (int item, TreeNode * root)
{
	//Base Case
	if (root == NULL)
	{
		return;
	}

	if (item == root->item)
	{
		cout << "Item found: " << item;
	}

	// Recursive Condition
	if (item > root -> item)
	{
		SearchItemInTree (item, root -> rightPtr);
	}
	else
	{
		SearchItemInTree (item, root -> leftPtr);
	}
}

void ADTBST::SearchItem (int item)
{
	SearchItemInTree (item, m_Root);
}

ADTBST::~ADTBST()
{
	DeAllocateBST (m_Root);
}


