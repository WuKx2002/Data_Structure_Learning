#include <stdio.h>
#include <string.h>

int stack[512];
int top = 0;

void push(int c);
int pop(void);
int is_empty(void);

int main(void)
{
	char a[100];
	int n;
	int i;
	int num1, num2;

	printf("Please enter a reverse polish expression:\n");
	gets(a);
	n = strlen(a);
	
	for(i = 0; i < n; i++)
	{
		if((a[i] >= '0') && (a[i] <= '9'))
			push(a[i] - '0');
		else
		{
			num2 = pop();
			num1 = pop();
			switch(a[i])
			{
				case '+':
					push(num1 + num2);
					break;
				case '-':
					push(num1 - num2);
					break;
				case '*':
					push(num1 * num2);
					break;
			}
		}
	}
	printf("result = %d\n", pop());

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
