#include<iostream>
using namespace std;

void hanoi(int, int, int, int);
void move(int, int, int);

int pie[20][3];
int sp[3], N;

void main()
{
	int i;
	cout << "How many disks? ";
	cin >> N;

	for (i = 0; i < N; i++)
		pie[i][0] = N - i;
	sp[0] = N; sp[1] = 0; sp[2] = 0;

	hanoi(N, 0, 1, 2);
}

void hanoi(int n, int a, int b, int c)
{
	if (n > 0)
	{
		hanoi(n - 1, a, c, b);
		move(n, a, b);
		hanoi(n - 1, c, b, a);
	}
}

void move(int n, int s, int d)
{
	int i, j;

	pie[sp[d]][d] = pie[sp[s] - 1][s];
	sp[d]++;
	sp[s]--;

	cout << "\n" << n << "number disks " << 'a' + s << "-->" << 'a' + d << " move" << endl;
	for (i = N - 1; i >= 0; i--)
	{
		for (j = 0; j < 3; j++)
		{
			if (i < sp[j])
				printf("%8d", pie[i][j]);
			else
				cout << "        ";
		}
		cout << endl;
	}
	cout << "\n       a       b       c" << endl;
	rewind(stdin); getchar();
}