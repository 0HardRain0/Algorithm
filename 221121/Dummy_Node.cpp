#include<iostream>
using namespace std;


struct tfield {
	char name[20];
	char tel[20];
	struct tfield* pointer;
};

struct tfield* talloc();

void main()
{
	struct tfield* head, * p, * old;

	head = talloc();
	old = head;
	while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		old->pointer = p;
		old = p;
	}
	old->pointer = NULL;

	p = head->pointer;
	while (p != NULL) {
		printf("%15s%15s\n", p->name, p->tel);
		p = p->pointer;
	}
}

struct tfield* talloc()
{
	return (struct tfield*)malloc(sizeof(struct tfield));
}