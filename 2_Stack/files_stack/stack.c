#include <stdio.h>

char stack[512];
int top = 0;

void push(char c);
char pop(void);
int is_empty(void);

int main(void)
{
	push('a');
	push('b');
	push('c');

	while(!is_empty())
	{
		putchar(pop());
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

int is_empty(void)
{
/*
	if(top == 0)
		return 1;
	else
		return 0;
*/
	return top == 0;
}
