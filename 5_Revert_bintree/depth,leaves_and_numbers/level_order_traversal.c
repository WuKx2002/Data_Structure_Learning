#include "BiTree.h"
#include "queue.h"

int main(void)
{
	struct BiTree_node* mytree;
	mytree = create_BiTree();

	printf("pre_order : ");
	pre_order(mytree);
	printf("\n");

	printf("in_order : ");
	in_order(mytree);
	printf("\n");

	printf("post_order : ");
	post_order(mytree);
	printf("\n");

	printf("lvl_order : ");
	lvl_order(mytree);

	printf("depth : %u\n", depth(mytree));
	printf("leaves : %u\n", leaves(mytree));
	printf("nodes : %u\n", nodes(mytree));


	return 0;
}