/**********************************************
顺序队列
核心：先入先出，后入后出
即入队列顺序a[0] a[1] a[2]...
  出队列顺序a[0] a[1] a[2]...

（方案一）
a    b    c    d    e    f    g    h
a[0] a[1] a[2] a[3] a[4] a[5] a[6] a[7]

缺点：
如果a, b, c出队列，那么顺序队列整体后移，造成的影响是：
顺序队列之前的数组存储空间将无法再被使用，造成了空间浪费；
如果顺序表申请的空间不足够大，则直接造成程序中数组 a 溢出，产生溢出(假溢出)错误；

（方案二）
    a[0]    a[1]    a[2]
    a[7]            a[3]
    a[6]    a[5]    a[4]

本文件实现第一种方案：

队头 front          队尾 rear
|                   |
a    b    c    d    e    
a[0] a[1] a[2] a[3] a[4] a[5] a[6] a[7]

当front = rear时，队列为空
初始时 front = rear = 0
每入队列一个元素 rear++
每出队列一个元素 front++

**********************************************/
#include <stdio.h>
#define SIZE 1000

void enqueue(char c);
void dequeue(void);
int isEmpty(void);

char queue[SIZE];

int main(void)
{
    
    return 0;
}

void enqueue(char c)
{
    queue[rear++] = c;
}
void dequeue(void);
{
    return queue[front++];
}
int isEmpty(void)
{
    return front == rear;
}
