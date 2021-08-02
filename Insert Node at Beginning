#include <stdlib.h>
#include <stdio.h>

// Create Node
struct Node {
	int data;
	struct Node* next;
};

struct Node* head;//global variable, can be accessed anywhere

void Insert(int x)
{
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp -> data = x;
	temp -> next = head;
	head = temp;
}

void Print()
{
	struct Node* temp = head;
	printf("List is: ");
	while (temp != NULL)
	{
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	head = NULL; // Create empty list without address
	printf("How many numbers? \n");
	int n, i, x;  
	scanf_s("%d", &n); // n is the how many number you want in the list
	for (i = 0;i < n;i++)
	{
		printf("Enter the number: \n");
		scanf_s("%d", &x); // x is the number you want in the list
		Insert(x);
		Print();
	}

}
