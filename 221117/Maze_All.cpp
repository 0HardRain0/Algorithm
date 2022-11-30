#include<iostream>
using namespace std;

int m[9][9] = { {2,2,2,2,2,2,2,2,2},{2,0,0,0,0,0,0,0,2},{2,0,2,2,0,2,2,0,2},{2,0,2,0,0,2,0,0,2},{2,0,2,0,2,0,2,0,2}, {2,0,0,0,0,0,2,0,2},{2,2,0,2,2,0,2,2,2},{2,0,0,0,0,0,0,0,2},{2,2,2,2,2,2,2,2,2} };

int Si, Sj, Ei, Ej, success, sp, ri[100], rj[100];

int visit(int, int);

void main()
{
	sp = 0;
	success = 0;
	Si = 1; Sj = 1; Ei = 7; Ej = 7;

	cout << "\n Searching Maze";
	if (visit(Si, Sj) == 0)
		cout << "You can't find a way out\n";
	cout << endl;
}

int visit(int i, int j)
{
	int k;
	static int path = 1;

	m[i][j] = 1;
	ri[sp] = i; rj[sp] = j; sp++;

	if (i == Ei && j == Ej)
	{
		cout << "\npath=" << path++ << endl;
		for (k = 0; k < sp; k++)
		{
			printf("(%d,%d) ", ri[k], rj[k]);
		}
		success = 1;
	}

	if (m[i][j + 1] == 0) visit(i, j + 1);
	if (m[i + 1][j] == 0) visit(i + 1, j);
	if (m[i][j - 1] == 0) visit(i, j - 1);
	if (m[i - 1][j] == 0) visit(i - 1, j);

	sp--;
	m[i][j] = 0;

	return success;
}