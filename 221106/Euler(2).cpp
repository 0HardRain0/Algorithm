#include<iostream>
#include<math.h>

double myexp(double);

void main()
{
	double x;
	printf("    x       myexp(x)       exp(x)\n");
	for (x = -40; x <= 40; x = x + 10)
		printf("%5.1f%14.6g%14.6g\n", x, myexp(x), exp(x));
}

double myexp(double x)
{
	double EPS = 1e-08;
	double s = 1.0, e = 1.0, d;
	int k;

	for (k = 1; k <= 200;k++) {
		d = s;
		e = e * x / k;
		s = s + e;
		if (fabs(s - d) < EPS * fabs(d))
			return s;
	}
	return 0.0;
}

// 한번더 하기