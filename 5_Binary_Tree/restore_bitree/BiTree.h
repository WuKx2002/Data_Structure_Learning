#ifndef BITREE_H_
#define BITREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTree
{
	ElemType elem;
	struct BiTree *ltree, *rtree;
	int lflag, rflag;
}Node, *Tree;

Tree create_bitree(void);
void preorder(Tree p);
void inorder(Tree p);
void posorder(Tree p);
Tree pre_in_restore_bitree(char *pre, char *in, int len);
Tree in_post_restore_bitree(char *in, char *post, int len);

#endif
