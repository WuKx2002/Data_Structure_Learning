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

/*ͳ�ƶ����������*/
/*
�㷨��
1.���������Ϊ�գ������Ϊ0.
2.�����������Ϊ�գ������Ϊ���ڵ���������Ⱥ�����������е����ֵ+1
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

/*ͳ�ƶ�������Ҷ����*/
/*
�㷨��
1.���������Ϊ�գ���Ҷ����Ϊ0.
2.���������ֻ�и��ڵ㣬��������������Ҷ����Ϊ1.
3.һ������£�Ҷ���� = ������Ҷ���� + ������Ҷ����.
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

/*ͳ�ƶ������Ľ����*/
/*
1.���������Ϊ�գ�������Ϊ0.
2.�����������Ϊ�գ������� = ����������� + �����������.
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