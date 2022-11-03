#include<iostream>
#define Num 10

int main()
{
	int a[] = { 56,25,67,88,100,61,55,67,76,56 };
	int juni[Num];
	int i, j;

	for (i = 0; i < Num; i++)
	{
		juni[i] = 1;
		for (j = 0; j < Num; j++) {
			if (a[j] > a[i])
			juni[i]++;
		}
		
	}

	std::printf("   Score  Ranking\n");
	for (i = 0; i < Num; i++) {
		std::printf("%6d%6d\n", a[i], juni[i]);
	}
}