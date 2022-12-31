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
	struct tfield* head, * p;

	head = talloc();
	head->left = head->right = head;

	while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		p->right = head;
		p->left = head->left;
		head->left->right = p;
		head->left = p;
	}

	cout << "\n Double linked List\n";
	p = head->right;
	while (p != head) {
		printf("%15s%15s\n", p->name, p->tel);
		p = p->right;
	}
	cout << "\n Double linked List\n";
	p = head->left;
	while (p != head) {
		printf("%15s%15s\n", p->name, p->tel);
		p = p->left;
	}
}

struct tfield* talloc()
{
	return (struct tfield *)malloc(sizeof(struct tfield));
}