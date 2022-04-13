#include "BiTree.h"
#include "queue.h"

int main(void)
{
	struct BiTree_node* mytree;
	mytree = create_BiTree();
	lvl_order(mytree);

	return 0;
}