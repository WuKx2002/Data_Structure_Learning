/*
����ƥ��
���磬������ʽ((1+2)*(3+4))*5
���ƥ�������:

�㷨��
�������Ҷ�ȡ���ʽ��ÿ���ַ���
����������������ַ������ԡ�
���������ţ������Ӧ�����������ջ��
���������ţ����ջһ����������������������ŵ�������Ӧ�����
*/
#include <stdio.h>
#include <string.h>
#define MAX 1000

int stack[MAX];
int top = 0;

void push(int i);
int pop(void);
char* s_gets(char* st, int n);

int main(void)
{
    char str[MAX];
    int len;

    printf("Please enter a calcuate notation:");
    s_gets(str, MAX);
    len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
        {
            push(i);   
        }
        else if (str[i] == ')')
        {
            printf("%d %d\n", pop(), i);
        }
    }
    return 0;
}

void push(int i)
{
    stack[top++] = i;
}
int pop(void)
{
    return stack[--top];
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
