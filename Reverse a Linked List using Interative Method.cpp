#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node* next; //store address of the next node
};

struct Node* Reverse(struct Node* head)
{
	struct Node *current, *prev, *next;
	current = head; //current address will be same like head address
	prev = NULL; //address before head is NULL
	while (current != NULL)
	{
		next = current->next;
		current->next = prev; //change the next address to previous address
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}


Node* Insert(Node* head, int data) // insert an integer at end of list
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


void Print(Node* head) // print all elements in the list
{
	while (head != NULL)
	{
		printf("%d", head->data);
		head = head->next;;
	}
	printf("\n\n");
}


int main()
{
	struct Node* head = NULL;
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 8);
	Print(head);

	head = Reverse(head);
	Print(head);
	
}