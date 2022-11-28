#include<iostream>
using namespace std;

#define N 4
int p[N + 1];

void perm(int);

void main()
{
	int i;
	for (i = 0; i <= N; i++)
		p[i] = i;
	perm(1);
}

void perm(int i)
{
	int j, k, t;
	
	if (i < N) {
		for (j = i; j <= N; j++) {
			t = p[j];
			for (k = j; k > i; k--)
				p[k] = p[k - 1];
			p[i] = t;

			perm(i + 1);

			for (k = i; k < j; k++)
				p[k] = p[k + 1];
			p[j] = t;
		}
	}
	else {
		for (j = 1; j <= N; j++)
			cout << p[j] << " ";
		cout << endl;
	}
}

//create Word

/*
 p[1] = 'a'; p[2] = 'c'; p[3] = 'h'; p[4] = t;

  cout << p[j];
*/