//Heap

#include<iostream>

int main()
{
	int heap[100];
	int i, n, s, p, w;

	n = 1;
	while (scanf_s("%d", &heap[n]) != EOF) {
		s = n;
		p = s / 2;
		while (s >= 2 && heap[p] > heap[s]) {
			w = heap[p]; heap[p] = heap[s]; heap[s] = w;
			s = p; p = s / 2;
		}
		n++;
	}
	for (i = 1; i < n; i++)
		std::cout << " " << heap[i];
	std::cout << "\n";
}