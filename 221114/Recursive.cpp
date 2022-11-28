#include<iostream>
using namespace std;

long lift(int);

void main()
{
	int n;
	for (n = 0; n < 13; n++)
	{
		printf("%2d!= %10ld\n", n, lift(n));
	}
}

long lift(int n)
{
	if (n == 0)
		return 1L;
	else
		return n * lift(n - 1);
}