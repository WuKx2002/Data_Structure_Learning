#include "BiTree.h"

int main(void)
{	
	printf("Please input a preorder binary tree(with fill blank #):\n");
	Tree mytree = create_bitree();

	pre_order(mytree);
/*	printf("\n");
	in_order(mytree);
	printf("\n");
	in_threading(mytree);
	printf("\n");	*/
	in_threading(mytree);
	inorder_threading(mytree);

	return 0;
}
