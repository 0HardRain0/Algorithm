#include<iostream>

#define TableSize 1000
#define ModSize   1000

int hash(char *);

struct tel {
	char name[20];
	char telnum[20];
} dat[TableSize];

void main()
{
	int n;
	char a[20], b[20];

	std::cout << " Name Tel\n";
	while (scanf("%s %s", a, b) != EOF) {
		n = hash(a);
		strcpy(dat[n].name, a);
		strcpy(dat[n].telnum, b);
	}
	std::rewind(stdin);
	std::cout << "Please, Input Searching Data\n";
	while (scanf("%s", a) != EOF) {
		n = hash(a);
		std::cout << dat[n].name << "  " << dat[n].telnum;
	}
}

int hash(char *s)
{
	int n;

	n = strlen(s);
	return (s[0] - 'A' + (s[n / 2 - 1] - 'A') * 26 + (s[n - 2] - 'A') * 26 * 26)
		% ModSize;
}