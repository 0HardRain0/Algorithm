#include<iostream>
using namespace std;

int gcd(int, int);
//GCD(Greatest common divisor) = 최대공약수, 最大公約数

void main()
{
	int a, b;

	cout << "Please enter 2 intergers ";
	cin >> a >> b;
	

	cout << "GCD=" << gcd(a, b) << endl;
}

int gcd(int m, int n)
{
	if (m == n)
		return m;
	if (m > n)
		return gcd(m - n, n);
	else
		return gcd(m, n - m);
}