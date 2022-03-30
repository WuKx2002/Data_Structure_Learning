/*2.1 The principle of stack����push & pop*/
#include <stdio.h>

char stack[10];
/*Top of the stack*/
int top = 0;

void push(char c);
char pop(void);
int isEmpty(void);  

int main(void)
{
    /*a,b,c������ջ*/
    push('a');
    push('b');
    push('c');
    /*��ջ*/
    while (!isEmpty())
    {
        putchar(pop());
    }
    return 0;
}

/*��ջ*/
void push(char c)    
{
    stack[top++] = c;
}

/*��ջ*/
char pop(void)
{
    return stack[--top];
}

/*�ж�ջ�Ƿ�Ϊ��*/
int isEmpty(void)
{
    return top == 0;
}