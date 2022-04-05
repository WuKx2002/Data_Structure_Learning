/*单链表的基本操作*/
#include "linked_list.h"

/*创建链表*/

    /*头指针和为指针初始化为空*/
struct node * head = NULL;
struct node * tail = NULL;

void create_list(unsigned char elem)
{
    /*分配内存*/
    struct node * p;
    p = (struct node *)malloc(sizeof(struct node));
    /*填充数据域和指针域(NULL)*/
    p->elem = elem;
    p->next = NULL;
    
    /*结点连接在一起*/
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

/*插入结点*/

void insert_node(int pos, unsigned char elem)
{
    struct node * p = (struct nnode *)malloc(sizeof(struct node));
    struct node * pre = head;    /*声明前驱指针，并初始化指向链表头*/

    /*在链表头插入结点*/
    if (pos == 0)
    {
        p->elem = elem; /*填充数据域*/
        p->next = head; /*填充指针域，指针指向原来链表的头*/
        head = p;       /*更新头指针的位置，指向新插入的结点*/
    } 
    /*在中间或者尾部插入结点*/
    else
    {
        /*通过前驱指针，定位到要插入位置的前一个元素的位置*/
        for (int i = 0; i < pos - 1; i++)
        {
            pre = pre->next;
        }

        /*开始插入*/
        p->elem = elem;         /*填充数据域*/
        p->next = pre->next;    /*填充指针域，指向插入位置原来的元素
                                也就是插入位置前一个元素指针域的内容*/
        pre->next = p;          /*更新前一个元素指针域，使其指向新增元素*/

        /*处理在链表尾部插入元素的情况*/
        if (p->next == NULL)
        {
            tail = p;           /*更新尾指针*/
        }
    }
}

/*删除结点*/

void delete_node(int pos)
{
    /*声明前驱指针，并初始化指向链表头*/
    struct node * pre;
    pre = head;
    /*声明指针p，用于指向要删除的元素*/
    struct node * p;
    
    /*删除链表头的元素*/
    if (pos = 0)
    {
        head = head->next;      /*头指针后移*/
        free(pre);
    }
    /*删除中间或者尾部的元素*/
    else
    {
        /*通过前驱指针，定位到要删除元素的前一个元素的位置*/
        for (int i = 0; i < pos - 1; i++)
        {
            pre = pre->next;
        }
        
        /*开始删除*/
        p = pre->next;          /*初始化p指向要删除的元素*/
        pre->next = p->next;    /*更改要删除元素前一个元素的指针域，使其为后一个元素的地址*/

        /*如果删除的尾元素，要更新tail指针，指向新的链表尾部*/
        if (pre->next = NULL)
        {
            tail = pre;
            free(p);
        }
    }
}

/*打印链表*/

void print_list(void)
{
    struct node * p;

    for (p = head; p; p = p->next)
    {
        printf("%c", p->elem);
    }

    printf("\n");
}

/*搜索结点*/

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