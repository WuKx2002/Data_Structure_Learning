#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>

#define SIZE 100

int front, rear;
int Queue[SIZE];

void enQueue(int n);
int deQueue(void);
int isEmptyQueue(void);



#endif