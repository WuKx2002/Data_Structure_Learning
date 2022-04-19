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
void create_in_threading_bitree(Tree p);
void in_order_threading(Tree p);
//void in_order_threading(Tree T);
Tree search_inorder_threading_node(Tree p, ElemType elem);
Tree in_threading_bitree_pre_node(const Tree node);
Tree in_threading_bitree_succ_node(const Tree node);

#endif
