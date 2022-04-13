/*******************************************************
˫�˶���
def��˫�˶��У�deque��ȫ��double-ended queue��
     ��һ�־��ж��к�ջ���ʵĳ����������͡�
     ˫�˶����е�Ԫ�ؿ��Դ����˵�����
     �����ɾ�������޶��ڶ��е����߽��С�
�������˫�˶���ʵ�ֻ����ж�:
�㷨��
1.���ַ����洢�������У�����δ������
2.�Ӷ�ͷ����һ��Ԫ�أ��Ӷ�β����һ��Ԫ�أ����бȽϡ�
3.�����ͬ���ظ�������ֱ������Ϊ�գ������ǻ��ġ�
4.�����������ͬ��ֱ�ӷ��ز��ǻ��ġ�
 *******************************************************/
#include <stdio.h>
#include <string.h>

#define SIZE 100

void push(char c1);      /*  �ڶ���ͷ����Ԫ��    */
void inject(char c2);    /*  ��β�˲���Ԫ��      */
char pop(void);          /*  �ڶ���ͷɾ��Ԫ��    */
char eject(void);        /*  �ڶ���βɾ��Ԫ��    */
int isEmpty(void);
int isFull(void);
int isPalindrome(char *pt);

char* s_gets(char* st, int n);

char deque[SIZE];
int front = 0, rear = 0;

int main(void)
{
    printf("Please enter a string :");

    char str[SIZE];
    s_gets(str, SIZE);

    if (isPalindrome(str))
    {
        puts("The string is a palindrome.");
    }
    else
    {
        puts("The string is not a palindrome.");
    }

    return 0;
}

void push(char c1)
{
    front = (front - 1 + SIZE) % SIZE;
    deque[front] = c1;
}

void inject(char c2)
{
    deque[rear] = c2;
    rear = (rear + 1) % SIZE;
}

char pop(void)
{
    char c3;
    c3 = deque[front];
    front = (front + 1) % SIZE;
    return c3;
}
int isEmpty(void)
{
    return front == rear;
}

int isFull(void)
{
    return (rear + 1) % SIZE == front;
}

char eject(void)
{
    rear = (rear - 1 + SIZE) % SIZE;
    return deque[rear];
}

int isPalindrome(char *pt)
{

    for (int i = 0; i < strlen(pt); i++)
    {
        if (!isFull())
        {
            push(pt[i]);
        }
    }
    
    while (!isEmpty())
    {
        char ch1, ch2;
        ch1 = pop();
        if (!isEmpty())
        {
            ch2 = eject();
        }
        else
        {
            break;
        }
        if (ch1 == ch2)
        {
            continue;
        }
        else 
            return 0;
    }
    return 1;
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