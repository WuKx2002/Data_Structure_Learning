#include "linked_list.h"

struct node* head = NULL;
struct node* tail = NULL;

void create_list(int elem)
{
    struct node* p = (struct node*)malloc(sizeof(struct node));

    p->elem = elem;
    p->next = NULL;

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        tail->next = p;
    }

    tail = p;
}

void insert_node(int pos, int elem)
{
    struct node* pre = head;
    struct node* p = (struct node*)malloc(sizeof(struct node));;

    for (int i = 0; i < pos - 1; i++)
    {
        pre = pre->next;
    }

    if (pos == 0)
    {
        p->elem = elem;
        p->next = head;

        head = p;
    }
    else
    {
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
    struct node* pre = head;
    struct node* p;

    for (int i = 0; i < pos - 1; i++)
    {
        pre = pre->next;
    }

    if (pos == 0)
    {
        head = head->next;
        free(pre);
    }
    else
    {
        p = pre->next;
        pre->next = p->next;

        if (p->next == NULL)
        {
            tail = pre;
            free(p);
        }
    }

}

void print_list(struct node* list_head)
{
    struct node* p;

    for (p = list_head; p; p = p->next)
    {
        printf("%5d", p->elem);
    }

    printf("\n");
}

int search(int elem)
{
    struct node* p;

    for (p = head; p; p = p->next)
    {
        if (p->elem = elem)
        {
            return 1;
        }
    }

    return 0;
}