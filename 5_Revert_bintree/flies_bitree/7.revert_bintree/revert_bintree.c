#include <stdio.h>
#include <stdlib.h>

struct BinTree_node
{
	unsigned char elem;
	struct BinTree_node *ltree, *rtree;
};

void pre_order(struct BinTree_node *tree);
void in_order(struct BinTree_node *tree);
void pos_order(struct BinTree_node *tree);

struct BinTree_node *create_bintree(void);
struct BinTree_node *pre_in_CreateBinTree(char *pre, char *in, int len);
struct BinTree_node *in_post_CreateBinTree(char *in, char *post, int len);

int main(void)
{
	struct BinTree_node *mytree;

	char pre[100], in[100], post[100];
	int choose, n;

	printf("1. Revert BinaryTree through pre & in order:\n");
	printf("2. Revert BinaryTree through in & post order:\n");
	scanf("%d", &choose);

	switch(choose)
	{
		case 1:
			printf("Please enter the number of nodes:");
			scanf("%d", &n);
			getchar();
			printf("Please enter the pre order:");
			gets(pre);
			printf("Please enter the in order:");
			gets(in);

			mytree = pre_in_CreateBinTree(pre, in, n);
			printf("After revert, show the bintree in post order:");
			pos_order(mytree);
			printf("\n");
			break;
		case 2:
			printf("Please enter the number of nodes:");
			scanf("%d", &n);
			getchar();
			printf("Please enter the in order:");
			gets(in);
			printf("Please enter the post order:");
			gets(post);

			mytree = in_post_CreateBinTree(in, post, n);
			printf("After revert, show the bintree in pre order:");
			pre_order(mytree);
			printf("\n");
			break;
	}

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

struct BinTree_node *pre_in_CreateBinTree(char *pre, char *in, int len)
{
	struct BinTree_node *tree;

	if(len == 0)
		return NULL;

	char ch = pre[0];
	int index = 0;

	while(in[index] != ch)
		index++;
	
	tree = (struct BinTree_node *)malloc(sizeof(struct BinTree_node));
	tree->elem = ch;
	tree->ltree = pre_in_CreateBinTree(pre+1, in, index);
	tree->rtree = pre_in_CreateBinTree(pre+index+1, in+index+1, len-index-1);

	return tree;
}

struct BinTree_node *in_post_CreateBinTree(char *in, char *post, int len)
{
	struct BinTree_node *tree;

	if(len == 0)
		return NULL;

	char ch = post[len-1];
	int index = 0;
	while(in[index] != ch)
		index++;

	tree = (struct BinTree_node *)malloc(sizeof(struct BinTree_node));
	tree->elem = ch;
	tree->ltree = in_post_CreateBinTree(in, post, index);
	tree->rtree = in_post_CreateBinTree(in+index+1, post+index, len-index-1);

	return tree;
}
