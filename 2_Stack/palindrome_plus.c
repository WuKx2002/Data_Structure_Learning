#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool isPalindrome(char * s);

int main(void)
{
    char s[] = "A man, a plan, a canal: Panama";
    int a = isPalindrome(s);
    printf("%d", a);
    return 0;
}
bool isPalindrome(char * s)
{
    printf("%d", strlen(s));
    char stack[50];
    int top = 0;
    

    /*Ԥ�����ַ���������ĸ�����ִ����ַ���*/
    int len = strlen(s);
    int i = 0, j = 0;

    for (i = 0; i < len; i++)
    {
        if (isalnum(s[i]))
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';

    puts(s);

    /*�ַ���Ԥ������дתСд*/
    len = strlen(s);
    for (i = 0; i < len; i++)
    {
        s[i] = tolower(s[i]);
    }

    puts(s);

    /*��ʼ�ж�*/
    for (i = 0; i < (len / 2); i++)
    {
        stack[top++] = s[i];
    }

    puts(stack);

    if ((len % 2) != 0)
    {
        i++;
    }
    
    while (top != 0)
    {
        if (stack[--top] == s[i++])
            continue;
        else
            return false;
    }
    return true;
}