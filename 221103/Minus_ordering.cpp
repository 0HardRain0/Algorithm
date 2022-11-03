#include<iostream>

#define Num 10
#define Max 36
#define Min -20
#define Bias 1-(Min)

void main()
{
	int a[] = { -3,2,3,-1,-2,-6,2,-1,1,5 };
	int i, juni[Max + Bias + 1];

	for (i = Min + Bias; i <= Max + Bias; i++)
		juni[i] = 0;
	
	for (i = 0; i < Num; i++)
		juni[a[i] + Bias]++;

	juni[0] = 1;
	for (i = Min + Bias; i <= Max + Bias; i++)
		juni[i] = juni[i] + juni[i - 1];

	std::printf("  Score  Ranking\n");
	for (i = 0; i < Num; i++) {
		std::printf("%6d%6d\n", a[i], juni[a[i] + Bias - 1]);
	}
}
