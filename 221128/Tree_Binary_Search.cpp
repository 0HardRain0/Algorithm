#include<iostream>
#include<string>
using namespace std;

#define nil -1
#define MaxSize 100

struct tnode {
	int left;
	char name[12];
	int right;
};

int main()
{
	struct tnode a[MaxSize] = { {  1,"Machilda",  2},
								{  3,"Candy"   ,  4},
								{  5,"Rolla"   ,nil},
								{nil,"Ann"     ,nil},
								{  6,"Emy"     ,  7},
								{nil,"Nancy"   ,nil},
								{nil,"Eluza"   ,nil},
								{nil,"Lisa"    ,nil} };

	char key[12];
	int p;

	cout << "Search Name --> "; scanf("%s", key);
	p = 0;
	while (p != nil) {
		if (strcmp(key, a[p].name) == 0)
		{
			cout << "found it\n";
			break;
		}
		else if (strcmp(key, a[p].name) < 0)
			p = a[p].left;
		else
			p = a[p].right;
	}
}