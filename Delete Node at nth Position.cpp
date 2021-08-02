#include <stdlib.h>
#include <stdio.h>
#include <iostream>


struct Node
{
	int data;
	struct Node* next;

};
struct Node* head;//global

void Insert(int data) // insert an integer at end of list
{
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = head;
	head = temp;
}

void Print() // print all elements in the list
{
	Node* temp = head;
	while (temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n\n");
}

void Delete(int n) // Delete node at position n
{
	struct Node* temp1 = head;
	if (n == 1)
	{
		head = temp1->next; //head now points to second node
		free(temp1);
		return;
	}
	int i;
	for (i = 0;i < n - 2; i++)
	{
		temp1 = temp1->next;
		// temp1 points to (n-1)th Node
	}
	struct Node* temp2 = temp1->next; // nth Node
	temp1->next = temp2->next; //  (n+1)th Node
	free(temp2); //delete temp2;

}

int main()
{
	head = NULL; // create empty list
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5); // List : 2,4,6,5
	Print();

	int n;
	printf("Enter a position: ");
	scanf_s("%d", &n);
	Delete(n); //delete position written by user
	Print(); //print new list
	
	main();

}