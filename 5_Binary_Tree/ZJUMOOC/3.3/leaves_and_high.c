#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;
typedef struct BiTree
{
    Elemtype val;
    struct BiTree *left, *right;
}Node, *Tree;

Tree create_bitree(void);
void print_leaves(Tree p);
int print_high(Tree p);

int main(void)
{
    Tree mytree;
    printf("Please enter a binary tree : ");
    mytree = create_bitree();

    printf("leaves : ");
    print_leaves(mytree);
    printf("\n");

    printf("high : ");
    printf("%d", print_high(mytree));
    printf("\n");

    return 0;
}

Tree create_bitree(void)
{
    Tree p;
    char ch;
    scanf("%c", &ch);

    if (ch == '#')
    {
        p = NULL;
    } 
    else
    {
        p = (Tree)malloc(sizeof(Node));
        if (p)
        {
            p->val = ch;
            p->left = create_bitree();
            p->right = create_bitree();
        }  
    }
    return p;
}

/*������һ�ֱ����Ļ����ϸ��죬Ҫ������������Ϊ���������㼴�ɡ�������ǰ�����Ϊ����*/
void print_leaves(Tree p)
{
    if (p)
    {   
        if (!p->left && !p->right)
        {
            printf("%c", p->val);
        }
        print_leaves(p->left);
        print_leaves(p->right);
    }
}

/*���������=max{��������ȣ����������}+1����Ҫͬʱ֪������������ȣ����ں�����������ϸ���*/
int print_high(Tree p)
{
    int high_left, high_right, high;
    if (p)
    {
        high_left = print_high(p->left);
        high_right = print_high(p->right); 
        high = (high_left > high_right) ? high_left : high_right;
        return (high + 1);
    }
    return 0;
}
