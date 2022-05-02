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
		printf("%c\n", tree->elem);
		pre_order(tree->left);
		pre_order(tree->right);
	}
}
void in_order(struct BiTree_node* tree)
{
	if (tree)
	{
		in_order(tree->left);
		printf("%c\n", tree->elem);
		in_order(tree->right);
	}
}

void post_order(struct BiTree_node* tree)
{
	if (tree)
	{
		post_order(tree->left);
		post_order(tree->right);
		printf("%c\n", tree->elem);
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