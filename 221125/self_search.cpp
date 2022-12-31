#include<iostream>
#include<string>
using namespace std;

struct tfield {
	char name[20];
	char tel[20];
	struct tfield* pointer;
};

struct tfield* talloc();

int main()
{
	char key[20];
	struct tfield* head, * p, * old;

	head = NULL;
	while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		p->pointer = head;
		head = p;
	}

	while (printf("\nKey Name ? "), scanf("%s", key) != EOF) {
		p = old = head;
		while (p != NULL)
		{
			if (strcmp(key, p->name) == 0) {
				printf("%15s%15s\n", p->name, p->tel);
				if (p != head) {
					old->pointer = p->pointer;
					p->pointer = head;
					head = p;
				}
				break;
			}
			old = p;
			p = p->pointer;
		}
	}
}

struct tfield* talloc()
{
	return (struct tfield*)malloc(sizeof(struct tfield));
}