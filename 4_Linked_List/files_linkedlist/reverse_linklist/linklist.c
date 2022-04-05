#include "linklist.h"
#include <stdlib.h>

struct node *head = NULL;
struct node *tail = NULL;

void create_list(unsigned int elem)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->elem = elem;
	p->next = NULL;

	if(head == NULL)
		head = p;
	else
		tail->next = p;

	tail = p;
}

void insert_node(int pos, unsigned int elem)
{
	struct node *pre;
	pre = head;
	int i = 0;
	struct node *p = (struct node *)malloc(sizeof(struct node));

	if(pos == 0)
	{
		p->elem = elem;
		p->next = head;
		head = p;
	}
	else
	{
		while(i < pos - 1)
		{
			pre = pre->next;
			i++;
		}

		p->elem = elem;
		p->next = pre->next;
		pre->next = p;
	
		if(p->next == NULL)
			tail = p;
	}
}

void delete_node(int pos)
{
	struct node *pre, *p;
	pre = head;
	int i = 0;

	if(pos == 0)
	{
		head = head->next;
		free(pre);
	}
	else
	{
		while(i < pos - 1)
		{
			pre = pre->next;
			i++;
		}
	
		p = pre->next;
		pre->next = p->next;
		if(p->next == NULL)
			tail = pre;
		free(p);
	}
}

void print_linklist(struct node *linklist_head)
{
	struct node *p;

	for(p = linklist_head; p; p = p->next)
		printf("%5d", p->elem);

	printf("\n");
}

int search(unsigned int elem)
{
	struct node *p;

	for(p = head; p; p = p->next)
		if(p->elem == elem)
			return 1;
	return 0;
}

int find_mid(struct node *linklist_head)
{
	struct node *p;
	struct node *q;
	p = q = linklist_head;

	while(p != NULL && p->next != NULL)
	{
		p = p->next->next;
		q = q->next;
	}

	return q->elem;
}

int find_last_nth(struct node *linklist_head, int n)
{
	int i;

	struct node *p;
	struct node *q;

	p = q = linklist_head;

	for(i = 0; i < n-1; i++)
		p = p->next;

	while(p->next != NULL)
	{
		p = p->next;
		q = q->next;
	}

	return q->elem;
}

void reverse_linklist(struct node *linklist_head)
{
	struct node *p, *n;

	p = linklist_head->next;
	linklist_head->next = NULL;

	while(p->next != NULL)
	{
		n = p->next;
		p->next = linklist_head;
		linklist_head = p;
		p = n;
	}
	p->next = linklist_head;
	linklist_head = p;

	head = linklist_head;
}
