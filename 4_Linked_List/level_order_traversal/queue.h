#ifndef QUEUE_H_
#define QUEUE_H_

#include "BiTree.h"

#define SIZE 100
struct BiTree_node queue[SIZE];
int front;
int rear;

void enqueue(struct BiTree_node c);
struct BiTree_node dequeue(void);
int is_empty(void);
int is_full(void);

#endif