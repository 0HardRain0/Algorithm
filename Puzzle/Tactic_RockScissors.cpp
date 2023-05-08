//가위바위보 게임 컴퓨터 랜덤요소 X
#include<iostream>

int main()
{
	int man, computer, C, M, judge;
	int table[3][3][3] = { {{0,0,0},{0,0,0},{0,0,0}},
		                   {{0,0,0},{0,0,0},{0,0,0}},
		                   {{0,0,0},{0,0,0},{0,0,0}}};

	int hist[3] = { 0,0,0 };
	const char* hand[3] = { "Rock","Scissors","Paper" };

	C = M = 0;
	while (1) {
		if (table[C][M][0] > table[C][M][1] && table[C][M][0] > table[C][M][2])
			computer = 0;
		else if (table[C][M][1] > table[C][M][2])
			computer = 1;
		else
			computer = 2;

		std::cout << "0: Rock  1: Scissors  2: Paper\n";
		std::cout << "Your hand "; scanf_s("%d", &man);

		std::cout << "Computer hand " << hand[computer] << "\n";

		judge = (computer - man + 3) % 3;
		switch (judge) {
			case 0:std::cout << "Draw\n";
				table[C][M][(computer + 2) % 3]++; break;
			case 1:std::cout << "Your Win\n";
				table[C][M][computer]--; break;
			case 2:std::cout << "Computer Win\n";
				table[C][M][computer]++; break;
		}
		M = man;
		C = computer;
		hist[judge]++;
		std::cout << "--- " << hist[1] << " Win " << hist[2] << " Lose " << hist[0] << " Draw --- \n\n";
	}

	return 0;
}