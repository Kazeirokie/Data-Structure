#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node* head;

void Reverse(struct Node* p)
{
	if (p->next == NULL) // list dh sampai hujung
	{
		head = p;
		return;
	}
	Reverse(p->next); // change address 
	struct Node* q = p->next;
	q->next = p;
	p->next = NULL;
	printf("%d", p->data); // First print the value in the code
	
}

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

void Print() {
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	struct Node* head = NULL; //local variable
	Insert(head, 2); Print();
	Insert(head, 4); Print();
	Insert(head, 6); Print();
	Insert(head, 2); Print();
	Reverse(head); // broken
	
}

// Broken