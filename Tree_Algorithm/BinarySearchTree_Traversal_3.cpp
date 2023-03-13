// ÀÌÁøÅ½»ö ºñÀç±ÍÇü

#include<iostream>

struct tnode {
	struct tnode* left;
	char name[12];
	struct tnode* right;
};

struct tnode* talloc();
struct tnode* gentree(struct tnode*, char*);
void treewalk(struct tnode*);

int main()
{
	char dat[12];
	struct tnode* root;

	root = NULL;
	while (scanf_s("%s", dat, 12) != EOF)
	{
		root = gentree(root, dat);
	}
	treewalk(root);
}

void treewalk(struct tnode* p)
{
	struct tnode* q, * w[128];
	int sp = 0;

	q = p;
	while (!(sp == 0 && q == NULL)) {
		while (q != NULL) {
			w[sp++] = q;
			q = q->left;
		}
		sp--;
		printf("%s\n", w[sp]->name);
		q = w[sp]->right;
	}
}

struct tnode* gentree(struct tnode* p, char* w)
{
	if (p == NULL) {
		p = talloc();
		strcpy_s(p->name, w);
		p->left = p->right = NULL;
	}
	else if (strcmp(p->name, w) < 0)
		p->right = gentree(p->right, w);
	else
		p->left = gentree(p->left, w);
	return p;
}

struct tnode* talloc()
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}