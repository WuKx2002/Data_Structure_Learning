/*
�����ж�
���ģ�abba abcdcba

�㷨��
1.�������Ҷ�ȡ�ַ����������ַ������м�ֿ���len / 2
    ż��len��4 / 2 = 2      ab|ba
    ����len��7 / 2  = 3     abc|dcba
    -->������ż������������len / 2 �����Եõ��жԳƵ��ǲ���
2.���ַ���ǰһ��������ջ
    ż��len����ջ1��Ԫ�����ַ�����벿�ֵ�1��Ԫ�رȽϣ�
            -->�ٳ�ջ1��Ԫ�����ַ�����벿�ֵ�2��Ԫ�رȽϣ������ظ���
    ����len����ջ1��Ԫ�����ַ�����벿�ֵ�2��Ԫ�رȽϣ�
            -->�ٳ�ջ1��Ԫ�����ַ�����벿�ֵ�3��Ԫ�رȽϣ������ظ���
3.�ȽϹ����У�һ��������ͬ��Ԫ�أ�ֱ���ж����ǻ��ģ�
    ��ջ�Ѿ�Ϊ�գ����г�ջ��Ԫ�ض�ƥ�䵽����ͬԪ�أ��򷵻��ǻ��ġ�
    
*/
#include <stdio.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = 0;

void push(char str);
char pop(void);
int isEmpty(void);
char* s_gets(char* st, int n);
int isPalindrome(char str[]);

int main(void)
{
    char str[MAX];

    puts("Please enter a string.");
    s_gets(str, MAX);

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
void push(char str)
{
    stack[top++] = str;
}
char pop(void)
{
    return stack[--top];
}
int isEmpty(void)
{
    return top == 0;
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
int isPalindrome(char str[])
{
    int len = strlen(str);
    int i;
    for (i = 0; i < (len / 2); i++)
    {
        push(str[i]);
    }
    if (len % 2 != 0)
    {
        i++;
    }
    while(!isEmpty())
	{
		if(pop() == str[i])
        {
            i++;
        }
		else
        {
            return 0;
        }
	}
	return 1;
}