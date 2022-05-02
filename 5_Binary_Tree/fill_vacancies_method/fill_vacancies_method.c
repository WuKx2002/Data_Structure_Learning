#include "BiTree.h"
#include "queue.h"

int main(void)
{
	struct BiTree_node* mytree;
	printf("Please enter a binary tree : ");
	mytree = create_BiTree_by_filling_vacancies();
	lvl_order(mytree);
	pre_order(mytree);

	return 0;
}