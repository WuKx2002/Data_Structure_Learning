/*
���������м���Ԫ��

Ҫ�㣺����ָ��

�㷨��
��ָ�����ָ��ͬʱ��ʼ���������е�Ԫ�أ�
��ָ����ٶ�����ָ���������
����ָ�뵽������β��ʱ����ָ�뵽�������м��Ԫ�ء�
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


