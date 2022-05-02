#include "BiTree.h"

Tree create_bitree(void)
{
	Tree p;
	ElemType ch;
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
			p->elem = ch;
			p->ltree = create_bitree();
			p->rtree = create_bitree();
		}
	}
	return p;
}

void preorder(Tree p)
{
	if (p)
	{
		printf("%c", p->elem);
		preorder(p->ltree);	
		preorder(p->rtree);
	}
}

void inorder(Tree p)
{
	if (p)
	{
		inorder(p->ltree);
		printf("%c", p->elem);
		inorder(p->rtree);
	}
}

void posorder(Tree p)
{
	if (p)
	{
		posorder(p->ltree);
		posorder(p->rtree);
		printf("%c", p->elem);
	}
}

Tree pre_in_restore_bitree(char *pre, char *in, int len)
{
	Tree p;

	if (len == 0)
	{
		return NULL;
	}

	char ch = pre[0];
	int index = 0;
	for (index = 0; in[index] != ch; index++);
	
	p = (Tree)malloc(sizeof(Node));
	p->elem = ch;
	p->ltree = pre_in_restore_bitree(pre + 1, in, index);
	p->rtree = pre_in_restore_bitree(pre + index + 1, in + index + 1, len - index - 1);
}

Tree in_post_restore_bitree(char *in, char *post, int len)
{
	Tree p;

	if (len == 0)
	{
		p = NULL;
	}

	char ch = post[len - 1];
	int index;
	for (index = 0; in[index] != ch; index++);
	p = (Tree)malloc(sizeof(Node));
	p->elem = ch;
	p->ltree = in_post_restore_bitree(in, post, index);
	p->rtree = in_post_restore_bitree(in + index + 1, post + index, len - index - 1);

	return p;
}
