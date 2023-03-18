// 지적 데이터베이스

#include<iostream>

struct tnode {
	struct tnode* left;
	char node[30];
	struct tnode* right;
};

struct tnode* talloc();
int getch()
{
	rewind(stdin);
	return getchar();
}

int main()
{
	struct tnode* root, * p, * q1, * q2;
	int c;

	root = talloc();
	printf("Initial node? "); scanf_s("%s", root->node, 80);
	root->left = root->right = NULL;

	do {
		p = root;
		while (p->left != NULL) {
			printf("\n%s y/n ", p->node); c = getch();
			if (c == 'Y' || c == 'y')
				p = p->left;
			else
				p = p->right;
		}
		//std::cout << "\nAnswer is " << p->node << ". \nIs correct? y/n ";  // C++
		printf("\nAnswer is %s.\nIs correct? y/n ", p->node);
		c = getch();

		if (c == 'n' || c == 'N') {
			q1 = talloc(); *q1 = *p;

			q2 = talloc();
			printf("\n What do you think? "); scanf_s("%s", q2->node,80);
			q2->left = q2->right = NULL;

			printf("Which question distinguishes %s from %s", q1->node, q2->node);
			scanf_s("%s", p->node,80);
			printf("Is it okay to be %s? y/n", q1->node);
			c = getch();
			if (c == 'Y' || c == 'y') {
				p->left = q1; p->right = q2;
			}
			else {
				p->left = q2; p->right = q1;
			}
		}
	} while (printf("\n should I continue? y/n"), c = getch(), c == 'Y' || c == 'y');
	std::cout << "\n";
}

struct tnode* talloc()
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}