#include <stdio.h>
#include "linklist.h"
#include <stdlib.h>

int main(void)
{
	int n, k, m;
	int i;
	struct node *p, *q;

	printf("Please enter the number of person:");
	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		create_list(i);
	print_linklist();
	p = head;

	printf("Please enter the start num:");
	scanf("%d", &k);

	while(--k)
		p = p->next;
//	printf("p->elem = %d\n", p->elem);

	printf("Please enter the m:");
	scanf("%d", &m);
	
	if(1 == m)
	{
		for(i = 0; i < n; i++)
		{
			printf("%3d", p->elem);
			p = p->next;
		}
		printf("\n");
	}
	else
	{
		while(n--)
		{
			for(i = 1; i < m - 1; i++)
				p = p->next;
		
			q = p;
			p = p->next;
			printf("%3d", p->elem);
			q->next = p->next;
			free(p);
			p = p->next;
		}
		printf("\n");
	}
	return 0;
}
