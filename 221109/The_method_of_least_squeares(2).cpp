#include <iostream>
#include "glib.h"



//Nuget Pakage Manager => NuGet\Install-Package glib -Version 2.36.2.11
//Re install

#define N 7
#define M 5

#define Max(a,b) (((a)>(b))?(a):(b))

double ipow(double, int);

void main()
{
	double x[] = { -3,-2,-1,0,1,2,3 },
		   y[] = { 5,-2,-3,-1,1,4,5 },
	    	a[M + 1][M + 2], s[2 * M + 1], t[M + 1];

	int i, j, k;
	double p, d;

	for (i = 0; i <= 2 * M; i++)
		s[i] = 0;
	for (i = 0; i <= M; i++)
		t[i] = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j <= 2 * M; j++)
			s[j] = s[j] + ipow(x[i], j);
		for (j = 0; j <= M; j++)
			t[j] = t[j] + ipow(x[i], j) * y[i];
	}

	for (i = 0; i <= M; i++) {
		for (j = 0; j <= M; j++)
			a[i][j] = s[i + j];
		a[i][M + 1] = t[i];
	}

	for (k = 0; k <= M; k++) {
		p = a[k][k];
		for (j = k; j <= M + 1; j++)
			a[k][j] = a[k][j] / p;
		for (i = 0; i <= M; i++) {
			if (i != k) {
				d = a[i][k];
				for (j = k; j <= M + 1; j++)
					a[i][j] = a[i][j] - d * a[k][j];
			}
		}
	}

	for (k = 0; k <= M; k++)
		printf("a%d=%f\n", k, a[k][M + 1]);

	double px, py, xmax, ymax, xmin, ymin, sx, sy, dx, dy, step;

	ginit();
	xmax = xmin = x[0]; ymax = ymin = y[0];
	for (i = 1; i < N; i++) {
		if (x[i] < xmin) xmin = x[i];
		if (y[i] < ymin) ymin = y[i];
		if (x[i] > xmax) xmax = x[i];
		if (y[i] > ymax) ymax = y[i];
	}
	sx = 1.2 * Max(fabs(xmin),fabs(xmax));
	sy = 1.2 * Max(fabs(ymin), fabs(ymax));
	dx = sx / 100; dy = sy / 100;
	step = (xmax - xmin) / 100;

	window(-sx, -sy, sx, sy);

	line(-sx, 0, sx, 0); line(0, -sy, 0, sy);

	for (i = 0; i < N; i++) {
		line(x[i] - dx, y[i], x[i] + dx, y[i]);
		line(x[i], y[i] - dy, x[i], y[i] + dy);
	}

	for (px = xmin; px <= xmax; px = px + step) {
		py = 0;
		for (i = 0; i <= M; i++)
			py = py + a[i][M + 1] * ipow(px,i);
		if (px == xmin)
			setpoint(px, py);
		else
			moveto(px, py);
	}
}

double ipow(double p, int n)
{
	int k;
	double s = 1;
	for (k = 1; k <= n; k++)
		s = s * p;

	return s;
}
