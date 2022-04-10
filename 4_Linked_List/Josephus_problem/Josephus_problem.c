/*
Լɪ��˹�û�,��һ�������ڼ������ѧ����ѧ�е����⡣
�ڼ������̵��㷨�У����������ֳ�ΪԼɪ�򻷡�

����վ��һ���ȴ���������Ȧ���
������ԲȦ�е�ָ���㿪ʼ,����ָ������Χ��ԲȦ���С�
������ָ����������֮��,������һ���ˡ� 
��ʣ�µ����ظ��ù���,ֱ��ֻʣ��һ����,�����ͷš�

���⼴��������������㡢�����Ҫ���������֣�ѡ���ʼԲȦ�е�λ���Ա��ⱻ������
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int elem;
	struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void create_list(int elem);
void print_list(void);

int main(void)
{
	int total; /*����������*/
	int start; /*���*/
	int delta; /*ÿ����������*/

	printf("Please enter the total number of people in the circle : ");
	scanf_s("%d", &total);

	printf("Please enter the number of starting point : ");
	scanf_s("%d", &start);

	printf("Please enter the number of people skip each time : ");
	scanf_s("%d", &delta);

	/*����ѭ������*/
	for (int i = 1; i <= total; i++)
	{
		create_list(i);
	}
	print_list();

	/*�ҵ�start�����磺start = 3����p��Ҫ�ƶ�2��*/
	struct node* p = head;
	struct node* q;
	while (--start)
	{
		p = p->next;
	}
	printf("%5d\n", p->elem);

	/*��ʼ��������delta= 1�����start��ʼ���������*/
	if (delta == 1)
	{
		for (int j = 1; j <= total; j++)
		{
			//printf("%5d", p->elem);
			p = p->next;
		}
	}
	else
	{
		while (total--)
		{
			for (int k = 1; k <= delta - 2; k++)
			{
				p = p->next;
			}
			q = p;
			p = p->next;
			printf("%5d", p->elem);
			q->next = p->next;
			p = p->next;
		}
	}


	return 0;
}

void create_list(int elem)
{
	struct node* p = (struct node*)malloc(sizeof(struct node));

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

void print_list(void)
{
	struct node* p = head;

	do {
		printf("%5d", p->elem);
		p = p->next;
	} while (p != head);

	printf("\n");
}