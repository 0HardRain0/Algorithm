#include<iostream>
using namespace std;

int gcd(int, int);

void main()
{
	int a, b;

	cout << "Please enter 2 intergers";
	cin >> a >> b;

	cout << "GCD = " << gcd(a, b) << endl;
}

int gcd(int m, int n)
{
	if (n == 0)
		return m;
	else
		return gcd(n, m % n);
}