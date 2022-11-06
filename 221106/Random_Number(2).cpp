#include<iostream>

#define N 1000
#define M 10
#define F (N/M)
#define SCALE (40.0/F)

unsigned rndnum = 13;

unsigned irnd();
double rnd();

void main()
{
	int i, j, rank, hist[M + 1];
	double e = 0.0;

	for (i = 1; i <= M; i++)
		hist[i] = 0;

	for (i = 0; i < N; i++) {
		rank = (int)(M * rnd() + 1);
		hist[rank]++;
	}

	for (i = 1; i <= M; i++) {
		printf("%3d:%3d ", i, hist[i]);
		for (j = 0; j < hist[i] * SCALE; j++)
			printf("*");
		printf("\n");

		e = e + (double)(hist[i] - F) * (hist[i] - F) / F;
	}
	printf("X 2=%f\n", e);
}

unsigned irnd()
{
	rndnum = (rndnum * 109 + 1021) % 32768;
	return rndnum;
	
	//rndnum = (rndnum * 214013 + 2531011 % 2147483648);
	//return rndnum / 65536;
	//C++ ·£´ıÇÔ¼ö
}

double rnd()
{
	return irnd() / 32767.1;
}