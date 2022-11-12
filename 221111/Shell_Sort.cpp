#include<iostream>

#define N 100

void main()
{
	int a[N], i, j, t;

	for (i = 0; i < N; i++)
		a[i] = rand();

	for (i = 0; i < N; i++) {
		for (j = i - 1; j >= 0; j--) {
			if (a[j] > a[j + 1]) {
				t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
			}
			else
				break;
		}
		/*
		t = a[i];
		for (j = i - 1; j >= 0 && a[j] > t; j--)
			a[j + 1] = a[j];
		a[j + 1] = t;
		*/
	}
	for (i = 0; i < N; i++)
		printf("%8d", a[i]);
	printf("\n");
}