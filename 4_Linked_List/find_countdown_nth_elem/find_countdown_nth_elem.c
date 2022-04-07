#include "linked_list.h"

int main(void)
{
	create_list(1);
	create_list(3);
	create_list(5);
	create_list(7);
	create_list(9);
	create_list(11);
	print_list(head);

	int n;
	printf("Please enter the last one you want to show:");
	while (scanf_s("%d", &n) == 1)
	{
		printf("the last n :%d\n", find_countdown_nth_elem(head, n));
	};

	return 0;
}
