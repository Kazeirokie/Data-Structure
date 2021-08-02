// Lesser data must in LEFT
// Bigger data must in RIGHT
/* C++ program to find Inorder successor in a BST */
#include<iostream>
using namespace std;

// Create empty node
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

bool IsBST(Node* root, int minValue, int maxValue)
{
	if (root == NULL) return true;
	if (root->data < minValue && root->data > maxValue && IsBST(root->left, minValue, root->data) && IsBST(root->right, root->data, maxValue))
		return true;
	else return false;
}

/*
 //How it works? (minValue,maxValue)

                5 (-inf,+inf)
			   / \ 
	 (-inf,5) 3   10 (5,+inf)
			 / \   \
   (-inf,3) 1   4   11 (10,+inf)

   // maxValue for RIGHT subtree don't change
   // minValue for LEFT  subtree don't change

*/

bool IsBinarySearchTree(Node* root)
{
	std::cout << "This is a Binary Search Tree." << std::endl;
	return IsBST(root, INT_MIN, INT_MAX); // To call IsBST function
}

// Function to Insert Node in a Binary Search Tree
Node* Insert(Node* root, char data) {
	if (root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}

int main() {
	/*Code To Test the logic
	  Creating an example tree
				5
			   / \
			  3   10
			 / \   \
			1   4   11
	*/
	Node* root = NULL;
	root = Insert(root, 5); root = Insert(root, 10);
	root = Insert(root, 3); root = Insert(root, 4);
	root = Insert(root, 1); root = Insert(root, 11);

	IsBinarySearchTree(root);
	
}