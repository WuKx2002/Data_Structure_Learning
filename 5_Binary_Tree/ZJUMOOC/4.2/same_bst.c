#include "same_bst.h"

Tree new_node(Elemtype x)
{
    Tree p;
    p = (Tree)malloc(sizeof(Node));
    p->val = x;
    p->left = p->right = NULL;
    p->flag = 0;
    return p;
}

Tree insert(Elemtype x, Tree p)
{
    if (!p)
        p = new_node(x);
    else
    {
        if (x > p->val)
            p->right = insert(x, p->right);
        else if (x < p->val)
            p->left = insert(x, p->left);
    }
    return p;
}

Tree creat_bst(int num_of_nodes)
{
    Elemtype x;
    printf("Node 1 : ");
    scanf("%d", &x);
    Tree p = new_node(x);

    int i;
    for (i = 1; i < num_of_nodes; i++)
    {
        printf("Node %d : ", i + 1);
        scanf("%d", &x);
        p = insert(x, p);
    }
    return p;
}

void preorder(Tree p)
{
    if (p)
    {
        printf("%d", p->val);
        preorder(p->left);
        preorder(p->right);
    }  
}

void inorder(Tree p)
{
    if (p)
    {
        inorder(p->left);
        printf("%d", p->val);
        inorder(p->right);
    }
}

int check(Tree p, int x)
{
    if (p->flag)
    {
        if (x < p->val)
            return check(p->left, x);
        else if (x > p->val)
            return check(p->right, x);
    }
    else
    {
        if (x == p->val)
        {
            p->flag = 1;
            return 1;
        }
        else 
            return 0;
    }
}

int judge(Tree p, int num_of_nodes)
{
    int x;
    int tag = 1;

    printf("Node 1 :");
    scanf("%d", &x);
    if (x != p->val)
        tag = 0;
    else
        p->flag = 1;
    int i;
    for (i = 1; i < num_of_nodes; i++)
    {
        printf("Node %d :", i + 1);
        scanf("%d", &x);
        if ((!tag) && (!check(p, x)))
            tag = 0;
    }
    if (tag)
        return 1;
    else
        return 0;
}