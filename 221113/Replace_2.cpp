#include<iostream>
using namespace std;

void replace(char *, char *, char *);
char *search(char *, char *);

void main()
{
	int k;
	static char text[][128] = { "    --- 우리가 눈발이라면 ---",
							 "우리가 눈발이라면",
							 "허공에서 쭈빗쭈빗 흩날리는",
							 "진눈깨비는 되지 말자",
							 "세상이 바람 불고 춥고 어둡다 해도",
							 "사람이 사는 마을",
							 "가장 낮은 곳으로",
							 "" };
	k = 0;
	while (text[k][0] != '\0') {
		replace(text[k], "우리가", "너 희 가");
		replace(text[k], "낮은", "높은");
		cout << text[k] << endl;
		k++;
	}
}

void replace(char* text, char* key, char* rep)
{
	char* p, buf[128];

	p = search(text, key);
	while (p != NULL) {
		*p = '\0';
		strcpy(buf, p + strlen(key));
		strcat(text, rep);
		strcat(text, buf);
		p = search(p + strlen(rep), key);
	}
}

char* search(char* text, char* key)
{
	int m, n;
	char* p;

	m = strlen(text);
	n = strlen(key);
	
	for (p = text; p <= text + m - n; p++)
	{
		if (strncmp(p, key, n) == 0)
			return p;
	}
	return NULL;

}