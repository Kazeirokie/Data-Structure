#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
	int data; // store data
	struct Node* link; // store address
};
struct Node* top = NULL; // same like head // the beginning of list

void Push(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
	temp->data;
	temp->link;
	top = temp;
}

void Pop()
{
	struct Node* temp;
	if (top == NULL) return; // if stack is empty it will return error
	temp = top;
	top = top->link;
	free(temp);
}


int main()
{

	Push(2);
	
}

//broken