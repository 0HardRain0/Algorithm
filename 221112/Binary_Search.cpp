#include<iostream>
using namespace std;
#define N 10

void main()
{
	int a[] = {2,3,7,11,31,50,55,70,77,80 };
	int key, low, high, mid, flag = 0;

	cout << "Searching Data? "; cin >> key;
	low = 0; high = N - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (a[mid] == key) {
			cout << a[mid] << " is in the " << mid << "th place\n";
			flag = 1;
			break;
		}
		if (a[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (flag != 1)
		cout << "No searching Data\n";

	
}