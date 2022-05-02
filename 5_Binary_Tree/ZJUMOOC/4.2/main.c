#include "same_bst.h"

int main(void)
{
    Tree mytree;
    int num_of_nodes;
    printf("Now, create a binary search tree!\n");
    printf("How many nodes does the tree have ?");
    scanf("%d", &num_of_nodes);
    mytree = creat_bst(num_of_nodes);
    printf("Create successfully ! preprder : ");
    preorder(mytree);
    printf("\n");

    printf("Please enter the next tree.\n");
    int result = judge(mytree, num_of_nodes);
    if (result = 0)
        printf("Same !");
    else if(result = 1)    
        printf("Different !");

    return 0;
}

/**/