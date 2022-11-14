#include<iostream>
using namespace std;

#define TableSize 1050
#define ModSize 1000

int hashp(char*);

struct tel {
	char name[12];
	char telnum[12];
	int empty;
} dat[TableSize];

void main()
{
	int n;
	char a[12], b[12];

	cout << "  Name  TelNum\n";
	while (scanf("%s %s", a, b) != EOF) {
		n = hashp(a);
		while (dat[n].empty == 1 && n < TableSize)
			n++;
		if (n < TableSize) {
			strcpy(dat[n].name, a);
			strcpy(dat[n].telnum, b);
			dat[n].empty = 1;
		}
		else
			cout << "Full Chart\n";
	}

	rewind(stdin);
	cout << "Please, Input Searching data\n";
	while (scanf("%s", a) != EOF)
	{
		n = hashp(a);
		while (strcmp(a, dat[n].name) != 0 && n < TableSize)
			n++;
		if (n < TableSize)
			cout << " " << dat[n].name << " " << dat[n].telnum;
		else
			cout << "No Data\n";
	}
}

int hashp(char* s)
{
	int n;
	n = strlen(s);
	return (s[0] - 'A' + (s[n / 2 - 1] - 'A') * 26 + (s[n - 2] - 'A') * 26 * 26)
		% ModSize;
}
