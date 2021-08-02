#include<iostream>
using namespace std;

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

// New Node created everytime data full (right & left)
BstNode* GetNewNode(int data)
{
	// Will execute new address without data
	BstNode* newNode = new BstNode(); // Same as using malloc 
	// different method same output
	(*newNode).data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// Insert new number in Node
BstNode* Insert(BstNode* root, int data)
{
	if (root == NULL) // empty tree
	{
		root = GetNewNode(data); // Put data in the newNode
	}
	else if (data <= root->data) // If data less than root..to LEFT
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data); // Bigger..to RIGHT
	}
	return root;
}

int height(struct BstNode* root)
{
	// Leaf node(Node without children) will be -1
	if (root == NULL) return -1;
	
	else 
	{
		int left = height(root->left);   // Left subtree
		int right = height(root->right); // Right subtree

		int height = (left < right) ? right + 1 : left + 1; // Condition
		return height;
	}
}

int main()
{
	BstNode* root; // pointer to root node
	root = NULL;   // setting empty tree
	root = Insert(root, 5); root = Insert(root, 10);
	root = Insert(root, 3); root = Insert(root, 4);
	root = Insert(root, 1); root = Insert(root, 11);
	cout<<"Binary Tree height is: " << height(root) << endl;
}
/* Height will be 2
 // Height count in binary tree start after the Node

              5
             / \
		    3   10
		   / \    \
		  1   4   11

 */