#include<iostream>
using namespace std;

long fib(long);

void main()
{
	long n;
	for (n = 1; n <= 20; n++)
		printf("%3ld: %ld\n", n, fib(n));
}

long fib(long n)
{
	if (n == 1 || n == 2) {
		return 1L;
	}
	else
		return fib(n - 1) + fib(n - 2);

}