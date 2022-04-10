#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <stdio.h>
#include <stdlib.h>

/*�������*/
struct node
{
    unsigned char elem;
    struct node* next;
};

/*��������*/
void create_list(unsigned char elem);
/*������*/
void insert_node(int pos, unsigned char elem);
/*ɾ�����*/
void delete_node(int pos);
/*��ӡ����*/
void print_list(struct node* list_head);
/*�������*/
int search(unsigned char elem);
/*ɾ���ظ����*/
void delete_repetive_elem(struct node* list_head);
/*�ҵ��м���*/
char find_mid(void);
/*�ҵ�������n�����*/
char find_countdown_nth_elem(struct node* list_head, int n);
/*�ϲ�����*/
void merge_list(struct node* head1, struct node* head2);
/*��������*/
void reverse_list(struct node* list_head);
#endif
