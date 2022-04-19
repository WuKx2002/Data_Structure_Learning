#include "BiTree.h"

Tree pre = NULL;/*始终指向刚刚访问过的结点*/

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
		in_order(p->ltree);
		printf("%c", p->elem);
		in_order(p->rtree);
	}
}

/*中序线索化*/
void in_threading(Tree p)
{
	if (p)
	{
		in_threading(p->ltree);
		if (!p->ltree)
		{
			p->lflag = 1;
			p->ltree = pre;
		}
		else
		{
			p->lflag = 0;
		}
		if(pre)
		{
			if (!pre->rtree)
			{
				pre->rflag = 1;
				pre->rtree = p;
			}
			else
			{
				pre->lflag = 0;
			}
		}
		pre = p;
		in_threading(p->rtree);
	}
}

/*创建线索二叉树*/
void create_in_threading_bitree(Tree p)
{
	if (p)
	{
		in_threading(p);
		pre->rtree = NULL;
		pre->rflag = 1;
	}
}

/*遍历中序线索二叉树*/
void in_order_threading(Tree p)
{
	while (p)
	{
		while (p->lflag == 0)
		{
			p = p->ltree;
		}
		printf("%c ", p->elem);
		while ((p->rflag == 1) && (p->rtree))
		{
			p = p->rtree;
			printf("%c ", p->elem);
		}
		p = p->rtree;

	}
}

/*void in_order_threading(Tree T)
{
	Tree p;
	p = T->ltree;
	while (p != T)
	{
		while (p->lflag == 0)
		{
			p = p->ltree;
		}
		printf("%c", p->elem);
		while (p->rflag == 1 && p->rtree != T)
		{
			p = p->rtree;
			printf("%c", p->elem);
		}
		p = p->rtree;
	}
}*/

Tree search_inorder_threading_node(Tree p, ElemType elem)
{
	Tree ret;
	while (p)
	{
		while (p->lflag == 0)
		{
			p = p->ltree;
		}
		if (p->elem == elem)
		{
			ret = p;
		}
		while ((p->rflag == 1) && (p->rtree))
		{
			p = p->rtree;
			if (p->elem == elem)
			{
				ret = p;
			}
		}
		p = p->rtree;
	}
	return ret;
}

Tree in_threading_bitree_pre_node(const Tree node)
{
	Tree nd, ret;

	if (node->lflag == 1)
	{
		ret = node->ltree; 
	}
	else
	{
		nd = node->ltree;
		while (nd->rflag == 0)
		{
			nd = nd->rtree;
		}
		ret = nd;
	}
	return ret;
}

Tree in_threading_bitree_succ_node(const Tree node)
{
	Tree nd, ret;

	if (node->rflag == 1)
	{
		ret = node->rtree; 
	}
	else
	{
		nd = node->rtree;
		while (nd->lflag == 0)
		{
			nd = nd->ltree;
			ret = nd;
		}
	}
	return ret;
}
