// ¸¶¹æÁø


#include<iostream>

#define N 7

int main()
{
	int square[N + 1][N + 1], i, j, k;

	j = (N + 1) / 2; i = 0;
	for (k = 1; k <= N * N; k++) {
		if ((k % N) == 1)
			i++;
		else {
			i--; j++;
		}
		/*
		else {
		i = N - (N - i + 1) % N;
		j = j%N + 1;
		}
		*/
		if (i == 0)
			i = N;
		if (j > N)
			j = 1;
		square[i][j] = k;
	}
	std::cout << "        Odd Magic Square (N=" << N << ")\n";
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++)
			printf("%4d", square[i][j]);
		std::cout << "\n";
	}

	return 0;
}