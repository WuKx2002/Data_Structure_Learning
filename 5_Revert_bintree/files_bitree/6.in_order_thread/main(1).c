#include <stdio.h>
#include <stdlib.h>

struct BinTree_node
{
	unsigned char elem;
	struct BinTree_node *ltree, *rtree;
	int lflag, rflag;
};

struct BinTree_node *pre = NULL;

void pre_order(struct BinTree_node *tree);
void in_order(struct BinTree_node *tree);
void pos_order(struct BinTree_node *tree);

struct BinTree_node *create_bintree(void); //ask_method
struct BinTree_node *Create_BinTree(void); //fill_blank_method
void In_order_Thread(struct BinTree_node *tree);
void Create_Inorder_Thread(struct BinTree_node *T);
void Traverse_Inorder_Thread(struct BinTree_node *tree);
struct BinTree_node *Search_Inorder_Thread(struct BinTree_node *tree, char ch);
struct BinTree_node *Prenode_Inorder_Thread(const struct BinTree_node *node);
struct BinTree_node *Succnode_Inorder_Thread(const struct BinTree_node *node);

int main(void)
{
	struct BinTree_node *mytree;
	char ch;
	struct BinTree_node *node, *precursor, *succeed;

	printf("Please input a preorder binary tree(with fill blank #):\n");
	mytree = Create_BinTree();
	pre_order(mytree);
	printf("\n");

	Create_Inorder_Thread(mytree);
	printf("Traverse Inorder_Thread Tree:");
	Traverse_Inorder_Thread(mytree);
	printf("\n");

	printf("Please enter the node that you want to find it's pre & succ node:\n");
	while((ch = getchar()) == '\n');
	node = Search_Inorder_Thread(mytree, ch);

	precursor = Prenode_Inorder_Thread(node);
	if(precursor == NULL)
		printf("node %c has no precursor node\n", node->elem);
	else
		printf("Precursor node = %c\n", precursor->elem);

	succeed = Succnode_Inorder_Thread(node);
	if(succeed == NULL)
		printf("node %c has not succeed node\n", node->elem);
	else
		printf("Succeed node = %c\n", succeed->elem);

	return 0;
}

struct BinTree_node *create_bintree(void)
{
	unsigned char flag;
	struct BinTree_node *tree;

	tree = (struct BinTree_node *)malloc(sizeof(struct BinTree_node));
	printf("Please input the node elem:\n");
	while((tree->elem = getchar()) == '\n');
	printf("Do you want to insert l_tree for %c, (Y/N)?\n", tree->elem);
	while((flag = getchar()) == '\n');

	if(flag == 'Y')
		tree->ltree = create_bintree();
	else
		tree->ltree = NULL;

	printf("Do you want to insert r_tree for %c, (Y/N)?\n", tree->elem);
	while((flag = getchar()) == '\n');

	if(flag == 'Y')
		tree->rtree = create_bintree();
	else
		tree->rtree = NULL;

	return tree;
}

struct BinTree_node *Create_BinTree(void) //fill_blank_method
{
	char ch;
	struct BinTree_node *tree;

	scanf("%c", &ch);

	if(ch == '#')
		tree = NULL;
	else
	{
		tree = (struct BinTree_node *)malloc(sizeof(struct BinTree_node));
		tree->elem = ch;
		tree->ltree = Create_BinTree();
		tree->rtree = Create_BinTree();
	}

	return tree;
}

void pre_order(struct BinTree_node *tree)
{
	if(tree)
	{
		printf("%c", tree->elem);
		pre_order(tree->ltree);
		pre_order(tree->rtree);
	}
}

void in_order(struct BinTree_node *tree)
{
	if(tree)
	{
		in_order(tree->ltree);
		printf("%c", tree->elem);
		in_order(tree->rtree);
	}
}

void pos_order(struct BinTree_node *tree)
{
	if(tree)
	{
		pos_order(tree->ltree);
		pos_order(tree->rtree);
		printf("%c", tree->elem);
	}
}

void In_order_Thread(struct BinTree_node *tree)
{
	if(tree)
	{
		//1.Do_Inorder_Thread to ltree
		In_order_Thread(tree->ltree);

		//2.Deal with current node, 
		if(!tree->ltree)
		{
			tree->lflag = 1;
			//current node's ltree points to the pre node
			tree->ltree = pre;
		}
		else
			tree->lflag = 0;

		if(pre)
		{
			if(!pre->rtree)
			{
				pre->rflag = 1;
				pre->rtree = tree;
			}
			else
				pre->rflag = 0;
		}
		pre = tree;

		//3.Do_Inorder_Thread to rtree
		In_order_Thread(tree->rtree);
	}
}

void Create_Inorder_Thread(struct BinTree_node *T)
{
	if(T)
	{
		In_order_Thread(T);
		pre->rtree = NULL;
		pre->rflag = 1;
	}
}

void Traverse_Inorder_Thread(struct BinTree_node *tree)
{
	while(tree)
	{
		while(tree->lflag == 0)
			tree = tree->ltree;
		printf("%c ", tree->elem);

		while((tree->rflag == 1) && (tree->rtree))
		{
			tree = tree->rtree;
			printf("%c ", tree->elem);
		}
		tree = tree->rtree;
	} 
}

struct BinTree_node *Search_Inorder_Thread(struct BinTree_node *tree, char ch)
{
	while(tree)
	{
		while(tree->lflag == 0)
			tree = tree->ltree;
		if(tree->elem == ch)
			return tree;

		while((tree->rflag == 1) && (tree->rtree))
		{
			tree = tree->rtree;
			if(tree->elem == ch)
				return tree;
		}
		tree = tree->rtree;
	} 	
}

struct BinTree_node *Prenode_Inorder_Thread(const struct BinTree_node *node)
{
	struct BinTree_node *nd;

	if(node->lflag == 1)
		return node->ltree;
	else
	{
		nd = node->ltree;
		while(nd->rflag == 0)
			nd = nd->rtree;
		return nd;
	}
}

struct BinTree_node *Succnode_Inorder_Thread(const struct BinTree_node *node)
{
	struct BinTree_node *nd;

	if(node->rflag == 1)
		return node->rtree;
	else
	{
		nd = node->rtree;
		while(nd->lflag == 0)
			nd = nd->ltree;
		return nd;
	}
}
