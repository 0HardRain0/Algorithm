#include<iostream>
using namespace std;

void hanoi(int, char, char);
#define Total 'a'+'b'+'c'

void main()
{
	int n;
	cout << "The number of disks? ";
	cin >> n;

	hanoi(n, 'a', 'b');
}

void hanoi(int n, char a, char b)
{
	if (n > 0)
	{
		hanoi(n - 1, a, Total - (a + b));
		cout << "Move the " << n << " disk from " << a << " to " << b << endl;
		hanoi(n - 1, Total - (a + b), b);
	}
}