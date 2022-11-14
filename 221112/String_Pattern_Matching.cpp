#include<iostream>
using namespace std;

char* search(char*, char*);

void main()
{
	static char text[] = "This is a pen. That is a pencil.";
	char* p, * key = "pen";

	p = search(text, key);
	while (p != NULL) {
		cout << p << endl;
		p = search(p + strlen(key), key);
	}
}

char* search(char* text, char* key)
{
	int m, n;
	char *p;
	m = strlen(text);
	n = strlen(key);
	for (p = text; p <= text + m - n; p++) {
		if (strncmp(p, key, n) == 0)
			return p;
	}
	return NULL;
}