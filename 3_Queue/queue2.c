/********************************************************
Ϊ�˱�����ּ����������ʹ�ö���ʱ��ʹ��ѭ������
���ļ�ʵ��˳����еĵڶ��ַ�����ѭ�����У�
������������[]��ʾ��Ӧλ��Ϊ�գ�

front
|
a    b    c
[]        d
[]   []   e��������rear

˼·��

[]  []  []
[]      []
[]  []  []
������Ϊ��ʱ��front = rear

        a    b    c         a    b    []����rear  
rear������ []        d         h         d
        g    f    e         g    f    e

ÿ�������һ��Ԫ�أ�rear = (rear + 1) % 8��
����Ա�֤�ڶ��������˷�һ���ռ䣩ʱ��rear����ָ��a[0]��λ�ã�
��rear = (7 + 1) % 8��Ҳ����rear = 0��

��������˼·�漰����
********************************************************/
#include <stdio.h>

#define SIZE 1000

void enqueue(char c);
char dequeue(void);
int isEmpty(void);
int isFull(void);

char queue[SIZE];
int front = 0;
int rear = 0;

int main(void)
{
    /*�������A, B, C�����Ȼ�������*/
    char c = 'A';
    for (int i = 0; i < 3; i++)
    {
        if (!isFull())
        {
            enqueue(c);
            c++;  
        }   
    }
    while (!isEmpty())
    {
        putchar(dequeue());
    }
    printf("\n");
    return 0;
}

void enqueue(char c)
{
    queue[rear] = c;
    rear = (rear + 1) % SIZE;
}
char dequeue(void)
{
    char ch;
    ch = queue[front];
    front = (front + 1) % SIZE;
    return ch;

}
int isEmpty(void)
{
    return front == rear;
}
int isFull(void)
{
	return (rear + 1) % SIZE == front;
}

