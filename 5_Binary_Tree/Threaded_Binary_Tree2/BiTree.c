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

void inorder(Tree p)
{
	if (p)
	{
		inorder(p->ltree);
		printf("%c", p->elem);
		inorder(p->rtree);
	}
}

Tree pre = NULL;
void inthreading(Tree p)
{
	if (p)
	{
		inthreading(p->ltree);
		if (!p->ltree)
		{
			p->lflag = 1;
			p->ltree = pre;
		}
		else
		{
			p->lflag = 0;
		}
		if (pre)
		{
			if (!pre->rtree)
			{
				pre->rflag = 1;
				pre->rtree = p;
			}
			else
			{
				pre->rflag = 0;
			}
		}
		pre = p;
		inthreading(p->rtree);
	}
}


void create_inthreading_bitree(Tree p)
{
	if (p)
	{
		inthreading(p);
		pre->rtree = NULL;
		pre->rflag = 1;
	}
}

Tree search_node(Tree p, ElemType ch)
{
	Tree ret;
	while (p)
	{
		while (p->lflag == 0)
		{
			p = p->ltree;
		}
		if (p->elem == ch)
		{
			ret = p;
		}
		while (p->rflag == 1 && p->rtree)
		{
			p = p->rtree;
			if (p->elem == ch)
			{
				ret = p;
			}
		}
		p = p->rtree;
	}
	printf("Finish searching %c.\n", ret->elem);
	return ret;
}

Tree inthreading_prenode(const Tree node)
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
Tree inthreading_succnode(const Tree node)
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
		}
		ret = nd;
	}
	return ret;
}



