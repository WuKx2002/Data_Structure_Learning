/*
十进制数转二进数
如：9转换成1001

算法：
1.判断num是否为0
2.如果n不为0，那么n % 2(也就是二进数数的末位)入栈
3.更新n的值，n = n / 2;
4.重复以上操作，直到n = 0停止
5.将栈内的数一次出栈，直至栈为空
*/

#include <stdio.h>
#define MAX 1000

int stack[MAX];
int top = 0;

void push(int a);
int pop(void);
int isEmpty(void);

int main(void)
{
    int num;

    puts("Please enter a decimal number.(q to quit)");
    while (scanf("%d", &num) == 1)
    {
        while (num != 0)
        {
            push(num % 2);
            num /= 2;
        }
        while (!isEmpty())
        {
            printf("%d", pop());
        }
        printf("\n");
        puts("Please enter a decimal number.(q to quit)");
    }
    return 0;
}

void push(int a)
{
    stack[top++] = a;
}
int pop(void)
{
    return stack[--top];
}
int isEmpty(void)
{
    return top == 0;
}