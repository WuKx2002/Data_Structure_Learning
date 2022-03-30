/*2.1 The principle of stack——push & pop*/
#include <stdio.h>

char stack[10];
/*Top of the stack*/
int top = 0;

void push(char c);
char pop(void);
int isEmpty(void);  

int main(void)
{
    /*a,b,c依次入栈*/
    push('a');
    push('b');
    push('c');
    /*出栈*/
    while (!isEmpty())
    {
        putchar(pop());
    }
    return 0;
}

/*入栈*/
void push(char c)    
{
    stack[top++] = c;
}

/*出栈*/
char pop(void)
{
    return stack[--top];
}

/*判断栈是否为空*/
int isEmpty(void)
{
    return top == 0;
}