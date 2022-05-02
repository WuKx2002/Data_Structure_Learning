#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;
typedef struct BiTree
{
    Elemtype val;
    struct BiTree *left, *right;
}Node, *Tree;

Tree create_bitree(void);
void preorder(Tree p);
void level_order_traverse(Tree p);

int main(void)
{
    Tree mytree;
    printf("Please enter a binary tree : ");
    mytree = create_bitree();

    printf("preorder : ");
    preorder(mytree);
    printf("\n");

    printf("level order traverse : ");
    level_order_traverse(mytree);
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

void preorder(Tree p)
{
    if (p)
    {   
        printf("%c", p->val);
        preorder(p->left);
        preorder(p->right);
    }
}

void level_order_traverse(Tree p)
{
    if (!p) return;
    Tree queue[100];
    Tree temp;
    int front = 0, rear = 0;

    queue[rear++] = p;
    temp = queue[front++];
    printf("%c", temp->val);
    level_order_traverse(temp->left);
    level_order_traverse(temp->right);
}