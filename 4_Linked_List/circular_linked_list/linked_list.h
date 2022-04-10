#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <stdio.h>
#include <stdlib.h>

/*声明结点*/
struct node
{
    unsigned char elem;
    struct node* next;
};

/*创建链表*/
void create_list(unsigned char elem);
/*插入结点*/
void insert_node(int pos, unsigned char elem);
/*删除结点*/
void delete_node(int pos);
/*打印链表*/
void print_list(struct node* list_head);
/*搜索结点*/
int search(unsigned char elem);

#endif