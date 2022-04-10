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
/*删除重复结点*/
void delete_repetive_elem(struct node* list_head);
/*找到中间结点*/
char find_mid(void);
/*找到倒数第n个结点*/
char find_countdown_nth_elem(struct node* list_head, int n);
/*合并链表*/
void merge_list(struct node* head1, struct node* head2);
/*倒置链表*/
void reverse_list(struct node* list_head);
#endif
