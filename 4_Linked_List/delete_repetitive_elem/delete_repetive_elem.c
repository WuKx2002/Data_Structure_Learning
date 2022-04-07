/***************************************************

ɾ���������ظ���Ԫ��
Ҫ�㣺�������飬�±꣺Ҫ���ҵ�Ԫ�أ����ݣ��Ƿ��ظ�(0/1)

***************************************************/

#include "linked_list.h"

void delete_repetive_elem(struct node* list_head);

int main(void)
{
	create_list(1);
	create_list(3);
	create_list(5);
	create_list(7);
	create_list(7);
	create_list(9);
	create_list(11);
	print_list(head);

	delete_repetive_elem(head);

	print_list(head);

	return 0;
}

void delete_repetive_elem(struct node* list_head)
{
	int flag[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};	/*��������*/
	struct node* p = list_head;
	struct node* q = NULL;

	flag[p->elem] = 1;

	while (p->next != NULL)
	{
		if (flag[p->next->elem] == 0)
		{
			flag[p->next->elem] = 1;
			p = p->next;
		}
		else
		{
			q = p->next;
			p->next = q->next;
			free(q);
		}
	}
}