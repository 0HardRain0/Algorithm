#include <iostream>

long combi(int, int);

int main()
{
	int n, r;
	for (n = 0; n <= 5; n++) {
		for(r=0;r<=n;r++)
			std::printf("%dC%d=%ld  ",n,r,combi(n,r)); //std::printf = printf()
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