/*
中缀转后缀，即将一般的运算表达式转换成逆波兰表达式
如：将((1+2)*(3-4))转换成12+34-*
算法：
1.从左至右来处理数据
2.当遇到左括号时，忽略它
3.当遇到数值时，直接输出
4.当遇到操作符时，将操作符入栈
5.当遇到右括号时，出栈栈顶的操作符
*/
#include <stdio.h>
#include <string.h>

#define MAX 10000

char stack[MAX];
int top = 0;

void push(char c);
char pop(void);
int isEmpty(void);
char* s_gets(char* st, int n);

int main(void)
{
    char str[MAX];
    int len;

    printf("Please enter a calcuate notation:");
    s_gets(str, MAX);
    len = strlen(str);
    for (int i = 0; i < MAX; i++)
    {
        if (str[i] == '(')
            continue;
        else if ((str[i] >= '0') && (str[i] <= '9'))
            printf("%c", str[i]);
        else if((str[i] == '+') || (str[i] == '-') || (str[i] == '*'))
			push(str[i]);
		else if(str[i] == ')')
			printf("%c", pop());
        
    }
    printf("\n");

    return 0;
}

void push(char c)
{
    stack[top++] = c;
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