/*����������������*/

#include "linked_list.h"

int main(void)
{
    /*������һ������*/
    struct node* head1;
    create_list(3);
    create_list(9);
    create_list(27);
    create_list(81);
    create_list(243);
    create_list(729);
    head1 = head;
    print_list(head1);
    head = NULL;

    /*�����ڶ�������*/
    struct node* head2;
    create_list(2);
    create_list(8);
    create_list(32);
    create_list(128);
    head2 = head;
    print_list(head2);
    head = NULL;

    /*���ڱ�����ָ��*/
    struct node* p1 = head1;
    struct node* p2 = head2;

    /*��ʼ�Ƚ�*/
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
    
    return 0;
}