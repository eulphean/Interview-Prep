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
};

class ADTBST
{
	TreeNode * m_Root;

	void PreorderTraversal (TreeNode * root);

	void InorderTraversal (TreeNode * root);

	void PostorderTraversal (TreeNode * root);

	void InsertItemBST (int item, TreeNode *& root);

	void DeAllocateBST (TreeNode *& root);

	void SearchItemInTree (int item, TreeNode * root);

	public:
	
	// default constructor
	ADTBST ()
	{
		m_Root = NULL;
	}

	// Inserting an Item
	void InsertItem (int item);

	// Search an Item
	void SearchItem (int item);

	// Print Tree
	void PrintTree (TraversalType T);

	~ADTBST();
};

#endif