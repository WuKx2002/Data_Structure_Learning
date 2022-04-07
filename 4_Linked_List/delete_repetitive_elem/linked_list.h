#ifndef	LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

extern struct node* head;
extern struct node* tail;

struct node
{
	unsigned int elem;
	struct node* next;
};

void create_list(int elem);

void print_list(struct node* list_head);

void delete_repetive_elem(struct node* list_head);

#endif
