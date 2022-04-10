/*
约瑟夫斯置换,是一个出现在计算机科学和数学中的问题。
在计算机编程的算法中，类似问题又称为约瑟夫环。

人们站在一个等待被处决的圈子里。
计数从圆圈中的指定点开始,并沿指定方向围绕圆圈进行。
在跳过指定数量的人之后,处刑下一个人。 
对剩下的人重复该过程,直到只剩下一个人,并被释放。

问题即，给定人数、起点、方向和要跳过的数字，选择初始圆圈中的位置以避免被处决。
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
	int total; /*环内总人数*/
	int start; /*起点*/
	int delta; /*每次跳过人数*/

	printf("Please enter the total number of people in the circle : ");
	scanf_s("%d", &total);

	printf("Please enter the number of starting point : ");
	scanf_s("%d", &start);

	printf("Please enter the number of people skip each time : ");
	scanf_s("%d", &delta);

	/*创建循环链表*/
	for (int i = 1; i <= total; i++)
	{
		create_list(i);
	}
	print_list();

	/*找到start，例如：start = 3，则p需要移动2次*/
	struct node* p = head;
	struct node* q;
	while (--start)
	{
		p = p->next;
	}
	printf("%5d\n", p->elem);

	/*开始输出，如果delta= 1，则从start开始输出链表即可*/
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