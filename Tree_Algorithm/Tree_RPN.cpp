//Reverse-polish Notation
// 다시 한번 체크할 것 -> 오류 발생(결과가 제대로 나오지 않음)


#include<iostream>
#include<cstring>

struct tnode {
	struct tnode* left;
	char ope;
	struct tnode* right;
};

struct tnode* talloc();
struct tnode* gentree(struct tnode*, char*);
void prefix(struct tnode*);
void infix(struct tnode*);
void postfix(struct tnode*);

int main()
{
	struct tnode* root;
	char expression[] = "ab*cd+e/-";

	root = NULL;
	root = gentree(root, expression);

	std::cout << "\nprefix   = "; prefix(root);
	std::cout << "\ninfix    = "; infix(root);
	std::cout << "\npostfix  = "; postfix(root);
	std::cout << "\n";
}

struct tnode* gentree(struct tnode* p, char* w)
{
	int n;

	n = strlen(w);  // 문제 -> 32비트에서 64비트로 넘어오면서 발생하는 문제 
	p = talloc();
	p->ope = w[n - 1];
	w[n - 1] = '\0';
	if (!(p->ope == '_' || p->ope == '+' || p->ope == '*' || p->ope == '/')) {
		p->left = p->right = NULL;
	}
	else {
		p->right = gentree(p->right, w);
		p->left = gentree(p->left, w);
	}
	return p;
}

void prefix(struct tnode* p) {
	if (p != NULL) {
		putchar(p->ope);
		prefix(p->left);
		prefix(p->right);
	}
}

void infix(struct tnode* p)
{
	if (p != NULL)
	{
		infix(p->left);
		putchar(p->ope);
		infix(p->right);
	}
}

void postfix(struct tnode* p)
{
	if (p != NULL)
	{
		postfix(p->left);
		postfix(p->right);
		putchar(p->ope);
	}
}

struct tnode* talloc()
{
	return(struct tnode*)malloc(sizeof(struct tnode));
}