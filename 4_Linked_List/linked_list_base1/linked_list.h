#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <stdio.h>
#include <stdlib.h>

/*声明结点*/
struct node
{
    unsigned char elem;    /*数据域*/
    struct node * next      /*指针域*/
};


void create_list(unsigned char elem);           /*创建链表*/
void insert_node(int pos, unsigned char elem);  /*插入结点*/
void delete_node(int pos);                      /*删除结点*/
void print_list(void);                          /*打印链表*/
int search(unsigned char elem);                 /*搜索结点*/

#endif