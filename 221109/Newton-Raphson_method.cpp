#include<iostream>
#include<math.h>

#define f(x) ((x)*(x)*(x)-(x)+1)
#define g(x) (3*(x)*(x)-1)
#define EPS 1e-8
#define LIMIT 50

void main()
{
	double x = -2.0, dx;
	int k;

	for (k = 1; k <= LIMIT; k++)
	{
		dx = x;
		x = x - f(x) / g(x);
		if (fabs(x - dx) < fabs(dx) * EPS) {
			printf("x=%f\n", x);
			break;
		}
		if (k > LIMIT)
			printf("Not converging\n");
	}
}