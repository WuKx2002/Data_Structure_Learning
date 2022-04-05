/*������Ļ�������*/
#include "linked_list.h"

/*��������*/

    /*ͷָ���Ϊָ���ʼ��Ϊ��*/
struct node * head = NULL;
struct node * tail = NULL;

void create_list(unsigned char elem)
{
    /*�����ڴ�*/
    struct node * p;
    p = (struct node *)malloc(sizeof(struct node));
    /*����������ָ����(NULL)*/
    p->elem = elem;
    p->next = NULL;
    
    /*���������һ��*/
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
    struct node * p = (struct nnode *)malloc(sizeof(struct node));
    struct node * pre = head;    /*����ǰ��ָ�룬����ʼ��ָ������ͷ*/

    /*������ͷ������*/
    if (pos == 0)
    {
        p->elem = elem; /*���������*/
        p->next = head; /*���ָ����ָ��ָ��ԭ�������ͷ*/
        head = p;       /*����ͷָ���λ�ã�ָ���²���Ľ��*/
    } 
    /*���м����β��������*/
    else
    {
        /*ͨ��ǰ��ָ�룬��λ��Ҫ����λ�õ�ǰһ��Ԫ�ص�λ��*/
        for (int i = 0; i < pos - 1; i++)
        {
            pre = pre->next;
        }

        /*��ʼ����*/
        p->elem = elem;         /*���������*/
        p->next = pre->next;    /*���ָ����ָ�����λ��ԭ����Ԫ��
                                Ҳ���ǲ���λ��ǰһ��Ԫ��ָ���������*/
        pre->next = p;          /*����ǰһ��Ԫ��ָ����ʹ��ָ������Ԫ��*/

        /*����������β������Ԫ�ص����*/
        if (p->next == NULL)
        {
            tail = p;           /*����βָ��*/
        }
    }
}

/*ɾ�����*/

void delete_node(int pos)
{
    /*����ǰ��ָ�룬����ʼ��ָ������ͷ*/
    struct node * pre;
    pre = head;
    /*����ָ��p������ָ��Ҫɾ����Ԫ��*/
    struct node * p;
    
    /*ɾ������ͷ��Ԫ��*/
    if (pos = 0)
    {
        head = head->next;      /*ͷָ�����*/
        free(pre);
    }
    /*ɾ���м����β����Ԫ��*/
    else
    {
        /*ͨ��ǰ��ָ�룬��λ��Ҫɾ��Ԫ�ص�ǰһ��Ԫ�ص�λ��*/
        for (int i = 0; i < pos - 1; i++)
        {
            pre = pre->next;
        }
        
        /*��ʼɾ��*/
        p = pre->next;          /*��ʼ��pָ��Ҫɾ����Ԫ��*/
        pre->next = p->next;    /*����Ҫɾ��Ԫ��ǰһ��Ԫ�ص�ָ����ʹ��Ϊ��һ��Ԫ�صĵ�ַ*/

        /*���ɾ����βԪ�أ�Ҫ����tailָ�룬ָ���µ�����β��*/
        if (pre->next = NULL)
        {
            tail = pre;
            free(p);
        }
    }
}

/*��ӡ����*/

void print_list(void)
{
    struct node * p;

    for (p = head; p; p = p->next)
    {
        printf("%c", p->elem);
    }

    printf("\n");
}

/*�������*/

int search(unsigned char elem)
{
    struct node * p;

    for (p = head; p; p = p->next)
    {
        if (p->elem = elem)
        {
            return 1;
        }
    }

    return 0;
}