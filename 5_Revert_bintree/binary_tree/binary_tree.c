/*二叉树的创建和遍历*/
#include <stdio.h>
#include <stdlib.h>

struct BiTree_node* create_BiTree(void);
void pre_order(struct BiTree_node* tree);
void in_order(struct BiTree_node* tree);
void post_order(struct BiTree_node* tree);

/*二叉树结点*/
struct BiTree_node
{
    unsigned char elem;
    struct BiTree_node* left, * right;
};

int main(void)
{
    struct BiTree_node* mytree;
    mytree = create_BiTree();
    pre_order(mytree);
    in_order(mytree);
    post_order(mytree);

    return 0;
}

/*创建二叉树*/
struct BiTree_node* create_BiTree(void)
{
    struct BiTree_node* tree;
    tree = (struct BiTree_node*)malloc(sizeof(struct BiTree_node));

    printf("Input the elem of the node : ");
    while ((tree->elem = getchar()) == '\n');

    unsigned char flag;
    printf("Do you want to insert a left tree for %c (Y or N) : ", tree->elem);
    while((flag = getchar()) == '\n');
    if (flag == 'Y')
    {
        tree->left = create_BiTree();
    }
    else
    {
        tree->left = NULL;
    }
    
    printf("Do you want to insert a right tree for %c (Y or N) : ", tree->elem);
    while((flag = getchar()) == '\n');
    if (flag == 'Y')
    {
        tree->right = create_BiTree();
    }
    else
    {
        tree->right = NULL;
    }
    return tree;
}

/*先序遍历二叉树*/
void pre_order(struct BiTree_node* tree)
{
    if (tree)
    {
       /*访问根节点*/
        printf("%c\n", tree->elem);
        /*先序遍历左子树*/
        pre_order(tree->left);
        /*先序遍历右子树*/
        pre_order(tree->right); 
    }
}

/*中序遍历二叉树*/
void in_order(struct BiTree_node* tree)
{
    if (tree)
    {
        /*中序遍历左子树*/
        in_order(tree->left);
        /*访问根节点*/
        printf("%c\n", tree->elem);
        /*中序遍历右子树*/
        in_order(tree->right);
    }
}

/*后序遍历二叉树*/
void post_order(struct BiTree_node* tree)
{
    if (tree)
    {
        /*后序遍历左子树*/
        post_order(tree->left);
        /*后序遍历右子树*/
        post_order(tree->right);
        /*访问根节点*/
        printf("%c\n", tree->elem);
    }
}