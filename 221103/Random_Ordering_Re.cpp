#include<iostream>

#define N 20

int irnd(int);

int main()
{
	int i, j, d, a[N + 1];

	for (i = 1; i <= N; i++)
		a[i] = i;

	for (i = N; i > 1; i--)
	{
		j = irnd(i - 1);
		d = a[i]; a[i] = a[j]; a[j] = d;
	}

	for (i = 1; i <= N; i++)
		std::printf("%d ", a[i]);

	std::cout << std::endl;
	
}

int irnd(int n)
{
	return (int)(rand() / (RAND_MAX + 0.1) * n + 1);
}