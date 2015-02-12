/*
	Program to make a binary tree with the shortest height using a sorted array
*/

#include <iostream>

using namespace std;

struct TreeNode {

	int number;
	TreeNode *left;
	TreeNode *right;
};

void insertionSort (int Array []);
void deleteTree (TreeNode *& root);
void insertItem (TreeNode *& root, int item);
void printTree (TreeNode * root);
void makeBalancedTree (TreeNode *& root, int Array [], int begin, int);

int main () {

	int array [] = {-1, 0, -5, 10, 20, 21, 22};
	
	insertionSort (array);

	TreeNode * root = NULL;
	
	makeBalancedTree (root, array, 0, 6);
	
	printTree (root);
	
	deleteTree (root);
}

void insertionSort (int array[]){
	
	/*
		- Partition the sorted (1st Element) and unsorted (1...n) region
		- Apply bubble sort in the region from sorted to unsorted or do shifting adjacent items on the 
		sorted side
	*/
	
	int n = 10;
	
	for (int unsorted = 1; unsorted < n; ++unsorted){
		int item = array [unsorted];
		
		for (int location = unsorted; location > 0; --location){
			if (array[location-1] > array[location]){
				array[location] = array[location - 1];
				array[location - 1] = item;
			}	
		}
	} 
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

void makeBalancedTree (TreeNode *& root, int array [], int begin, int end){
	
	
}