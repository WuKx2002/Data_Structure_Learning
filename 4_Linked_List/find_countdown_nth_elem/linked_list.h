#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

extern struct node* head;
extern struct node* tail;

struct node
{
	int elem;
	struct node* next;
};

void create_list(int elem);
void print_list(struct node* list_head);
int find_countdown_nth_elem(struct node* head, int n);

#endif
