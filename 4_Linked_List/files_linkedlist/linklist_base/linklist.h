#ifndef LINKLIST_H__
#define LINKLIST_H__

#include <stdio.h>

struct node
{
	unsigned char elem;
	struct node *next;
};

void create_list(unsigned char elem);
void insert_node(int pos, unsigned char elem);
void delete_node(int pos);
void print_linklist(void);
int search(unsigned char elem);

#endif

