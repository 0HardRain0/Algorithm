// 폐쇄로의 판정 포함

#include<iostream>

#define N 8

int a[N + 1][N + 1] = { {0,0,0,0,0,0,0,0,0},
						{0,0,0,1,0,0,0,0,0},
						{0,1,0,0,0,1,0,0,0},
						{0,0,0,0,1,0,0,1,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,1,0,1,0,0},
						{0,0,0,0,0,0,0,1,1},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,1,0} };

int v[N + 1],											// 방문 그래프
	s[N + 1];											// 정렬 결과 넣는용

void visit(int);

int main()
{
	int i;

	for (i = 1; i <= N; i++)
		v[i] = 0;

	for (i = 1; i <= N; i++)
		if (v[i] == 0)
			visit(i);

	for (i = N; i >= 1; i--)
		std::cout << s[i] << " ";
	std::cout << "\n";
}

void visit(int i)
{
	int j;

	static int sp = 1;				// 스택 포인트
	v[i] = 1;

	for (j = 1; j <= N; j++)
	{
		if (a[i][j] == 1 && v[j] == 0)
			visit(j);
		if (a[i][j] == 1 && v[j] == 1) {
			std::cout << "There are loops in the vicinity of " << i << " and " << j;
			exit(1);
		}
	}
	v[i] = 2;
	s[sp++] = i;
}