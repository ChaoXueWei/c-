#ifndef _QUEUE_H
#define _QUEUE_H
#include"BinaryTree.h"
#include<stdbool.h>
typedef BTNode* QUTypeData;
typedef struct QueueNode
{
	QUTypeData _data;
	struct QueueNode* _next;
}QueueNode;
typedef struct Queue
{
	struct QueueNode* head;
	struct QueueNode* rear;
}Queue;
void QueueInit(Queue*);
void QueueDestory(Queue*);

void QueuePop(Queue*);
void QueuePush(Queue*, QUTypeData);
QUTypeData QueueTop(Queue*);

bool QueueIsEmpty(Queue*);
#endif //_QUEUE_H