#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <stdio.h>
#include <stdlib.h>

/*�������*/
struct node
{
    unsigned char elem;    /*������*/
    struct node * next      /*ָ����*/
};


void create_list(unsigned char elem);           /*��������*/
void insert_node(int pos, unsigned char elem);  /*������*/
void delete_node(int pos);                      /*ɾ�����*/
void print_list(void);                          /*��ӡ����*/
int search(unsigned char elem);                 /*�������*/

#endif