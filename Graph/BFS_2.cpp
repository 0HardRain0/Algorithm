// 넓이 우선 탐색 -> 모든 점을 시점으로한 탐색

#include<iostream>

#define N 8

int a[N + 1][N + 1] = { {0,0,0,0,0,0,0,0,0},
						{0,0,1,1,0,0,0,0,0},
						{0,1,0,1,1,1,0,0,0},
						{0,0,1,0,0,0,0,1,0},
						{0,0,1,0,0,0,0,0,0},
						{0,0,1,0,0,0,1,0,0},
						{0,0,0,0,0,1,0,1,1},
						{0,0,0,1,0,0,1,0,1},
						{0,0,0,0,0,0,1,1,0} };


int v[N + 1];
int queue[100];
int head, tail;

int main()
{
	int i, j, p;

	for (p = 1; p <= N; p++) {
		for (i = 1; i <= N; i++)
			v[i] = 0;
		head = tail = 0;
		queue[tail++] = p; v[p] = 1;
		do {
			i = queue[head++];									  // 큐로부터 추출
			for (j = 1; j <= N; j++) {
				if (a[i][j] == 1 && v[j] == 0) {
					std::cout << i << "->" << j << " ";
					queue[tail++] = j;                            // 큐에 넣음
					v[j] = 1;
				}
			}
		} while (head != tail);
		std::cout << "\n";
	}
}