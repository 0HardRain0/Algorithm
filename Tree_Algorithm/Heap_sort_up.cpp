// heap up sort

#include<iostream>

void swap(int*, int*);
void shiftdown(int, int, int[]);

int main()
{
	int heap[100];
	int i, n, m;

	n = 1;
	while (scanf_s("%d", &heap[n]) != EOF)
		n++;
	m = n - 1;
	for (i = m / 2; i >= 1; i--)
		shiftdown(i, m, heap);
	while (m > 1) {
		swap(&heap[1], &heap[m]);
		m--;
		shiftdown(1, m, heap);
	}
	for (i = 1; i < n; i++)
		std::cout << heap[i] << " ";
	std::cout << "\n";
}

void shiftdown(int p, int n, int heap[])
{
	int s;
	s = 2 * p;
	while (s <= n) {
		if (s<n && heap[s + 1]>heap[s])
			s++;
		if (heap[p] >= heap[s])
			break;
		swap(&heap[p], &heap[s]);
		p = s; s = 2 * p;
	}
}

void swap(int* a, int* b)
{
	int w;
	w = *a; *a = *b; *b = w;
}