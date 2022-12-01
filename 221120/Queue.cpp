#include<iostream>
using namespace std;

#define MaxSize 100    // 대기행렬 크기
int queue[MaxSize];    // 대기행렬
int head = 0,          // 첫 데이터의 포인터
    tail = 0;          // 마지막 데이터의 포인터
int queuein(int);
int queueout(int *);

void main()
{
    int c, n;
    
    while (printf("]"), (c = getchar()) != EOF)
    {
        rewind(stdin);
        if (c == 'i' || c == 'I')
        {
            cout << "data --> ";
            cin >> n; rewind(stdin);
            if (queuein(n) == -1)
                cout << "Queue is full\n";
        }
        if (c == 'o' || c == '0')
        {
            if (queueout(&n) == -1)
                cout << "Queue is empty\n";
            else
                cout << "queue data --> " << n << endl;
        }
    }
}

int queuein(int n)                     // 대기행렬에 데이터 넣음
{
    if ((tail + 1) % MaxSize != head)
    {
        queue[tail] = n;
        tail++;
        tail = tail % MaxSize;
        return 0;
    }
    else
        return -1;
}

int queueout(int* n)                  // 대기행렬에 데이터 추출
{
    if (tail != head)
    {
        *n = queue[head];
        head++;
        head = head % MaxSize;
        return 0;
    }
    else
        return -1;                  // 대기행렬이 비었을 경우
}