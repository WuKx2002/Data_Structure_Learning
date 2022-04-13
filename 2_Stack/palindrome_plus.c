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
    

    /*预处理字符串：将字母和数字存入字符串*/
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

    /*字符串预处理：大写转小写*/
    len = strlen(s);
    for (i = 0; i < len; i++)
    {
        s[i] = tolower(s[i]);
    }

    puts(s);

    /*开始判断*/
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