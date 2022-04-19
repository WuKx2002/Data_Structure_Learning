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
void inorder(Tree p);
void inthreading(Tree p);
void create_inthreading_bitree(Tree p);
Tree search_node(Tree p, ElemType ch);
Tree inthreading_prenode(const Tree node);
Tree inthreading_succnode(const Tree node);


#endif
