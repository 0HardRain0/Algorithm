#include<iostream>

#define NUM 1000

double rnd();

void main()
{
	double x, y, pi;
	int i, in = 0;

	for (i = 0; i < NUM; i++) {
		x = rnd();
		y = rnd();
		if (x * x + y * y <= 1)
			in++;
	}
	pi = (double)4 * in / NUM;
	std::printf("¥ð=%f\n", pi);
}

double rnd()
{
	return (double)rand() / (RAND_MAX + 0.1);
}