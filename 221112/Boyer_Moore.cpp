#include<iostream>
using namespace std;

char* search(char*, char*);
void table(char*);

int skip[256];

void main()
{
	static char text[] = "This is a pen. That is a pencil.";
	char* p, * key = "pen";
	table(key);
	p = search(text, key);
	while (p != NULL) {
		cout << p << endl;
		p = search(p + strlen(key), key);
	}
}

void table(char* key) 
{
	int k, n;
	n = strlen(key);
	for (k = 0; k <= 255; k++)
		skip[k] = n;
	for (k = 0; k < n - 1; k++)
		skip[key[k]] = n - 1 - k;
}
char* search(char* text, char* key)
{
	int m, n;
	char* p;

	m = strlen(text);
	n = strlen(key);

	p = text + n - 1;
	while (p < text + m) {
		if (*p == key[n - 1]) {
			if (strncmp(p - n + 1, key, n) == 0)
				return p - n + 1;
		}
		p = p + skip[*p];
	}
	return NULL;
}