#include<iostream>

#define Node 4
#define Root 6
#define Start 1

int a[Node + 1][Node + 1] = { {0,0,0,0,0},
							  {0,0,1,0,0},
							  {0,0,0,1,1},
							  {0,0,0,0,1},
							  {0,1,1,0,0} };

int success, v[Root + 1], n;

void visit(int);

int main()
{
	success = 0; n = Root;
	visit(Start);
	if (success = 0)
		std::cout << "No Answer\n";
}

void visit(int i)
{
	int j;
	v[n] = i;
	if (n == 0 && i == Start) {
		std::cout << "Answer " << ++success << ":";
		for (i = 0; i <= Root; i++)
			std::cout << v[i];
		std::cout << "\n";
	}
	else {
		for (j = 1; j <= Node; j++) 
			if (a[i][j] != 0) {
				a[i][j]--;
				n--;
				visit(j);
				a[i][j]++;
				n++;
			}
	}
}