// 4N¸¶¹æ(n=4,8,12,16,...)

#include<iostream>

#define N 8

int main()
{
	int square[N + 1][N + 1], i, j;

	for (j = 1; j <= N; j++) {
		for (i = 1; i <= N; i++) {
			if ((j % 4 == i % 4) || (j % 4 + i % 4) % 4 == 1)
				square[i][j] = (N + 1 - i) * N - j + 1;
			else
				square[i][j] = (i - 1) * N + j;
		}
	}

	std::cout << "      4N Magic Square (N=" << N << ")\n";
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++)
			printf("%4d", square[i][j]);
		std::cout << "\n";
	}

	return 0;
}
