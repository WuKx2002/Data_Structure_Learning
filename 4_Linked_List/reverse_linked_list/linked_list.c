#include "linked_list.h"

struct node* head = NULL;
struct node* tail = NULL;

void creat_list(int elem)
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

void reverse_list(struct node* list_head)
{
	struct node* p = list_head->next;
	struct node* temp;

	list_head->next = NULL;

	while (p->next != NULL)
	{
		temp = p->next;
		p->next = list_head;
		list_head = p;
		p = temp;
	}

	p->next = list_head;
	list_head = p;

	head = list_head;
}