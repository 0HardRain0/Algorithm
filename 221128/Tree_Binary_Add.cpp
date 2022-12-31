#include<iostream>
#include<string>

#define nil -1
#define MaxSize 100

struct tnode {
	int left;
	char name[12];
	int right;
};

int sp = 8;
struct tnode a[MaxSize]= { {  1,"Machilda",  2},
						   {  3,"Candy"   ,  4},
						   {  5,"Rolla"   ,nil},
						   {nil,"Ann"     ,nil},
					       {  6,"Emy"     ,  7},
				    	   {nil,"Nancy"   ,nil},
						   {nil,"Eluza"   ,nil},
	  				       {nil,"Lisa"    ,nil}};

int main()
{
	char key[12];
	int p, old, i;

	std::cout << "New name --> "; scanf("%s", key);
	p = 0;
	while (p != nil)
	{
		old = p;
		if (strcmp(key, a[p].name) <= 0)
			p = a[p].left;
		else
			p = a[p].right;
	}

	a[sp].left = a[sp].right = nil;
	strcpy(a[sp].name, key);
	if (strcmp(key, a[old].name) <= 0)
		a[old].left = sp;
	else
		a[old].right = sp;
	sp++;

	for (i = 0; i < sp; i++)
		printf("%4d%12s%4d\n", a[i].left, a[i].name, a[i].right);
}