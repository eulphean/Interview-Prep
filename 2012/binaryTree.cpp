/*
	Program to add nodes to a Binary Tree. 
	Binary Tree - Empty tree or a tree with TL and TR as binary tree. A tree with just a root node 
	is also a binary tree. Or a tree with just a left or just a right node is also a binary tree
*/

#include <iostream>

using namespace std;

struct TreeNode {

	int number;
	TreeNode *left;
	TreeNode *right;
};

void insertItem (TreeNode *&root, int num); 
void printTree (TreeNode * root);
void deleteTree (TreeNode *& root);

int main () {
	
	TreeNode *root = NULL;
	int num;
	char ch;
	
	do {
		cout << "Enter an item in the tree ";
		cin >> num;
		insertItem (root, num);
		cout << "\nDo you want to enter more numbers? ";
		cin >> ch; 
		cout << "\n";
	} while (ch == 'y');
	
	cout << "\nPrinting the tree in ascending order";
	printTree (root);
	
	cout <<"\nDeleting the tree";
	deleteTree (root);
}
		
// Preorder insertion check
void insertItem (TreeNode *& root, int item){
	
	// Basis Case
	if (root == NULL){
		TreeNode *newPtr = new TreeNode;
		newPtr -> number = item;
		newPtr -> left = NULL;
		newPtr -> right = NULL;
		root = newPtr;
		return;
	}
	
	// Recursion Step
	if (item > root->number)
		insertItem (root->right, item);
	else 
		insertItem (root->left, item);
}

// Inorder printing in ascending order
void printTree (TreeNode * root){
		
	if (root == NULL){
		cout << "a";
		return;
	}
	printTree (root->left);
	cout << "\n" << root->number;
	printTree (root->right);
}

// Postorder insertion in the tree
void deleteTree (TreeNode *& root){

	if (root == NULL)
		return;
		
	deleteTree (root->left);
	deleteTree (root->right);
	delete root;
}