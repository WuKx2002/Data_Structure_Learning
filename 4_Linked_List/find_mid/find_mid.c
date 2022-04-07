/*
查找链表中间点的元素

要点：快慢指针

算法：
快指针和慢指针同时开始遍历链表中的元素，
快指针的速度是慢指针的两倍，
当快指针到达链表尾的时候，慢指针到达链表中间的元素。
*/
#include "linked_list.h"

int main(void)
{
	create_list(1);
	create_list(3);
	create_list(5);
	create_list(7);
	create_list(9);
	create_list(11);

	print_list(head);
	printf("mid : %d", find_mid());

	return 0;
}


