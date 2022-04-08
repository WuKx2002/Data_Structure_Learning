/*ÄæÖÃµ¥Á´±í*/
#include "linked_list.h"

int main(void)
{
	creat_list(1);
	creat_list(2);
	creat_list(3);
	creat_list(4);

	print_list(head);

	reverse_list(head);
	print_list(head);

	return 0;
}