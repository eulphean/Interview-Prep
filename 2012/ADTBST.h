/*
	Header file for implementation of a Abstract Data Type around a Binary Search Tree.
	Search: O(logn) 
	Insert: O(logn)
	Delete: O(logn)
*/
#ifndef ADTBST_H
#define ADTBST_H

#include <iostream>
using namespace std;

struct TreeNode
{
	int item;
	TreeNode * leftPtr;
	TreeNode * rightPtr;
};

enum TraversalType
{
	PREORDER,
	INORDER,
	POSTORDER
}

class ADTBST
{
	TreeNode * m_Root;

	//void PreorderTraversal ();

	void InorderTraversal (TreeNode * root);

	//void PostorderTraversal ();

	void InsertItemBST (int item, TreeNode * root);

	void DeAllocateBST (TreeNode * root);

	public:
	
	// default constructor
	TreeNode ()
	{
		m_Root = NULL;
	}

	// Inserting an Item
	void InsertItem (int item);

	// Search an Item
	//int SearchItem (int item);

	// Print Tree
	void PrintTree ();

	~TreeNode();
};

#endif