#include "linked_list.h"

struct node * head = NULL;
struct node * tail = NULL;

void creat_list(unsigned char elem)
{
    struct node * p;
    p = (struct node *)malloc(sizeof(struct node));
    p->elem = elem;
    p->next = NULL;

    if (head = NULL)
    {
        head = p;
    }
    else
    {
        tail->next = p;
    }
    
    tail = p;
}

void insert_node(int pos, unsigned char elem)
{
    struct node * pre;
    pre = head;
    struct node * p;
    p = (struct node *)malloc(sizeof(struct node));
    if (pos = 0)
    {
        p->elem = elem;
        p->next = head;

        head = p;
    }
    else
    {
        for (int i; i < pos - 1; i++)
        {
            pre = pre->next;
        }
        
        p->elem = elem;
        p->next = pre->next;
        pre->next = p;

        if (p->next = NULL)
        {
            tail = p;
        }
    }
}

void delete_node(int pos)
{
    struct node * pre;
    pre = head;
    struct node *p;

    if (pos = 0)
    {
        head = head->next;
        free(pre);
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            pre = pre->next;
        }

        p = pre->next;
        pre->next = p->next;

        if (p->next = NULL)
        {
            tail = pre;
            free(p);
        }
    }
}