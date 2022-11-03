#include<iostream>

#define NUM 1000

double rnd();

void main() {
	double x, y, s;
	int i, in = 0;

	for (i = 0; i < NUM; i++)
	{
		x = 2 * rnd();
		y = rnd();
		if (x * x / 4 + y * y <= 1)
			in++;
	}
	s = 4.0 * (2.0 * in / NUM);
	std::printf("Area of ellipse = %f\n", s);
}

double rnd()
{
	return (double)rand() / (RAND_MAX + 0.1);
}