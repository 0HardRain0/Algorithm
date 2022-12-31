//선두에 추가
#include<iostream>
#include<string>

#define TableSize 1000
#define ModSize 1000

int hash(char*);

struct tfield {
	char name[20];
	char tel[20];
	struct tfield* pointer;
} *dat[TableSize];

struct tfield* talloc();

int main()
{
	int n;
	char key[20];
	struct tfield* p;

	for (n = 0; n < TableSize; n++)
		dat[n] = NULL;

	std::cout << "Name PhoneNumber\n";
	while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		n = hash(p->name);
		p->pointer = dat[n];
		dat[n] = p;
	}

	rewind(stdin);
	std::cout << "\nPlease, Enter data to search\n";
	while (scanf("%s", key) != EOF) {
		n = hash(key);
		p = dat[n];
		while (p != NULL) {
			if (strcmp(key, p->name) == 0)
				printf("%15s%15s\n", p->name, p->tel);
			p = p->pointer;
		}
	}
}

int hash(char* s)
{
	int n;

	n = strlen(s);
	return (s[0] - 'A' + (s[n / 2 - 1] - 'A') * 26 + (s[n - 2] - 'A') * 26 * 26)
		% ModSize;
}

struct tfield* talloc()
{
	return (struct tfield*)malloc(sizeof(struct tfield));
}