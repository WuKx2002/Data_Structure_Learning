/*������Ļ�������*/
#include "linked_list.h"

/*��������*/
struct node* head = NULL;
struct node* tail = NULL;

void create_list(unsigned char elem)
{
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));

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

        if (p->next == NULL)
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
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            pre = pre->next;
        }

        p = pre->next;
        pre->next = p->next;

        if (pre->next = NULL)
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

    for (p = list_head; p; p = p->next)
    {
        printf("%c", p->elem);
    }

    printf("\n");
}

/*�������*/
int search(unsigned char elem)
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

/*ɾ���ظ����*/
void delete_repetive_elem(struct node* list_head)
{
    int flag[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    struct node* p = list_head;
    struct node* q = NULL;

    flag[p->elem] = 1;

    while (p->next != NULL)
    {
        if (flag[p->next->elem] == 0)
        {
            flag[p->next->elem] = 1;
            p = p->next;
        }
        else
        {
            q = p->next;
            p->next = q->next;
            free(q);
        }
    }
}

/*�ҵ��м���*/
char find_mid(void)
{
    struct node* p_fast = head;
    struct node* p_low = head;

    while (p_fast != NULL && p_fast->next != NULL)
    {
        p_fast = p_fast->next->next;
        p_low = p_low->next;
    }

    return p_low->elem;

}

/*�ҵ�������n�����*/
char find_countdown_nth_elem(struct node* list_head, int n)
{
    struct node* p_fast = list_head;
    struct node* p_low = list_head;

    for (int i = 0; i < n - 1; i++)
    {
        p_fast = p_fast->next;
    }

    while (p_fast->next != NULL)
    {
        p_fast = p_fast->next;
        p_low = p_low->next;
    }

    return p_low->elem;
}

/*��������*/
void reverse_list(struct node* list_head)
{
    struct node* p = list_head->next;
    struct node* temp;

    list_head->next = NULL;

    while (p->next != NULL)
    {
        temp = p->next;
        p->next = list_head;
        list_head = p;
        p = temp;
    }

    p->next = list_head;
    list_head = p;

    head = list_head;
}

/*�ϲ�����*/
void merge_list(struct node* head1, struct node* head2)
{
    struct node* p1 = head1;
    struct node* p2 = head2;

    while (p1 && p2)
    {
        if (p2->elem <= p1->elem)
        {
            if (head == NULL)
            {
                head = p2;
            }
            else
            {
                tail->next = p2;
            }
            tail = p2;
            p2 = p2->next;
        }
        else
        {
            if (head == NULL)
            {
                head = p1;
            }
            else
            {
                tail->next = p1;
            }
            tail = p1;
            p1 = p1->next;
        }
    }

    tail->next = p1 ? p1 : p2;

    print_list(head);
}