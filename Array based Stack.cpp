#include <stdio.h>
#include <iostream>
#define MAX_SIZE 101 //max size is 101

int A[MAX_SIZE];
int top = -1; // top = -1 means empty stack

void Push(int x)
{
	if (top == MAX_SIZE - 1) // overflow
	{
		printf("Error: stack overflow.\n");
		return;
	}
	A[++top] = x;
}

void Pop()
{
	if (top == -1) // empty list
	{
		printf("Error: No element to pop.\n");
		return;
	}
	top--;
}

int Top()
{
	std::cout<<"The stack top is: "<<A[top]<<std::endl;
	return A[top];
}

void Print()
{
	int i;
	printf("Stack: ");
	for (i = 0;i <= top; i++)
	{
		printf("%d", A[i]);
	}
	printf("\n");
}

int main()
{
	Push(1); Print();
	Push(2); Print();
	Push(3); Print();
	Push(5); Print();
	Pop(); Print();
	Push(4); Print();
	Top();
}