#include<iostream>
using namespace std;

#define MaxSize 100    // ������ ũ��
int queue[MaxSize];    // ������
int head = 0,          // ù �������� ������
    tail = 0;          // ������ �������� ������
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

int queuein(int n)                     // �����Ŀ� ������ ����
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

int queueout(int* n)                  // �����Ŀ� ������ ����
{
    if (tail != head)
    {
        *n = queue[head];
        head++;
        head = head % MaxSize;
        return 0;
    }
    else
        return -1;                  // �������� ����� ���
}