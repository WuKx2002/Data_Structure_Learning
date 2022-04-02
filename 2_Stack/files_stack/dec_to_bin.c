#include <stdio.h>

int stack[512];
int top = 0;

void push(int c);
int pop(void);
int is_empty(void);

int main(void)
{
	int num;

	printf("Please enter an integer in decimal:");
	scanf("%d", &num);

	while(num)
	{
		push(num % 2);
		num /= 2;
	}

	while(!is_empty())
		printf("%d", pop());

	printf("\n");

	return 0;
}

void push(int c)
{
	stack[top++] = c;
}

int pop(void)
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
