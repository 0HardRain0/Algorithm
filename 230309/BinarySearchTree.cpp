/*
// 동적 메모리상에서의 트리 표현
#include<iostream>
#include<string.h>


//구조체
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

*/

// 이진탐색트리 재귀 버전

#include<iostream>
#include<string.h>
using namespace std;

struct tnode {
	struct tnode* left;
	char name[12];
	struct tnode* right;
};

struct tnode* talloc(void);
struct tnode* gentree(struct tnode*, char*);

int main(void)
{
	char dat[12];
	struct tnode* root, * p;

	root = NULL;
	while (scanf_s("%s", 80, dat) != EOF) {
		root = gentree(root, dat);
	}
	p = root;
	while (p != NULL) {
		cout << "%s\n" << p->name;
		p = p->left;
	}
}

struct tnode* gentree(struct tnode* p, char* w)
{
	if (p == NULL) {
		p = talloc();
		strcpy_s(p->name, w);
		p->left = p->right = NULL;
	}
	else if (strcmp(w, p->name) < 0)
		p->left = gentree(p->left, w);
	else
		p->right = gentree(p->right, w);

	return p;
}

struct tnode* talloc(void)
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}