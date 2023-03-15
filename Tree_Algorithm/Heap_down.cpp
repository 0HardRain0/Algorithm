//Heap shiftdown

#include<iostream>

void swap(int*, int*);

int main()
{
	int heap[100];
	int i, n, p, s, m;

	n = 1;
	while (scanf_s("%d", &heap[n]) != EOF)
		n++;
	m = n - 1;
	for (i = m / 2; i >= 1; i--) {
		p = i;
		s = 2 * p;
		while (s <= m) {
			if (s < m && heap[s + 1] < heap[s])
				s++;
			if (heap[p] <= heap[s])
				break;
			swap(&heap[p], &heap[s]);
			p = s; s = 2 * p;
		}
	}
	for (i = 1; i <= m; i++)
		printf("%d ", heap[i]);
	std::cout << "\n";
}

// 스왑시키는 함수
void swap(int* a, int* b)
{
	int w;
	w = *a; *a = *b; *b = w;
}