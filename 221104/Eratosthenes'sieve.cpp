#include<iostream>
#include<cmath> // math.h


void main()
{
	int i, n, Limit;

	while (std::printf("data? "), std::scanf("%d", &n) != EOF) {
		if (n >= 2) {
			Limit = (int)sqrt((double)n);
			for (i = Limit; i > 1; i--) {
				if (n % i == 0)
					break;
			}
			if (i == 1)
				std::cout << "Minority!" << std::endl;
			else
				std::cout << "Not Minority!" << std::endl;
		}
	}
}