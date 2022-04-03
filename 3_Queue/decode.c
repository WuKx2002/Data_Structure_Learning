/************************************************************
�����ƽ�
��֪һ����������Ǿ������ܺ��һ�����֣���ô����֪���⴮���ܺ����
�֣�����ָ������ƽ�ķ����������ǰ���ֵ������ʲô��

�ƽ�ķ�����
���Ƚ��� 1 ����ɾ���������Ž��� 2 �����ŵ��⴮����ĩβ��
�ٽ��� 3 ����ɾ�������� 4 �����ŵ��⴮����ĩβ��
�ٽ��� 5 ����ɾ��......ֱ��ʣ�����һ�����������һ����Ҳɾ����
���ող�ɾ����˳�򣬰���Щɾ����������һ�����ԭʼ�����ݡ�

���磺123456789 �ƽ��Ϊ 135794862
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

    /*�������������*/
    int i;
    for (i = 0; i < strlen(code); i++)
    {
        if (!isFull())
        {
            enqueue(code[i]);
        }
    }

    /*��ʼ�ƽ�*/
    int j = 0;
    char temp;
    while (!isEmpty())
    {
        /*����������Ԫ�أ���һ���ŵ�code������ڶ�����β�����*/
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

    /*������*/
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