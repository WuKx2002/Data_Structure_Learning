/*
ʮ������ת������
�磺9ת����1001

�㷨��
1.�ж�num�Ƿ�Ϊ0
2.���n��Ϊ0����ôn % 2(Ҳ���Ƕ���������ĩλ)��ջ
3.����n��ֵ��n = n / 2;
4.�ظ����ϲ�����ֱ��n = 0ֹͣ
5.��ջ�ڵ���һ�γ�ջ��ֱ��ջΪ��
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