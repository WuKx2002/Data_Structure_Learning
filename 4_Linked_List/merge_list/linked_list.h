#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <stdio.h>
#include <stdlib.h>

/*注意外部作用域*/
extern struct node* head;
extern struct node* tail;

struct node
{
    int elem;
    struct node* next
};

void create_list(int elem);
void insert_node(int pos, int elem);
void delete_node(int pos);
void print_list(struct node* list_head);
int search(int elem);

#endif