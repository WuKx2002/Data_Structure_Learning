#include "BiTree.h"

int main(void)
{	
	printf("Please input a pre_order binary tree(with fill blank #): ");
	Tree mytree = create_bitree();

	printf("In_order Traverse: ");
	in_order(mytree);
	printf("\n");

	create_in_threading_bitree(mytree);

	printf("Traverse Inorder_Thread Tree:");
//	in_threading(mytree);
	in_order_threading(mytree);
	printf("\n");

	printf("Please enter the node that you want to find it's pre & succ node:\n");
	ElemType ch;
	while((ch = getchar()) == '\n');
	Tree node = search_inorder_threading_node(mytree, ch);
//	printf("node : %c", node->elem);
	Tree precursor = in_threading_bitree_pre_node(node);
	if(precursor == NULL)
		printf("node %c has no precursor node\n", node->elem);
	else
		printf("Precursor node = %c\n", precursor->elem);

	Tree succeed = in_threading_bitree_succ_node(node);
	if(succeed == NULL)
		printf("node %c has not succeed node\n", node->elem);
	else
		printf("Succeed node = %c\n", succeed->elem);

	return 0;
}
