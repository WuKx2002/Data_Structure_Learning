/*
回文判定
回文：abba abcdcba

算法：
1.从左至右读取字符串，并将字符串从中间分开，len / 2
    偶数len：4 / 2 = 2      ab|ba
    奇数len：7 / 2  = 3     abc|dcba
    -->不管是偶数还是奇数，len / 2 都可以得到有对称的那部分
2.将字符串前一半依次入栈
    偶数len：出栈1个元素与字符串后半部分第1个元素比较，
            -->再出栈1个元素与字符串后半部分第2个元素比较，不断重复。
    奇数len：出栈1个元素与字符串后半部分第2个元素比较，
            -->再出栈1个元素与字符串后半部分第3个元素比较，不断重复。
3.比较过程中，一旦遇到不同的元素，直接判定不是回文；
    若栈已经为空，所有出栈的元素都匹配到了相同元素，则返回是回文。
    
*/
#include <stdio.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = 0;

void push(char str);
char pop(void);
int isEmpty(void);
char* s_gets(char* st, int n);
int isPalindrome(char str[]);

int main(void)
{
    char str[MAX];

    puts("Please enter a string.");
    s_gets(str, MAX);

    if (isPalindrome(str))
    {
        puts("The string is a palindrome.");
    }
    else
    {
        puts("The string is not a palindrome.");
    }

    return 0;
}
void push(char str)
{
    stack[top++] = str;
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
int isPalindrome(char str[])
{
    int len = strlen(str);
    int i;
    for (i = 0; i < (len / 2); i++)
    {
        push(str[i]);
    }
    if (len % 2 != 0)
    {
        i++;
    }
    while(!isEmpty())
	{
		if(pop() == str[i])
        {
            i++;
        }
		else
        {
            return 0;
        }
	}
	return 1;
}