#include<iostream>
using namespace std;

#define MaxSize 100

int stack[MaxSize];
int sp = 0;
int push(int);
int pop(int*);

void main()
{
	int c, n;

	while (printf("]"), (c = getchar()) != EOF)
	{
		rewind(stdin);
		if (c == 'i' || c == 'I')
		{
			cout << "data--> ";
			cin >> n; rewind(stdin);
			if (push(n) == -1)
			{
				cout << "Stack is full\n";
			}
		}
		if (c == 'o' || c == '0')
		{
			if (pop(&n) == -1)
				cout << "Stack is empty\n";
			else
				cout << "Stack data --> " << n << endl;
		}
	}
}

int push(int n)
{
	if (sp < MaxSize)
	{
		stack[sp] = n;
		sp++;
		return 0;
	}
	else
		return -1;
}

int pop(int* n)
{
	if (sp > 0)
	{
		sp--;
		*n = stack[sp];
		return 0;
	}
	else
		return -1;
}