/*�������Ĵ����ͱ���*/
#include <stdio.h>
#include <stdlib.h>

struct BiTree_node* create_BiTree(void);
void pre_order(struct BiTree_node* tree);
void in_order(struct BiTree_node* tree);
void post_order(struct BiTree_node* tree);

/*���������*/
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

/*����������*/
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

/*�������������*/
void pre_order(struct BiTree_node* tree)
{
    if (tree)
    {
       /*���ʸ��ڵ�*/
        printf("%c\n", tree->elem);
        /*�������������*/
        pre_order(tree->left);
        /*�������������*/
        pre_order(tree->right); 
    }
}

/*�������������*/
void in_order(struct BiTree_node* tree)
{
    if (tree)
    {
        /*�������������*/
        in_order(tree->left);
        /*���ʸ��ڵ�*/
        printf("%c\n", tree->elem);
        /*�������������*/
        in_order(tree->right);
    }
}

/*�������������*/
void post_order(struct BiTree_node* tree)
{
    if (tree)
    {
        /*�������������*/
        post_order(tree->left);
        /*�������������*/
        post_order(tree->right);
        /*���ʸ��ڵ�*/
        printf("%c\n", tree->elem);
    }
}