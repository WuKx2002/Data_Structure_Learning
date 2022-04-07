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
int find_mid(void)
{
	struct node* p_fast = head;
	struct node* p_low = head;

	while (p_fast != NULL && p_fast->next != NULL)
	{
		p_fast = p_fast->next->next;
		p_low = p_low->next;
	}

	return p_low->elem;

}