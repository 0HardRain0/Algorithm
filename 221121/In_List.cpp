#include<iostream>
#include<string>

struct tfield {
	char name[20];
	char tel[20];
	struct tfield* pointer;
} *head;


struct tfield* talloc();

struct tfield* talloc();

void genlist();
void displist();
void link(char *);

int main()
{
	char key[20];

	genlist();
	displist();

	while (printf("Key Name "), scanf("%s", key) != EOF) {
		link(key);
	}

	displist();
}

void link(char* key)
{
	struct tfield* p, * n;

	n = talloc();
	printf("Add Data ");
	scanf("%s %s", n->name, n->tel);

	p = head;
	while (p != NULL)
	{
		if (strcmp(key, p->name) == 0){
			n->pointer = p->pointer;
			p->pointer = n;
			return;
		}
		p = p->pointer;
	}
	printf("No find Key Data\n");
}

void genlist()
{
	struct tfield* p;

	head = NULL;
	while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		p->pointer = head;
		head = p;
	}
	
}

void displist()
{
	struct tfield* p;
	p = head;
	while (p == NULL) {
		printf("%15s%15s\n", p->name, p->tel);
		p = p->pointer;
	}
	
}

struct tfield* talloc()
{
	return (struct tfield*)malloc(sizeof(struct tfield));
}