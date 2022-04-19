#include "BiTree.h"

int main(void)
{
	Tree mytree;
	char ch;

	printf("Enter a binary tree: ");
	mytree = create_bitree();
	printf("In Order :");
	inorder(mytree);
	printf("\n");

	create_inthreading_bitree(mytree);
	printf("Please enter the node you want to search its pre&succ node:");
	//scanf("%c", &ch);
	while((ch = getchar()) == '\n');
	Tree node = search_node(mytree, ch);
	Tree prenode = inthreading_prenode(node);
	Tree succnode = inthreading_succnode(node);
	if (prenode == NULL)
	{
		printf("Node %c has no prenode.\n", node->elem);
	}
	else
	{
		printf("Prenode : %c.\n", prenode->elem);	
	}
	if (succnode == NULL)
	{
		printf("Node %c has no succnode.\n", node->elem);
	}
	else
	{
		printf("Succnode : %c.\n", succnode->elem);
	}

	return 0;
}
