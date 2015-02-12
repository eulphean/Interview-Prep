/*
	If a binary tree is balanced or not
*/
#include <iostream>
#include <cmath>

#define efficient 1

using namespace std;

struct TreeNode {

	int number;
	TreeNode *left;
	TreeNode *right;
};

void insertItem (TreeNode *&root, int num); 
void printTree (TreeNode * root);
void deleteTree (TreeNode *& root); 
bool ifBalanced (TreeNode * root);
int heightTree (TreeNode * root);
int efficientCheckHeight (TreeNode * root);
bool ifnewBalanced (TreeNode * root);

int main () {

	int array [] = {-1, 0, -5, 10, 15, 16, 25, 3, 2, -10, 11, 106};
	int array2[] = {10, 5, 8, 3, 12, 11, 14};
	int array3[] = {10, 5, 11};
	TreeNode * root = NULL;
	
	for (int i = 0; i < 7;i++){
		insertItem (root, array2[i]);
	}
	printTree (root);
	#if (efficient == 0)
	bool flag = ifBalanced (root);
	#else 
	bool flag = ifnewBalanced (root);
	#endif
	cout << "\n Balanced Status is "<< flag << "\n";
	
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
/*
	A solution with O (n^2) efficiency as at each node, even though the subtrees are called,
	heightTree is calculated again on the nodes of those subtrees. So, in the worst case scenario, every
	node is visited twice by the function and it's O(n^2) efficiency. 
*/

bool ifBalanced (TreeNode * root){

	// Basis Step
	if (root == NULL) return true;
	
	int diffInHeight = heightTree (root->left) - heightTree (root->right);
	
	/*
		Don't go into that subtree if that two subtrees are not balanced.
		Somewhat like pruning as well.
	*/
	if (abs(diffInHeight)>1) return false;
	
	else{
		// Recursive Step
		bool flag1 = ifBalanced (root->left);
		bool flag2 = ifBalanced (root->right);
		
		// Recomposition Step 
		return (flag1&&flag2);
	}
}

int heightTree (TreeNode * root){
	
	// Basis Step
	if (root == NULL)
		return true;
		
	
	// Recursive Step
	int num1 = heightTree (root->left);
	int num2 = heightTree (root->right);
	
	// Recomposition Step 
	if (num1 > num2)
		return (num1+1);
	else 
		return (num2+1);
}

/*
	An efficient solution in which each node is visited just once O(n^2)
	When height is calculated, find if the tree is balanced or not. As soon 
	the absolute difference between heights i > 1, break out of it
*/
int efficientCheckHeight (TreeNode * root){

	// Base Case
	if (root == NULL) return 0;
	
	// Recursive + Base Case
	int hleft = efficientCheckHeight (root->left);
	if (hleft == -1) return -1;
	int hright = efficientCheckHeight (root->right);
	if (hright == -1) return -1;
	
	// Recomposition
	int hdiff = hleft - hright;
	if (abs (hdiff) > 1) return -1;
	else {
		if (hright>hleft) return (hright+1);
		else return (hleft+1);
	}
}

bool ifnewBalanced (TreeNode * root){

	if (efficientCheckHeight (root)==-1)
		return false;
	else return true;
	
}