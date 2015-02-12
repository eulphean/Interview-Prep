/*
	Program to implement breadth first search
*/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {

	int number;
	TreeNode *left;
	TreeNode *right;
};

void insertItem (TreeNode *&root, int num); 
void printTree (TreeNode * root);
void deleteTree (TreeNode *& root);
void bfs (TreeNode * root); 

int main () {
	
	int array [] = {-1, 0, -5, 10, 15, 16, 25, 3, 2, -10, 11, 106};
	TreeNode * root = NULL;
	
	for (int i = 0; i < 12; i++){
		insertItem (root, array[i]);
	}
	cout << "\nPrinting the tree in Breadth Wise order\n";
	bfs (root);

	
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

// Function to print the tree breadth wise
void bfs (TreeNode * root){
	
	queue <TreeNode *> myQ;
	myQ.push(root);
	
	while (!myQ.empty()){
	
		TreeNode * node = myQ.front();
		myQ.pop();
		cout << node -> number << " ";
		if (node->left) myQ.push(node->left);
		if (node->right) myQ.push(node->right);
	}
	
}