#include<iostream>

unsigned rndnum = 13;

unsigned irnd();

void main()
{
	int j;
	for (j = 0; j < 100; j++) {
		printf("%8d", irnd());
	}
	printf("\n");
}

unsigned irnd()
{
	rndnum = (rndnum * 109 + 1021) % 32768;
	return rndnum;
}