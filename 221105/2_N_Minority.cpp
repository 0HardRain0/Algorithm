#include<iostream>
#include<math.h>

#define NUM 1000

void main()
{
	int prime[NUM / 2 + 1];
	int i, n, m = 0, Limit;

	for (n = 2; n <= NUM; n++) {
		Limit = (int)sqrt((double)n);
		for (i = Limit; i > 1; i--) {
			if (n % i == 0)
				break;
		}
		if (i == 1)
			prime[m++] = n;
	}

	std::printf("\n Minority\n");
	for (i = 0; i < m; i++)
		std::printf("%5d", prime[i]);
	std::printf("\n");
}