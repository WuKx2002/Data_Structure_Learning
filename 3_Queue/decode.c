/************************************************************
密码破解
已知一个数列组合是经过加密后的一串数字，那么现在知道这串加密后的数
字，并且指导如何破解的方法，求加密前数字的组合是什么。

破解的方法：
首先将第 1 个数删除，紧接着将第 2 个数放到这串数的末尾，
再将第 3 个数删除并将第 4 个数放到这串数的末尾，
再将第 5 个数删除......直到剩下最后一个数，将最后一个数也删除。
按照刚才删除的顺序，把这些删除的数连在一起就是原始的数据。

例如：123456789 破解后为 135794862
*************************************************************/
#include <stdio.h>
#include <string.h>

#define SIZE 10

char queue[SIZE];
int front = 0, rear = 0;

void enqueue(char c);
char dequeue(void);
int isEmpty(void);
int isFull(void);
char* s_gets(char* st, int n);

int main(void)
{
    char code[SIZE];

    printf("Please enter the password to be cracked :");
    s_gets(code, SIZE);

    /*所有数字入队列*/
    int i;
    for (i = 0; i < strlen(code); i++)
    {
        if (!isFull())
        {
            enqueue(code[i]);
        }
    }

    /*开始破解*/
    int j = 0;
    char temp;
    while (!isEmpty())
    {
        /*出队列两个元素，第一个放到code数组里，第二个置尾入队列*/
        code[j++] = dequeue();
        if (!isEmpty())
        {
            temp = dequeue();
            if (!isFull())
            {
                enqueue(temp);
            }
        }
    }

    /*输出结果*/
    printf("Orignal code is :");
    int k;
    for (k = 0; k < strlen(code); k++)
    {
        printf("%c", code[k]);
    }
    printf("\n");

    return 0;
}

void enqueue(char c1)
{
    queue[rear] = c1;
    rear = (rear + 1) % SIZE;
}

char dequeue(void)
{
    char c2;
    c2 = queue[front];
    front = (front + 1) % SIZE;
    return c2;
}

int isEmpty(void)
{
    return front == rear;
}

int isFull(void)
{
    return (rear + 1) % SIZE == front;
}

char* s_gets(char* st, int n)
{
    char* ret_val;
    char i = 0;

    //char *fgets(char *str, int n, FILE *stream)
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
        {
            i++;
        }
        if (st[i] == '\n')
        {
            st[i] = '\0';
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }

    }
    return ret_val;
}