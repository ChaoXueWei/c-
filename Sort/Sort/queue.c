#include"queue.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
void QueueInit(Queue*Qu)
{
	assert(Qu != NULL);
	Qu->_head = NULL;
	Qu->_rear = NULL;
}
void QueueDestory(Queue*Qu)
{
	QueueNode*tmp;
	while (Qu->_head)
	{
		tmp = Qu->_head;
		Qu->_head = Qu->_head->_next;
		free(tmp);
		tmp = NULL;
	}
}
bool QueueIsEmpty(Queue*Qu)
{
	assert(Qu != NULL);
	if (Qu->_head== NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void QueuePush(Queue*Qu,QUDataType x)
{
	//QueueNode*cur = (QueueNode*)malloc(sizeof(QueueNode*));
	QueueNode*cur = (QueueNode*)malloc(sizeof(QueueNode));
	cur->_data = x;
	cur->_next = NULL;
	if (QueueIsEmpty(Qu))
	{
		Qu->_head=Qu->_rear = cur;
	}
	else
	{
		Qu->_rear->_next = cur;
		Qu->_rear = cur;
	}
}
void QueuePop(Queue*Qu)
{
	assert(Qu!=NULL);
	QueueNode*tmp;
	if (Qu->_head)
	{
		tmp = Qu->_head;
		Qu->_head = Qu->_head->_next;
		free(tmp);
	}
}
QUDataType QueueTop(Queue*Qu)
{
	assert(Qu != NULL);
	if (QueueIsEmpty(Qu))
	{
		return (QUDataType)0;
	}
	return Qu->_head->_data;
}