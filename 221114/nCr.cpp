#include<iostream>
using namespace std;

long combi(int, int);

void main()
{
	int n, r;

	for (n = 0; n <= 5; n++)
	{
		for (r = 0; r <= n; r++)
			printf("%d C %d=%ld  ", n, r, combi(n, r));
		cout << endl;
	}
}

long combi(int n, int r)
{
	if (r == 0 || r == n)
		return 1L;
	else
		return combi(n - 1, r) + combi(n - 1, r - 1);
}