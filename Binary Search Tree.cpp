// Binary Search Tree - Implementation in C++
#include<iostream>
using namespace std;

// Create Binary Search Tree Node
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
	else if (data <= root->data) 
	{
		root->left = Insert(root->left, data); // If data less than root..to LEFT
	}
	else
	{
		root->right = Insert(root->right, data); // Bigger..to RIGHT
	}
	return root;
}

// Search the data in tree
bool Search(BstNode* root, int data)
{
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data <= root->data)return Search(root->left, data);
	else return Search(root->right, data);
}

int main()
{
	BstNode* root; // pointer to root node
	root = NULL;   // setting empty tree
	root = Insert(root,15); root = Insert(root, 30);
	root = Insert(root,20); root = Insert(root, 35);
	root = Insert(root,25); root = Insert(root, 40);
	int number;
	cout << "Search a number: \n";
	cin >> number;
	if (Search(root, number) == true)
	{
		cout << "FOUND\n\n";
	}
	else cout << "NOT FOUND\n\n";
	main();
}
//"newNode" will be created everytime new data "Insert"ed
