#include<iostream>
using namespace std;
// 2�� �� 0�� ��, ��������������Գ
int m[7][7] = { {2,2,2,2,2,2,2},
			    {2,0,0,0,0,0,2},
	            {2,0,2,0,2,0,2},
	            {2,0,0,2,0,2,2},
	            {2,2,0,2,0,2,2},
	            {2,0,0,0,0,0,2},
	            {2,2,2,2,2,2,2} };

int Si, Sj, Ei, Ej, success;

int visit(int, int);

void main()
{
	success = 0;
	Si = 1; Sj = 1; Ei = 5; Ej = 5;

	cout << "\nSearch Maze" << endl;
	if (visit(Si, Sj) == 0)
		cout << "You can't find a way out" << endl;
	cout << endl;
}

int visit(int i, int j)
{
	m[i][j] = 1;

	if (i == Ei && j == Ej)
		success = 1;

	if (success != 1 && m[i][j + 1] == 0) visit(i, j + 1);
	if (success != 1 && m[i + 1][j] == 0) visit(i + 1, j);
	if (success != 1 && m[i][j - 1] == 0) visit(i, j - 1);
	if (success != 1 && m[i - 1][j] == 0) visit(i - 1, j);

	if (success == 1)
		printf("(%d,%d) ", i, j);
	return success;
}