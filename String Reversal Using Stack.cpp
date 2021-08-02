#include <iostream>
#include <stdio.h>
#include <stack> // stack from library
using namespace std;

/*class Stack // or just use stack from library
{
private:
	char A[101];
	int top;
public:
	void Push(int x);
	void Pop();
	int Top();
	bool IsEmpty;
};*/ 

void Reverse(char C[], int n) // n is number of character in string // C[] is an array
{
	stack<char> S; // create stack of character
	// loops for push
	for (int i = 0; i < n; i++)
	{
		S.push(C[i]);
	}
	// loop for pop
	for (int i = 0;i < n;i++)
	{
		C[i] = S.top(); // look for who at the top
		S.pop(); // perform pop
	}

}
int main()
{
	char C[51];
	printf("Enter a string: ");
	cin.getline(C, sizeof C);
	Reverse(C, strlen(C)); //strlen is string length
	printf("Output = %s",C);
}