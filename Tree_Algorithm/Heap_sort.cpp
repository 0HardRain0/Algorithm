//Heap_Sort

#include<iostream>

void swap(int*, int*);

int main()
{
	int heap[100];
	int n, i, s, p, m;

	n = 1;
	while (scanf_s("%d", &heap[n]) != EOF) {
		s = n; p = s / 2;
		while (s >= 2 && heap[p] > heap[s]) {
			swap(&heap[p], &heap[s]);
			s = p; p = s / 2;
		}
		n++;
	}

	// 스왑 부분
	m = n - 1;
	while (m > 1) {
		swap(&heap[1], &heap[m]);
		m--;

		p = 1; s = 2 * p;
		while (s <= m) {
			if (s < m && heap[s + 1] < heap[s])
				s++;
			if (heap[p] <= heap[s])
				break;
			swap(&heap[p], &heap[s]);
			p = s; s = 2 * p;
		}
	}
	for (i = 1; i < n; i++)
		std::cout << " " << heap[i];
	std::cout << "\n";
}

void swap(int* a, int* b)
{
	int w;
	w = *a; *a = *b; *b = w;
}