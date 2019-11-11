#include"Queue.h"
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
void QueueInit(Queue*plist)
{
	assert(plist != NULL);
	plist->head = plist->rear = NULL;
}
void QueueDestory(Queue*plist)
{
	assert(plist != NULL);
	while (plist->head)
	{
		QueueNode*tmp = plist->head;
		plist->head = plist->head->_next;
		free(tmp);
	}
}

void QueuePop(Queue*plist)
{
	assert(plist != NULL);
	if (plist->head)
	{
		QueueNode*tmp = plist->head;
		plist->head = plist->head->_next;
		free(tmp);
	}
}
void QueuePush(Queue*plist, QUTypeData x)
{
	assert(plist != NULL);
	QueueNode*cur = (QueueNode*)malloc(sizeof(QueueNode));
	cur->_data = x;
	cur->_next = NULL;
	if (QueueIsEmpty(plist))//当队列为空时
	{
		plist->head = plist->rear = cur;
	}
	else
	{
		plist->rear->_next = cur;
		plist->rear = cur;
	}
}
QUTypeData QueueTop(Queue*plist)
{
	assert(plist != NULL);
	if (QueueIsEmpty(plist))
	{
		return NULL;
	}
	else
	{
		return plist->head->_data;
	}
}

bool QueueIsEmpty(Queue*plist)
{
	assert(plist!= NULL);
	return plist->head == NULL;
}