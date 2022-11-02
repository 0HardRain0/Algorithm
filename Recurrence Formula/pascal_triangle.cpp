#include <iostream>
#define N 12

long combi(int, int);

void main()
{
	int n, r, t;

	for (n = 0; n <= N; n++) {
		for (t = 0; t < (N - n) * 3; t++)
			std::cout << " ";
		for (r = 0; r <= n; r++)
			std::printf("%3ld   ", combi(n, r));
		std::cout << std::endl;
	}
}

long combi(int n, int r)
{
	int i;
	long p = 1;

	for (i = 1; i <= r; i++)
		p = p * (n - i + 1) / i;
	return p;
}