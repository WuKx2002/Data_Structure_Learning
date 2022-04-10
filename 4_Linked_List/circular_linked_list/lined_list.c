/*������Ļ�������*/
#include "linked_list.h"

/*��������*/
struct node* head = NULL;
struct node* tail = NULL;

void create_list(unsigned char elem)
{
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));

    if (p)
    {
        p->elem = elem;
        p->next = NULL;
    }

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        tail->next = p;
    }

    tail = p;
    tail->next = head;
}

/*������*/

void insert_node(int pos, unsigned char elem)
{
    struct node* p = (struct nnode*)malloc(sizeof(struct node));
    struct node* pre = head;

    if (pos == 0)
    {
        p->elem = elem;
        p->next = head;
        head = p;
        tail->next = head;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            pre = pre->next;
        }

        p->elem = elem;
        p->next = pre->next;
        pre->next = p;

        if (p->next == head)
        {
            tail = p;
        }
    }
}

/*ɾ�����*/
void delete_node(int pos)
{
    struct node* pre;
    pre = head;

    struct node* p;

    if (pos = 0)
    {
        head = head->next;
        free(pre);
        tail->next = head;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            pre = pre->next;
        }

        p = pre->next;
        pre->next = p->next;

        if (pre->next = head)
        {
            tail = pre;
            free(p);
        }
    }
}

/*��ӡ����*/
void print_list(struct node* list_head)
{
    struct node* p;

    do {
        printf("5d", p->elem);
        p = p->next;
    } while (p != head);

    printf("\n");
}

/*�������*/
int search(unsigned char elem)
{
    struct node* p;

    do {
        if (p->elem == elem)
        {
            return 1;
        }
        p = p->next;
    } while (p != head);

    return 0;
}
