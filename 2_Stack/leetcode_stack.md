#### [150. 逆波兰表达式求值](https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/)

根据 逆波兰表示法，求表达式的值。

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

注意 两个整数之间的除法只保留整数部分。

可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

示例 1：
```
输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
```
示例 2：
```
输入：tokens = ["4","13","5","/","+"]
输出：6
解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
```
示例 3：
```
输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
输出：22
解释：该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

```
提示：
```
1 <= tokens.length <= 104
tokens[i] 是一个算符（"+"、"-"、"*" 或 "/"），或是在范围 [-200, 200] 内的一个整数
```

逆波兰表达式：

逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。

平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
逆波兰表达式主要有以下两个优点：

去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中

题解:

```c
#include <stdio.h>
#include <stdlib.h>

int evalRPN(char ** tokens, int tokensSize);
int is_number(char * token);

int is_number(char * token)
{
    return strlen(token) > 1 || ('0' <= token[0] && token[0] <= '9');
}

/*参数为二维字符串，这样可以识别出多位数字。
例如["4","13","5","/","+"]，如果使用一维字符串的形式，13就会被当作1和3处理*/
int evalRPN(char ** tokens, int tokensSize)
{
    /*不将栈定义为全局变量，而是在函数中定义栈，这样可以依据字符串的长度进行设置栈的大小。*/
    int stack[tokensSize];
    int top = 0;

    for (int i = 0; i < tokensSize; i++)
    {
        char * token = tokens[i];
        if (is_number(token))
        {
            stack[top++] = atoi(token);
        }
        else
        {
            int elem2 = stack[--top];
            int elem1 = stack[--top];
            switch(token[0])
            {
                case '+':   stack[top++] = (elem1 + elem2);
                            break;
                case '-':   stack[top++] = (elem1 - elem2);
                            break;
                case '*':   stack[top++] = (elem1 * elem2);
                            break;
                case '/':   stack[top++] = (elem1 / elem2);
                            break;
            }

        }
    }
    return stack[--top];
}
```

#### [125. 验证回文串](https://leetcode-cn.com/problems/valid-palindrome/)

难度简单512

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

**说明：**本题中，我们将空字符串定义为有效的回文串。

**示例 1:**

```
输入: "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串
```

**示例 2:**

```
输入: "race a car"
输出: false
解释："raceacar" 不是回文串
```

**提示：**

- `1 <= s.length <= 2 * 105`
- 字符串 `s` 由 ASCII 字符组成

题解：

```c
bool isPalindrome(char * s)
{
    int n = strlen(s);
    char stack[n];
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

    /*字符串预处理：大写转小写*/
    len = strlen(s);
    for (i = 0; i < len; i++)
    {
        s[i] = tolower(s[i]);
    }

    /*开始判断*/
    for (i = 0; i < (len / 2); i++)
    {
        stack[top++] = s[i];
    }

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
```

