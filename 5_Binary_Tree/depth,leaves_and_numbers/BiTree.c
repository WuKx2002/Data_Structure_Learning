#include "BiTree.h"
#include "queue.h"

struct BiTree_node* create_BiTree(void)
{
	struct BiTree_node* tree;
	tree = (struct BiTree_node*)malloc(sizeof(struct BiTree_node));

	if (tree)
	{
		printf("Elem of the node :");
		while ((tree->elem = getchar()) == '\n');

		char flag;
		printf("Insert a left tree for %c ? (Y or N) : ", tree->elem);
		while ((flag = getchar()) == '\n');
		if (flag == 'Y')
		{
			tree->left = create_BiTree();
		}
		else
		{
			tree->left = NULL;
		}

		printf("Insert a right tree for %c ? (Y or N) : ", tree->elem);
		while ((flag = getchar()) == '\n');
		if (flag == 'Y')
		{
			tree->right = create_BiTree();
		}
		else
		{
			tree->right = NULL;
		}
	}
	return tree;
}

void pre_order(struct BiTree_node* tree)
{
	if (tree)
	{ 
		printf("%c", tree->elem);
		pre_order(tree->left);
		pre_order(tree->right);
	}
}
void in_order(struct BiTree_node* tree)
{
	if (tree)
	{
		in_order(tree->left);
		printf("%c", tree->elem);
		in_order(tree->right);
	}
}

void post_order(struct BiTree_node* tree)
{
	if (tree)
	{
		post_order(tree->left);
		post_order(tree->right);
		printf("%c", tree->elem);
	}
}

void lvl_order(struct BiTree_node* tree)
{
	struct BiTree_node node;

	enqueue(*tree);

	while (!is_empty())
	{
		node = dequeue();
		printf("%c", node.elem);
		if (node.left)
		{
			enqueue(*node.left);
		}
		if (node.right)
		{
			enqueue(*node.right);
		}
	}
	printf("\n");
}

/*统计二叉树的深度*/
/*
算法：
1.如果二叉树为空，则深度为0.
2.如果二叉树不为空，则深度为根节点左子树深度和右子树深度中的最大值+1
*/
unsigned int depth(struct BiTree_node* tree)
{
	unsigned int l_depth, r_depth;
	int tree_depth;

	if (tree == NULL)
	{
		tree_depth = 0;
	}
	else
	{
		l_depth = depth(tree->left);
		r_depth = depth(tree->right);
		tree_depth = (l_depth > r_depth) ? (l_depth + 1) : (r_depth + 1);
	}
	return tree_depth;
}

/*统计二叉树的叶子数*/
/*
算法：
1.如果二叉树为空，则叶子数为0.
2.如果二叉树只有根节点，无左右子树，则叶子数为1.
3.一般情况下，叶子数 = 左子树叶子数 + 右子树叶子数.
*/
unsigned int leaves(struct BiTree_node* tree)
{
	int tree_leaves;

	if (tree == NULL)
	{
		tree_leaves = 0;
	}
	else if ((tree->left == NULL) && (tree->right == NULL))
	{
		tree_leaves = 1;
	}
	else
	{
		tree_leaves = leaves(tree->left) + leaves(tree->right);
	}
	return tree_leaves;
}

/*统计二叉树的结点数*/
/*
1.如果二叉树为空，则结点数为0.
2.如果二叉树不为空，则结点数 = 左子树结点数 + 右子树结点数.
*/
unsigned int nodes(struct BiTree_node* tree)
{
	unsigned int tree_nodes;
	if (tree == NULL)
	{
		tree_nodes = 0;
	}
	else
	{
		tree_nodes = nodes(tree->left) + nodes(tree->right) + 1;
	}
	return tree_nodes;
}