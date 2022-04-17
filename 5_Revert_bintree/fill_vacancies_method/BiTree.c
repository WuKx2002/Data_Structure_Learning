#include "BiTree.h"
#include "queue.h"

struct BiTree_node* create_BiTree_by_asking(void)
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
			tree->left = create_BiTree_by_asking();
		}
		else
		{
			tree->left = NULL;
		}

		printf("Insert a right tree for %c ? (Y or N) : ", tree->elem);
		while ((flag = getchar()) == '\n');
		if (flag == 'Y')
		{
			tree->right = create_BiTree_by_asking();
		}
		else
		{
			tree->right = NULL;
		}
	}
	return tree;
}

struct BiTree_node* create_BiTree_by_filling_vacancies(void)
{
	struct BiTree_node* tree;
	
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#')
	{
		tree = NULL;
	}
	else
	{
		tree = (struct BiTree_node*)malloc(sizeof(struct BiTree_node));
		if (tree)
		{
			tree->elem = ch;
			tree->left = create_BiTree_by_filling_vacancies();
			tree->right = create_BiTree_by_filling_vacancies();
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