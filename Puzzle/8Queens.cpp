#include<iostream>

void backtrack(int);

#define N 8

int column[N + 1],
    rup[2 * N + 1],
    lup[2 * N + 1],
    queen[N + 1];


int main()
{
    int i;

    for (i = 1; i <= N; i++)
        column[i] = 1;
    for (i = 1; i <= 2 * N; i++)
        rup[i] = lup[i] = 1;

    backtrack(1);

    return 0;
}

void backtrack(int i)
{
    int j, x, y;
    static int num = 0;

    if (i > N) {
        std::cout << "\n value " << ++num << " \n";
        for (y = 1; y <= N; y++) {
            for (x = 1; x <= N; x++) {
                if (queen[y] == x)
                    std::cout << " Q";
                else
                    std::cout << " .";
            }
            std::cout << "\n";
        }
    }
    else {
        for (j = 1; j <= N; j++) {
            if (column[j] == 1 && rup[i + j] == 1 && lup[i - j + N] == 1) {
                queen[i] = j;    //(i,j)°¡ ÄýÀÇ À§Ä¡
                column[j] = rup[i + j] = lup[i - j + N] = 0;
                backtrack(i + 1);
                column[j] = rup[i + j] = lup[i - j + N] = 1;
            }
        }
    }
}