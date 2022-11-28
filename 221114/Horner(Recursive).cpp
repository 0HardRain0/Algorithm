#include<iostream>
using namespace std;

#define N 4
double fn(double, double*, int);

void main()
{
	double a[] = { 1,2,3,4,5 };

	cout << fn(2, a, N) << endl;
}

double fn(double x, double a[], int i)
{
	if (i == 0)
		return a[N];
	else
		return fn(x, a, i - 1) * x + a[N - i];
}