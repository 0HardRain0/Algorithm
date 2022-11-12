#include<iostream>
#include<string>
using namespace std;

#define N 10

void main()
{
	struct girl {
		char name[20];
		int age;
	} a[] = { "Ann",18,"Rolla",19,"Nancy",16,"Eluza",17,"Juliet",18,"Machilda",20,"Emy",15,"Candy",16,"Ema",17,"Mari",18 };

	char key[20];
	int i, flag = 0;

	cout << "Searching Data ? "; cin.getline(key, 20);

	for (i = 0; i < N; i++) {
		if (strcmp(key, a[i].name) == 0) {
			cout << a[i].name << " " << a[i].age << endl;
			flag = 1;
			break;
		}
	}

	if (flag != 1)
		cout << "No Searching Data" << endl;

}