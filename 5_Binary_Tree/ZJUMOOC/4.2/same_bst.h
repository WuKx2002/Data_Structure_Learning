#ifndef SAME_BST_H_
#define SAME_BST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct BiTree
{
    Elemtype val;
    struct BiTree *left, *right;
    int flag;
}Node, *Tree;


Tree new_node(Elemtype x);
Tree insert(Elemtype x, Tree p);
Tree creat_bst(int num_of_nodes);

void preorder(Tree p);
void inorder(Tree p);

int check(Tree p, int x);
int judge(Tree p, int num_of_nodes);


#endif