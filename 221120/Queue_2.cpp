#include<iostream>
using namespace std;

int queuein(int);
int queueout(int *);
void disp(void);

#define MaxSize 100
int queue[MaxSize];
int head = 0, 
    tail = 0;

void main()
{
    int c, n;

    while (printf("]"), (c = getchar()) != EOF)
    {
        rewind(stdin);
        switch (c) {
        case'i':
        case'I': cout << "data--> ";
            cin >> n; rewind(stdin);
            if (queuein(n) == -1)
                cout << "Queue is full\n";
            break;
        case'o':
        case'O': if (queueout(&n) == -1)
                     cout << "Queue is empty\n";
               else
                     cout << "Queue data --> " << n << endl;
            break;

        case'l':
        case'L': disp();
            break;
        }
    }
}

int queuein(int n)
{
    if ((tail + 1) % MaxSize != head)
    {
        queue[tail] = n;
        tail++;
        tail = tail % MaxSize;
        return 0;
    }
    else return -1;
}

int queueout(int* n) 
{
    if (tail != head)
    {
        *n = queue[head];
        head++;
        head = head % MaxSize;
        return 0;
    }
    else
        return -1;
}

void disp(void)              // 대기행렬의 내용을 표시
{
    int i;

    i = head;
    while (i != tail)
    {
        cout << queue[i] << endl;
        i++;
        i = i % MaxSize;
    }
}

//대기행렬 케이스 작성