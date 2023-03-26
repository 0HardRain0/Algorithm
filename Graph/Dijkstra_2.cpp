//최단경로 루트 표시

#include<iostream>

#define N 8
#define M 9999

int a[N + 1][N + 1] = { {0,0,0,0,0,0,0,0,0},
						{0,0,1,7,2,M,M,M,M},
						{0,1,0,M,M,2,4,M,M},
						{0,7,M,0,M,M,2,3,M},
						{0,2,M,M,0,M,M,5,M},
						{0,M,2,M,M,0,1,M,M},
						{0,M,4,2,M,1,0,M,6},
						{0,M,M,3,5,M,M,0,2},
						{0,M,M,M,M,M,6,2,0} };

int main()
{
	int j, k, p, start, min,
		leng[N + 1],
		v[N + 1],
		index[N + 1];

	std::cout << "Start "; std::cin >> start;
	for (k = 1; k <= N; k++) {
		leng[k] = M; v[k] = 0;
	}

	leng[start] = 0;
	index[start] = 0;

	for (j = 1; j <= N; j++) {
		min = M;
		for (k = 1; k <= N; k++) {
			if (v[k] == 0 && leng[k] < min) {
				p = k; min = leng[k];
			}
		}

		v[p] = 1;

		if (min == M) {
			std::cout << "No connect Graph\n";
			exit(1);
		}

		for (k = 1; k <= N; k++) {
			if ((leng[p] + a[p][k]) < leng[k]) {
				leng[k] = leng[p] + a[p][k];
				index[k] = p;
			}
		}
	}
	for (j = 1; j <= N; j++) {
		printf("%3d : %d", leng[j], j); //자릿수 지정을 위해 printf사용
		p = j;
		while (index[p] != 0) {
			std::cout << " <-- " << index[p];
			p = index[p];
		}
		std::cout << "\n";
	}
}