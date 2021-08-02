#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data; // store node
	struct Node* next; // store address for next node
	struct Node* prev; // store address for prev node
};

struct Node* head; // pointer to head node // global variable

struct Node* GetNewNode(int x)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void InsertAtHead(int x)
{
	struct Node* newNode = GetNewNode(x); //local variable // different from newNode upside
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}	

void Print()
{
	struct Node* temp = head;
	printf("Forward: ");
	while (temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void ReversePrint()
{
	struct Node* temp = head;
	if (temp == NULL) return; // last node
	// Going to last node
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	// Moving backward using previous pointer
	printf("Reverse: ");
	while (temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main()
{
	head = NULL; // list is empty initially
	InsertAtHead(2); Print(); ReversePrint();
	InsertAtHead(4); Print(); ReversePrint();
	InsertAtHead(6); Print(); ReversePrint();
	InsertAtHead(8); Print(); ReversePrint();

}