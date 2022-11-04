#include<iostream>

void main()
{
	int a, b, m, n, k;

	std::printf("Enter two interfgers ");
	std::cin >> a;
	std::cin >> b;

	m = a; n = b;
	do {
		k = m % n;
		m = n; n = k;
	} while (k != 0);
	std::printf("GCD = %d\n", m); // GCD = The Greatest common denominator
}