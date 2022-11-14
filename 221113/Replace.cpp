#include<iostream>
using namespace std;

char* search(char *, char *);
void replace(char *, char *, char *);

void main()
{
	static char text[] = "This is a pen. That is a pencil.";

	replace(text, "pen", "cap");
	cout << text << endl;
}

void replace(char* text, char* key, char* rep)
{
	char* p;
	int i;
	p = search(text, key);
	while (p != NULL)
	{
		for (i = 0; i < (int)strlen(rep); i++)
			p[i] = rep[i];
		p = search(p + strlen(key), key);
	}
}
char* search(char* text, char* key)
{
	int m, n;
	char* p;

	m = strlen(text);
	n = strlen(key);
	for (p = text; p <= text + m - n; p++) {
		if (strncmp(p, key, n) == 0)
			return p;
	}
	return NULL;
}