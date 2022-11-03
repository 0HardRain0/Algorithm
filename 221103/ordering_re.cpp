#include<iostream>

#define Num 10
#define Max 100
#define Min 0

void main()
{
	int a[] = { 56,25,67,88,100,61,55,67,76,56 };
	int i, juni[Max + 2];
	

	for (i = Min; i <= Max; i++)   // 0 clear
		juni[i] = 0;

	for (i = 0; i < Num; i++)     // substance + 1
		juni[a[i]]++;
	
	juni[Max + 1] = 1;

	for (i = Max; i >= Min; i--)
		juni[i] = juni[i] + juni[i + 1];

	std::printf("  Score  Ranking\n");
	for (i = 0; i < Num; i++)
	{
		std::printf("%6d%6d\n", a[i], juni[a[i] + 1]);
	}
}