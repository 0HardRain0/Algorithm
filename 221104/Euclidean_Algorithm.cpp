#include<iostream>

void main()
{
	int a, b, m, n;

	std::printf("Enter two interfgers ");
	std::cin >> a;
	std::cin >> b;

	m = a; n = b;
	while (m!= n) {
		if (m > n)
			m = m - n;
		else
			n = n - m;
	}
	std::printf("GCD = %d\n", m);
}