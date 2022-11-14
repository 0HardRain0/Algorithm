#include<iostream>
using namespace std;

#define N 10

void main()
{
	int  a[] = { 2,3,7,11,31,50,55,70,77,80 };
	int key, low, high, mid;

	cout << "Searching Data? "; cin >> key;

	low = 0; high = N - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (a[mid] <= key)
			low = mid + 1;
		if (a[mid] >= key)
			high = mid - 1;
	}
	if (low == high + 2)
		cout << a[mid] << " is in the " << mid << "th place";
	else
		cout << "No Searching Data\n";
}