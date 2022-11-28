#include<iostream>
using namespace std;

long lift(int);

void main()
{
	int n;
	for (n = 0; n < 13; n++)
		printf("%2d!= %10ld\n", n, lift(n));
}

long lift(int n)
{
	int k;
	long p = 1L;

	for (k = n; k >= 1; k--)
		p = p * k;
	return p;
}