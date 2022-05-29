#include "Queue.h"

void enQueue(int n)
{
    Queue[rear++] = n;
}

int deQueue(void)
{
    return Queue[front++];
}

int isEmptyQueue(void)
{
    return front == rear;
}
