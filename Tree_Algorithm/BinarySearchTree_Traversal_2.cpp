// ū ������ ����
// ���� ���Ĵٵ�, ��Ʈ��, ���Ĵٵ� ���̺귯��(C�� ���)
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
	while (scanf_s("%s", dat, 12) != EOF) {
		root = gentree(root, dat);
	}
	treewalk(root);
}

void treewalk(struct tnode* p)
{
	if (p != NULL)
	{
		treewalk(p->right);
		printf("%s\n", p->name);
		treewalk(p->left);
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

struct tnode* talloc()
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}