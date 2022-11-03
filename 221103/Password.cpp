#include<iostream>

void main()
{
	char table[] = { 'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M','?' };

	char *p,*password = "KSOIDHEPZ";
	int index;

	p = password;
	while (*p != '\0')
	{
		if ('A' <= *p && *p <= 'Z')
			index = *p - 'A';
		else
			index = 26;
		putchar(table[index]);
		p++;
	}
	std::cout << std::endl;
}