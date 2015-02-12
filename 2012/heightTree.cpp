/*
	Finding the binary tree height
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
int heightTree (TreeNode * root);

int main () {

	int array [] = {-1, 0, -5, 10, 15, 16, 25, 3, 2, -10, 11, 106};
	TreeNode * root = NULL;
	
	for (int i = 0; i < 12; i++){
		insertItem (root, array[i]);
	}
	printTree (root);
	int height = heightTree (root);
	cout << "\n Height of the tree is "<< height << "\n";
	
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
	root = NULL;
}

int heightTree (TreeNode * root){
	
	// Basis Step
	if (root == NULL)
		return 0;
	
	// Recursive Step
	int num1 = heightTree (root->left);
	int num2 = heightTree (root->right);
	
	// Recomposition Step 
	if (num1 > num2)
		return (num1+1);
	else 
		return (num2+1);
}