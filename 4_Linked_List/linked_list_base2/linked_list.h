#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

struct node
{
    unsigned char elem;
    struct node * next;
};

void creat_list(unsigned char elem);
void insert_node(int pos, unsigned char elem);
void delete_node(int pos);

#endif