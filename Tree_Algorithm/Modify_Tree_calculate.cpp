// 나무형의 식 계산

#include<iostream>
#include<cstring>

struct tnode {
	struct tnode* left;
	int ope;
	struct tnode* right;
};

struct tnode* talloc();
struct tnode* gentree(struct tnode*, char*);
void postfix(struct tnode*);

int main()
{
	struct tnode* root;
	char expression[] = "53*64+2/-";

	root = NULL;
	root = gentree(root, expression);

	postfix(root);
	printf("value=%d\n", root->ope);
}

struct tnode* gentree(struct tnode* p, char* w)
{
	int n;

	n = strlen(w);
	p = talloc();
	if ('0' <= w[n - 1] && w[n - 1] <= '9')
		p->ope = w[n - 1] - '0';
	else
		p->ope = w[n - 1];
	w[n - 1] = '\0';
	if (!(p->ope == '-' || p->ope == '+' || p->ope == '*' || p->ope == '/')) {
		p->left = p->right = NULL;
	}
	else {
		p->right = gentree(p->right, w);
		p->left = gentree(p->left, w);
	}
	return p;
}

void postfix(struct tnode* p)
{
	if (p != NULL) {
		postfix(p->left);
		postfix(p->right);
		switch (p->ope) {
		case '+': p->ope = (p->left->ope) + (p->right->ope); break;
		case '-': p->ope = (p->left->ope) - (p->right->ope); break;
		case '*': p->ope = (p->left->ope) * (p->right->ope); break;
		case '/': p->ope = (p->left->ope) / (p->right->ope); break;
		}
	}
}

struct tnode* talloc()
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}

// 실행시 결과값 10이 나와야 함