#ifndef BITREE_H_
#define BITREE_H_
#include <stdio.h>
#include <stdlib.h>

struct BiTree_node
{
	unsigned char elem;
	struct BiTree_node* left, * right;
};

struct BiTree_node* create_BiTree(void);
void pre_order(struct BiTree_node* tree);
void in_order(struct BiTree_node* tree);
void post_order(struct BiTree_node* tree);
void lvl_order(struct BiTree_node* tree);
unsigned int depth(struct BiTree_node* tree);
unsigned int leaves(struct BiTree_node* tree);
unsigned int nodes(struct BiTree_node* tree);
#endif