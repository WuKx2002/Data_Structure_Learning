/********************************************************
为了避免出现假溢出，我们使用队列时常使用循环队列
本文件实现顺序队列的第二种方案（循环队列）
（方案二）（[]表示对应位置为空）

front
|
a    b    c
[]        d
[]   []   e————rear

思路：

[]  []  []
[]      []
[]  []  []
当队列为空时，front = rear

        a    b    c         a    b    []——rear  
rear——— []        d         h         d
        g    f    e         g    f    e

每进入队列一个元素，rear = (rear + 1) % 8，
这可以保证在队列满（浪费一个空间）时，rear可以指向a[0]的位置，
即rear = (7 + 1) % 8，也就是rear = 0。

基于以上思路涉及程序。
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
    /*下面举例A, B, C入队列然后出队列*/
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

