// ���� �켱 Ž�� -> ��� ���� ���������� Ž��

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
			i = queue[head++];									  // ť�κ��� ����
			for (j = 1; j <= N; j++) {
				if (a[i][j] == 1 && v[j] == 0) {
					std::cout << i << "->" << j << " ";
					queue[tail++] = j;                            // ť�� ����
					v[j] = 1;
				}
			}
		} while (head != tail);
		std::cout << "\n";
	}
}