#include<iostream>
using namespace std;

void quick(int*, int, int);

#define N 10

void main()
{
	static int a[] = { 41,24,76,11,45,64,21,69,19,36 };
	int k;

	quick(a, 0, N - 1);

	for (k = 0; k < N; k++)
		printf("%4d", a[k]);
	cout << endl;
}

void quick(int a[], int left, int right)
{
	int s, t, i, j;

	if (left < right) {
		s = a[left];                //좌측항을 축으로 함
		i = left; j = right + 1;    //축보다 작은 그룹과 큰 그룹으로 나눔
		while (1) {
			while (a[++i] < s);
			while (a[--j] > s);
			if (i >= j) break;
			t = a[i]; a[i] = a[j]; a[j] = t;
		}
		a[left] = a[j]; a[j] = s; //축을 정확한 위치에 넣음

		quick(a, left, j - 1);   // 왼쪽 부분 열에 대한 재귀 호출
		quick(a, j + 1, right);  // 오른쪽 부분 열에 대한 재귀 호출
	}
}