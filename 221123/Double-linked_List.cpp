#include<iostream>
#include<string>
using namespace std;

struct tfield {
	struct tfield* left;
	char name[20];
	char tel[20];
	struct tfield* right;
};

struct tfield* talloc();

int main()
{
	struct tfield* head, * tail, * p;

	tail = NULL;
	while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		p->left = tail;
		tail = p;
	}

	p = tail;
	head = NULL;
	while (p != NULL) {
		p->right = head;
		head = p;
		p = p->left;
	}

	cout << "\n Double Linked List\n";
	p = tail;
	while (p != NULL)
	{
		printf("%15s%15s\n", p->name, p->tel);
		p = p->left;
	}
}

struct tfield* talloc()
{
	return (struct tfield*)malloc(sizeof(struct tfield));
}