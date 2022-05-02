#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct BiTree
{
    Elemtype val;
    struct BiTree *left, *right;
}Node, *Tree;

Tree insert(Elemtype x, Tree p);
void preorder(Tree p);

Tree minimum(Tree p);
void print_minimum(Tree p);

Tree maximum(Tree p);
void print_maximum(Tree p);

Tree find(Elemtype x, Tree p);
void print_find(Tree p);

Tree delete(Elemtype x, Tree p);

int main(void)
{
    Tree mytree = NULL;

    int nodes;
    printf("Now let's create a binary search tree !\n");
    printf("How many nodes does the tree have ?\n");
    scanf("%d", &nodes);

    int i;
    int x;
    Tree temp = mytree;
    for (i = 0; i < nodes; i++)
    {
        printf("Please enter value %d : ", i + 1);
        scanf("%d", &x);
        mytree = insert(x, mytree);
    }

    printf("Congratulations on you have successfully created a binary search tree !\n");
    
    printf("preorder : ");
    preorder(mytree);
    printf("\n");

    print_minimum(minimum(mytree));
    print_maximum(maximum(mytree));

    printf("Now, which node do you want to find : ");
    scanf("%d", &x);
    print_find(find(x, mytree));

    printf("Now, which node do you want to insert : ");
    scanf("%d", &x);
    insert(x, mytree);
    printf("Finsh inserting the node.\n");
    printf("preorder : ");
    preorder(mytree);
    printf("\n");

    printf("Now, which node do you want to deldete : ");
    scanf("%d", &x);
    mytree = delete(x, mytree);
    printf("preorder : ");
    preorder(mytree);
    printf("\n");


    return 0;
}

Tree insert(Elemtype x, Tree p)
{
    if (!p)
    {
        p = (Tree)malloc(sizeof(Node));
        p->val = x;
        p->left = p->right = NULL;
    }
    else
    {
        if (x < p->val)
            p->left = insert(x, p->left);
        if (x > p->val)
            p->right = insert(x, p->right);
    }
    
    return p;
}

void preorder(Tree p)
{
    if (p)
    {
        printf("%d ", p->val);
        preorder(p->left);
        preorder(p->right);
    }
}

Tree maximum(Tree p)
{
    if (p)
    {
        while (p->right)
            p = p->right;
    }
    return p;
}

void print_maximum(Tree p)
{
    if (!p)
        printf("Sorry, the tree is empty.\n");
    else   
        printf("MAX : %d\n", p->val);
}

Tree minimum(Tree p)
{
    if (!p)
        return NULL;
    else if (!p->left)
        return p;
    else
        return minimum(p->left);
}


void print_minimum(Tree p)
{
    if (!p)
        printf("Sorry, the tree is empty.\n");
    else   
        printf("MIN : %d\n", p->val);
}

Tree find(Elemtype x, Tree p)
{
    if (p)
    {
        if (x > p->val)
            return  find(x, p->right);
        else if (x < p->val)
            return find(x, p->left);
        else
            return p;
    }
}

void print_find(Tree p)
{
    if (!p)
        printf("Not Found !\n");
    else
        printf("Find %d.\n", p->val);
}

Tree delete(Elemtype x, Tree p)
{
    Tree temp;
    if (!p)
        printf("Not Found %d", x);
    else if (x < p->val)
        p->left = delete(x, p->left);
    else if (x > p->val)
        p->right = delete(x, p->right);
    else 
        if (p->left && p->right)
        {
            temp = minimum(p->right);
            p->val = temp->val;
            p->right = delete(p->val, p->right);
        }
        else
        {
            temp = p;
            if (!p->left)
                p = p->right;
            else if (!p->right)
                p = p->left;
            free(temp);
        }
    return p;
}