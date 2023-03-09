// 이진탐색트리 대략적인 코드
#include<iostream>
#include<string.h>


struct tnode {
	struct tnode* left;
	char name[12];
	struct tnode* right;
} dat[12];

struct tnode* talloc(void);

int main(void) {

	char dat[12];
	struct tnode* root, * p, * old = {0};

	root = talloc();
	scanf_s("%s", root->name, 80);
	root->left = root->right = NULL;

	while (scanf_s("%s", dat, 80) != EOF) {
		p = root;
		while (p != NULL) {
			old = p;
			// 
			if (strcmp(dat, p->name) <= 0)
				p = p-> left;
			else
				p = p-> right;
		}

		p = talloc();
		strcpy_s(p->name, 12, dat);
		p->left = p->right = NULL;
		if (strcmp(dat, old->name) <= 0)
			old->left = p;
		else
			old->right = p;
	}
}

struct tnode* talloc(void)
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}
