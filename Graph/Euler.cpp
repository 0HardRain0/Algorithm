// Euler 한붓긋기

#include<iostream>

// Node 절점의 수, Root 변의 수, Start 시작점

#define Node 4    
#define Root 6
#define Start 1

int a[Node + 1][Node + 1] = { {0,0,0,0,0},
							  {0,0,1,0,1},
						      {0,1,0,1,2},
						  	  {0,0,1,0,1},
							  {0,1,2,1,0} };

int success, v[Root + 1], n;

void visit(int);

int main()
{
	success = 0; n = Root;
	visit(Start);
	if (success = 0)
		std::cout << "No answer\n";
}

void visit(int i)
{
	int j;

	v[n] = i;
	// 변의 수만 통과하고 되돌아 옴
	if (n == 0 && i == Start) {
		std::cout << "Answer " << ++success << ":";
		for (i = 0; i <= Root; i++)
			std::cout << v[i];
		std::cout << "\n";
	}
	else {
		for(j=1;j<=Node;j++)
			if (a[i][j] != 0) {
				a[i][j]--; a[j][i]--;
				n--;
				visit(j);
				a[i][j]++; a[j][i]++;
				n++;
			}
	}
}