/*
查找倒数第n个元素
要点：快慢指针
算法：
快指针先后移n-1个位置，然后慢指针从后开始和快指针同速前进，
当快指针到达链表尾的时候，慢指针指向了倒数第n个元素。
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