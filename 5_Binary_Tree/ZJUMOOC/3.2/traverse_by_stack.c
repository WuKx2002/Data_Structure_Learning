#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;
typedef struct BiTree
{
    Elemtype val;
    struct BiTree *left, *right;
}Node, *Tree;

Tree create_bitree(void);
void preorder_by_stack(Tree p);
void inorder_by_stack(Tree p);
void inorder(Tree p);
void postorder_by_stack(Tree p);



int main(void)
{
    printf("Enter a binary tree : ");
    Tree mytree = create_bitree();
    //inorder(mytree);
    inorder_by_stack(mytree);
    printf("\n");
    preorder_by_stack(mytree);
    printf("\n");
    postorder_by_stack(mytree);
    
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

void inorder(Tree p)
{
    if (p)
    {
        inorder(p->left);
        printf("%c", p->val);
        inorder(p->right);
    }
}

void preorder_by_stack(Tree p)
{
    Tree stack[100];
    int top = 0;
    while (p || top != 0)
    {
       while(p)
       {
           stack[top++] = p;
           printf("%c", p->val);
           p = p->left;
       } 
        if (top != 0)
        {
            p = stack[--top];
            p = p->right;
        }
    }
}

/*��ջ��ʵ���������������
> ����һ����㣬�Ͱ���ѹջ����ȥ����������������
> �����������������󣬴�ջ�����������㲢��������
> Ȼ������ָ����ȥ��������ý�����������
*/

void inorder_by_stack(Tree p)
{
    Tree stack[100];
    int top = 0;
    while (p || top != 0)
    {
       while(p)
       {
           stack[top++] = p;
           p = p->left;
       } 
        if (top != 0)
        {
            p = stack[--top];
            printf("%c", p->val);
            p = p->right;
        }
    }
}
/*
�������ĺ��������������������������Ľ���෴��
���ֻ��Ҫ�õ������ҽ���������ٽ��������򼴿ɡ�
����������ı�������ǰ�����(������)������ͬ��
*/

void postorder_by_stack(Tree p)
{
    Tree stack[100];
    int top = 0;
    Elemtype temp[100];
    int i = 0;
    while (p || top != 0)
    {
       while(p)
       {
           stack[top++] = p;
           temp[i++] = p->val;
           p = p->right;
       } 
        if (top != 0)
        {
            p = stack[--top];
            p = p->left;
        }
    }
    for (;i >= 0; i--)
    {
        printf("%c", temp[i]);
    }
}
