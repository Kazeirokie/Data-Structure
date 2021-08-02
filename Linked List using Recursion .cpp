#include <stdlib.h>
#include <stdio.h>


struct Node
{
	int data;
	struct Node* next;
};


struct Node* Insert(Node* head, int data) // insert an integer at end of list
{
	Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		Node* temp1 = head; //temp1 address will be same to head
		while (temp1->next != NULL) temp1 = temp1->next; //temp1 address will change to next address
		temp1->next = temp;
	}
	return head;
}


void Print(struct Node* p) 
{
	if (p == NULL) return; // Exit condition // when address after that is 0/NULL
	printf("%d", p->data); // First print the value in the code
	Print(p->next); // Recursive call // looked data/value after p address
}


int main()
{
	struct Node* head = NULL; //local variable
	head = Insert(head,2);
	head = Insert(head,4); //refer back to Insert()
	head = Insert(head,6);
	head = Insert(head,2);
	Print(head);
}

// upside down printf & Print(p->next) to reverse 