#include<iostream>

void main()
{
	int a, n;

	while (std::printf("Number ? "), std::scanf("%d", &n) != EOF) {
		a = 2;
		while (n >= a * a) {
			if (n % a == 0) {
				std::printf("%d*", a);
				n = n / a;
			}
			else
				a++;
		}
		std::printf("%d\n", n);
	}
}