#ifndef BITREE_H_
#define BITREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char ElemType;

typedef struct BiTree
{
	ElemType elem;
	struct BiTree *ltree, *rtree;
	int lflag, rflag;
} Node, *Tree;

Tree create_bitree(void);
void pre_order(Tree p);
void in_order(Tree p);
void in_threading(Tree p);
void inorder_threading(Tree p);

#endif
