#include "BiTree.h"

int main(void)
{
	Tree mytree;
	char pre[100], in[100], post[100];
	int choose, n;

	printf("1. Restore Bitree through pre&in order");
	printf("2. Restore Bitree through in&post order");

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

			mytree = pre_in_restore_bitree(pre, in, n);
			printf("After revert, show the bintree in post order:");
			posorder(mytree);
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

			mytree = in_post_restore_bitree(in, post, n);
			printf("After revert, show the bintree in pre order:");
			preorder(mytree);
			printf("\n");
			break;
	}
	return 0;
}
