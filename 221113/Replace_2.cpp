#include<iostream>
using namespace std;

void replace(char *, char *, char *);
char *search(char *, char *);

void main()
{
	int k;
	static char text[][128] = { "    --- �츮�� �����̶�� ---",
							 "�츮�� �����̶��",
							 "������� �޺��޺� �𳯸���",
							 "��������� ���� ����",
							 "������ �ٶ� �Ұ� ��� ��Ӵ� �ص�",
							 "����� ��� ����",
							 "���� ���� ������",
							 "" };
	k = 0;
	while (text[k][0] != '\0') {
		replace(text[k], "�츮��", "�� �� ��");
		replace(text[k], "����", "����");
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