//질의응답과 결정트리

#include<iostream>

#define Max 100
#define nil -1

int getch()
{
	rewind(stdin);   // rewind 입력버퍼 초기화
	return getchar();
}

int main()
{
	struct tnode {
		int left;
		char node[30];
		int right;
	};

	//질문 다시 작성해야함 완전 틀림
	static struct tnode a[Max] = { {1   ,"Talent?"		  ,2},
								{3   ,"Singer?"		  ,4},
								{nil ,"Sam Smith"     ,nil},
								{nil ,"Ed Sheeran"    ,nil},
								{5   ,"Actress"       ,6},
								{nil ,"Angelina Jolie",nil},
								{nil ,"Scarlett Johansson",nil} };

	int p, lp = 6, c;

	do {
		p = 0;
		while (a[p].left != nil) {
			printf("\n%s y/n ", a[p].node); c = getch();
			if (c == 'y' || c == 'Y')
				p = a[p].left;
			else
				p = a[p].right;
		}

		printf("\n Answer is %s. \n Is that correct?  y/n ", a[p].node);
		c = getch();

		if (c == 'n' || c == 'N') {
			a[lp + 1] = a[p];

			printf("\n What do you think?");
			scanf_s("%s", a[lp + 2].node, 80);
			a[lp + 2].left = a[lp + 2].right = nil;

			printf("What is the question that distinguishes %s from %s?", a[lp + 1].node, a[lp + 2].node);
			scanf_s("%s", a[p].node, 80);
			printf("Is %s of Yes okay with something? y/n ", a[lp + 1].node);
			c = getch();

			if (c == 'Y' || c == 'y') {
				a[p].left = lp + 1; a[p].right = lp + 2;
			}
			else {
				a[p].left = lp + 2; a[p].right = lp + 1;
			}
			lp = lp + 2;
		}
	} while (printf("\n Continue? y/n "), c = getch(), c == 'y' || c == 'Y');
	std::cout << "\n";
}

