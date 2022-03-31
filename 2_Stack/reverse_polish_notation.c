/*
�沨����ʾ����Reverse Polish notation��RPN��
���沨���Ƿ��У����в��������ڲ������ĺ��棬���Ҳ����Ϊ��׺��ʾ����
�沨���Ƿ�����Ҫ��������ʶ�����������ȼ���
�磺(1+2)*(3-4)���沨����ʾ��Ϊ12+34-*
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

int stack[MAX];
int top = 0;

void push(int num);
int pop(void);
bool isEmpty(void);
char* s_gets(char* st, int n);

int main(void)
{
    char a[MAX];
    int len;
    int num1,num2;

    puts("PLease enter a reverse polish notation.");
    s_gets(a, MAX);
    len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        /*����������֣���������ջ*/
        if (a[i] >= '0' && a[i] <= '9')
        {
            push(a[i] - '0'); 
        }
        /*�����������������ջ2�����ֲ��ҽ������㣬���������ٴ���ջ*/
        else
        {
            num2 = pop();
            num1 = pop();
            switch(a[i])
            {
                case '+':   push(num1 + num2);
                            break;
                case '-':   push(num1 - num2);
                            break;
                case '*':   push(num1 * num2);
                            break;
                case '/':   push(num1 / num2);
                            break;
            }
        }
    }
    printf("result = %d\n", pop());

    return 0;
}   

void push(int num)
{
    stack[top++] = num;
}
int pop(void)
{
    return stack[--top];
}
bool isEmpty(void)
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