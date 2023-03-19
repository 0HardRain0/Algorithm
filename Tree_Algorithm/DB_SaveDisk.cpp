// 데이터베이스의 디스크로의 보존
// 오류 수정해야함.
// C28182 NULL 포인터를 역참조

#include<iostream>

#define Rec 34L
#define Leaf -1
FILE* fp;

struct tnode {
	struct tnode *left;
	char node[30];
	struct tnode* right;
};

struct tnode* talloc();
struct tnode* readtree(struct tnode *);
void writetree(struct tnode*);

int getch()
{
	rewind(stdin);
	return getchar();
}

int main()
{
	struct tnode* root = NULL, * p, * q1, * q2;
	int c;

	if ((fopen_s(&fp, "dbase.dat", "r")) == NULL) {
		root = talloc();
		printf("Initial Node? "); scanf_s("%s", root->node, 80);
		root->left = root->right = NULL;
	}
	else {
		root = readtree(root);
		fclose(fp);
	}
	do {
		p = root;  //Tree Search
		while (p->left != NULL) {
			printf("\n%s y/n ", p->node); c = getch();
			if (c == 'Y' || c == 'y')
				p = p->left;
			else
				p = p->right;
		}
		printf("\nAnswer is %s.\nIs correct? y/n ", p->node);
		c = getch();

		if (c == 'n' || c == 'N') {
			q1 = talloc(); *q1 = *p;

			q2 = talloc();
			printf("\nWhat do you think? "); scanf_s("%s", q2->node, 80);
			q2->left = q2->right = NULL;

			printf("Which question distinguishes %s from %s?", q1->node, q2->node);
			scanf_s("%s", p->node, 80);
			printf("Is it okay to be %s? y/n", q1->node);
			c = getch();
			if (c == 'Y' || c == 'y') {
				p->left = q1; p->right = q2;
			}
			else {
				p->left = q2; p->right = q1;
			}
		}
	} while (printf("\nShould I continue? y/n"), c = getch(), c == 'Y' || c == 'y');
	std::cout << "\n";
	//fopen -> fopen_s로 변경해야함
	if ((fopen_s(&fp, "dbase.dat", "w")) != NULL) {
		writetree(root);
		fclose(fp);
	}
}

struct tnode* readtree(struct tnode* p)
{
	int flag;

	p = talloc();
	// fscanf_s 쓸때 p->node 뒤에 사이즈 정해줘야함 
	fscanf_s(fp, "%30s%4d", p->node, 30, &flag);
	if (flag == Leaf)
		p->left = p->right = NULL;
	else {
		p->left = readtree(p->left);
		p->right = readtree(p->right);
	}
	return p;
}

void writetree(struct tnode* p)
{
	if (p != NULL) {
		if (p->left == NULL)
			fprintf(fp, "%30s%4d", p->node, Leaf);
		else
			fprintf(fp, "%30s%4d", p->node, !Leaf);
		writetree(p->left);
		writetree(p->right);
	}
}

struct tnode* talloc()
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}