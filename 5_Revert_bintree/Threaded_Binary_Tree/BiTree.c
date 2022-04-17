#include "BiTree.h"

Tree create_bitree(void)
{
	Tree p;
	char ch;
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

void pre_order(Tree p)
{
	if (p)
	{
		printf("%c", p->elem);
		pre_order(p->ltree);
		pre_order(p->rtree);
	}
}

void in_order(Tree p)
{
	if (p)
	{
		pre_order(p->ltree);
		printf("%c", p->elem);
		pre_order(p->rtree);
	}
}

/*中序线索化*/
void in_threading(Tree p)
{
	Tree pre = NULL;/*始终指向刚刚访问过的结点*/
	p->lflag = p->rflag = 0;
	if (p)
	{
		in_threading(p->ltree);
		if (!p->ltree)
		{
			p->ltree = pre;
			p->lflag = 1;
		}
		if (!pre->rtree)
		{
			pre->rtree = p;
			pre->rflag = 1;
		}
		pre = p;
		in_threading(p->rtree);
	}
}

/*遍历中序线索二叉树*/
void inorder_threading(Tree p)
{
	while (p)
	{
		while (p->lflag == 0)
		{
			p = p->ltree;
			printf("%c", p->elem);
		}
		while (p->rflag == 1 && p->rtree != NULL)
		{
			p = p->rtree;
			printf("%c", p->elem);
		}
		p = p->rtree;
	}
}
