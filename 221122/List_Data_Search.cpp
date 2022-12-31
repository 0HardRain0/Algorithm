#include<iostream>
#include<string>
using namespace std;

struct tfield {
	char name[20];
	char tel[20];
	struct tfield* pointer;
};

struct tfield* talloc();

void main()
{
	struct tfield* head, * p, sentinel;

	char key[20];

	head = &sentinel;
	while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF)
	{
		p->pointer = head;
		head = p;
	}

	rewind(stdin);
	while (printf("key name "), scanf("%s", key) != EOF)
	{
		strcpy(sentinel.name, key);
		p = head;
		while (strcmp(p->name, key) != 0)
			p = p->pointer;
		if (p != &sentinel)
			cout << p->name << " " << p->tel << "\n";
		else
			cout << "No found\n";
	}
}

struct tfield* talloc()
{
	return (struct tfield*)malloc(sizeof(struct tfield));
}