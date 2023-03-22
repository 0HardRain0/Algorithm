// 연결되지 않은 그래프의 탐색

#include<iostream>

#define N 8

int a[N + 1][N + 1] = { {0,0,0,0,0,0,0,0,0},
						{0,0,1,1,0,0,0,0,0},
						{0,1,0,1,1,0,0,0,0},
						{0,1,1,0,0,1,0,0,0},
						{0,0,1,0,0,1,0,0,0},
						{0,0,0,1,1,0,0,0,0},
						{0,0,0,0,0,0,0,1,1},
						{0,0,0,0,0,0,1,0,1},
						{0,0,0,0,0,0,1,1,0} };

int v[N + 1];

void visit(int);

int main()
{
	int i, count = 1;

	for (i = 1; i <= N; i++)
		v[i] = 0;
	//for문을 두개로 나눈 이유? -> 그래프를 따로 존재하여 탐색
	for (i = 1; i <= N; i++) {
		if (v[i] != 1) {
			std::cout << count++ << " :"; visit(i);
			std::cout << "\n";
		}
	}
}

void visit(int i)
{
	int j;

	std::cout << i << " ";
	v[i] = 1;
	for (j = 1; j <= N; j++)
	{
		if (a[i][j] == 1 && v[j] == 0)
			visit(j);
	}
}