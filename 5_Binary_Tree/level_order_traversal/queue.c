#include "BiTree.h"/*ÄÚº¬stdio.h*/
#include "queue.h"

front = 0;
rear = 0;

void enqueue(struct BiTree_node c)
{
	queue[rear] = c;
	rear = (rear + 1) % SIZE;
}

struct BiTree_node dequeue(void)
{
	struct BiTree_node ch;
	ch = queue[front];
	front = (front + 1) % SIZE;
	return ch;
}

int is_empty(void)
{
	return front == rear;
}

int is_full(void)
{
	return (rear + 1) % SIZE == front;
}
