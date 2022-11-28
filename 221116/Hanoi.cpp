#include<iostream>
using namespace std;

void hanoi(int, char, char, char);

void main()
{
	int n;
	cout << "The number of disks? ";
	cin >> n;

	hanoi(n, 'a', 'b', 'c');
}

void hanoi(int n, char a, char b, char c)
{
	if (n > 0) {
		hanoi(n - 1, a, c, b);
		cout << "Move the " << n << " disk from " << a << " to " << b << endl;
		hanoi(n - 1, c, b, a);
	}
}