//가위바위보

#include<iostream>

int main()
{
	int man, computer, M, judge;
	int table[3][3] = { {0,0,0},
					    {0,0,0},
					    {0,0,0} },
		hist[3] = { 0,0,0 };
	const char *hand[3] = { "Rock", "Scissors", "Paper"};

	M = 0;

	while (1) {
		if (table[M][0] > table[M][1] && table[M][0] > table[M][2])
			computer = 2;
		else if (table[M][1] > table[M][2])
			computer = 2;
		else
			computer = 1;

		std::cout << "0: Rock  1: Scissors  2: Paper\n";
		std::cout << "Your hand "; scanf_s("%d", &man);
		std::cout << "Computer hand" << hand[computer] << "\n";

		judge = (computer - man + 3) % 3;
		switch (judge) {
			case 0: std::cout << "Draw\n"; break;
			case 1: std::cout << "You Win\n"; break;
			case 2: std::cout << "Computer Win\n"; break;

		}
		hist[judge]++;
		table[M][man]++;
		M = man;
		std::cout << "--- " << hist[1] << " Win " << hist[2] << " Lose " << hist[0] << " Draw ---\n\n";
	}

	return 0;
}