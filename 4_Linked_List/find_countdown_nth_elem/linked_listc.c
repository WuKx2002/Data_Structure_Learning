/*
���ҵ�����n��Ԫ��
Ҫ�㣺����ָ��
�㷨��
��ָ���Ⱥ���n-1��λ�ã�Ȼ����ָ��Ӻ�ʼ�Ϳ�ָ��ͬ��ǰ����
����ָ�뵽������β��ʱ����ָ��ָ���˵�����n��Ԫ�ء�
*/

#include "linked_list.h"

struct node* head = NULL;
struct node* tail = NULL;

void create_list(int elem)
{
	struct node* p = (struct node*)malloc(sizeof(struct node));

	if (p)
	{
		p->elem = elem;
		p->next = NULL;
	}

	if (head == NULL)
	{
		head = p;
	}
	else
	{
		tail->next = p;
	}
	tail = p;

}

void print_list(struct node* list_head)
{
	struct node* p;

	for (p = list_head; p; p = p->next)
	{
		printf("%5d", p->elem);
	}
	printf("\n");

}

int find_countdown_nth_elem(struct node* list_head, int n)
{
	struct node* p_fast = list_head;
	struct node* p_low = list_head;

	for (int i = 0; i < n - 1; i++)
	{
		p_fast = p_fast->next;
	}

	while (p_fast->next != NULL)
	{
		p_fast = p_fast->next;
		p_low = p_low->next;
	}

	return p_low->elem;
}