//레벨에 따른 횡단(Tree)

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
	struct tnode* q[128], * w[128];  //포인트 테이블
	int i, child, n, level;          //작업용

	//초기화
	child = 1;
	q[0] = p;
	level = 0;

	do {
		n = 0;
		printf("level %d :", level);
		for (i = 0; i < child; i++) {
			printf("%12s", q[i]->name);
			if (q[i]->left != NULL)
				w[n++] = q[i]->left;
			if (q[i]->right != NULL)
				w[n++] = q[i]->right;
		}
		std::cout << "\n";
		child = n;
		for (i = 0; i < child; i++)
			q[i] = w[i];
		level++;
	} while (child != 0);
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
	return(struct tnode*)malloc(sizeof(struct tnode));
}