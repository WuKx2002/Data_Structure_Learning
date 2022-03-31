/*
逆波兰表示法（Reverse Polish notation，RPN）
在逆波兰记法中，所有操作符置于操作数的后面，因此也被称为后缀表示法。
逆波兰记法不需要括号来标识操作符的优先级。
如：(1+2)*(3-4)用逆波兰表示法为12+34-*
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
        /*如果遇到数字，则数字入栈*/
        if (a[i] >= '0' && a[i] <= '9')
        {
            push(a[i] - '0'); 
        }
        /*如果遇到运算符，则出栈2个数字并且进行运算，将运算结果再次入栈*/
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