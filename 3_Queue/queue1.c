/**********************************************
˳�����
���ģ������ȳ���������
�������˳��a[0] a[1] a[2]...
  ������˳��a[0] a[1] a[2]...

������һ��
a    b    c    d    e    f    g    h
a[0] a[1] a[2] a[3] a[4] a[5] a[6] a[7]

ȱ�㣺
���a, b, c�����У���ô˳�����������ƣ���ɵ�Ӱ���ǣ�
˳�����֮ǰ������洢�ռ佫�޷��ٱ�ʹ�ã�����˿ռ��˷ѣ�
���˳�������Ŀռ䲻�㹻����ֱ����ɳ��������� a ������������(�����)����

����������
    a[0]    a[1]    a[2]
    a[7]            a[3]
    a[6]    a[5]    a[4]

���ļ�ʵ�ֵ�һ�ַ�����

��ͷ front          ��β rear
|                   |
a    b    c    d    e    
a[0] a[1] a[2] a[3] a[4] a[5] a[6] a[7]

��front = rearʱ������Ϊ��
��ʼʱ front = rear = 0
ÿ�����һ��Ԫ�� rear++
ÿ������һ��Ԫ�� front++

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
