/*******************************************************
双端队列
def：双端队列（deque，全名double-ended queue）
     是一种具有队列和栈性质的抽象数据类型。
     双端队列中的元素可以从两端弹出，
     插入和删除操作限定在队列的两边进行。
下面基于双端队列实现回文判断:
算法：
1.将字符串存储到队列中（队列未满）。
2.从队头出队一个元素，从队尾出队一个元素，进行比较。
3.如果相同，重复操作，直至队列为空，返回是回文。
4.如果遇到不相同，直接返回不是回文。
 *******************************************************/
#include <stdio.h>
#include <string.h>

#define SIZE 100

void push(char c1);      /*  在队列头插入元素    */
void inject(char c2);    /*  在尾端插入元素      */
char pop(void);          /*  在队列头删除元素    */
char eject(void);        /*  在队列尾删除元素    */
int isEmpty(void);
int isFull(void);
int isPalindrome(char *pt);

char* s_gets(char* st, int n);

char deque[SIZE];
int front = 0, rear = 0;

int main(void)
{
    printf("Please enter a string :");

    char str[SIZE];
    s_gets(str, SIZE);

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

void push(char c1)
{
    front = (front - 1 + SIZE) % SIZE;
    deque[front] = c1;
}

void inject(char c2)
{
    deque[rear] = c2;
    rear = (rear + 1) % SIZE;
}

char pop(void)
{
    char c3;
    c3 = deque[front];
    front = (front + 1) % SIZE;
    return c3;
}
int isEmpty(void)
{
    return front == rear;
}

int isFull(void)
{
    return (rear + 1) % SIZE == front;
}

char eject(void)
{
    rear = (rear - 1 + SIZE) % SIZE;
    return deque[rear];
}

int isPalindrome(char *pt)
{

    for (int i = 0; i < strlen(pt); i++)
    {
        if (!isFull())
        {
            push(pt[i]);
        }
    }
    
    while (!isEmpty())
    {
        char ch1, ch2;
        ch1 = pop();
        if (!isEmpty())
        {
            ch2 = eject();
        }
        else
        {
            break;
        }
        if (ch1 == ch2)
        {
            continue;
        }
        else 
            return 0;
    }
    return 1;
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